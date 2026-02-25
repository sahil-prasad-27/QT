#include "workerthread.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrl>

WorkerThread::WorkerThread(QObject *parent)
    : QThread(parent),
      manager(nullptr),
      timer(nullptr),
      paused(false),
      stopped(false)
{
    apiKey = "your api key";
    city = "Delhi";
}

WorkerThread::~WorkerThread()
{
    quit();
    wait();
}

void WorkerThread::run()
{
    manager = new QNetworkAccessManager();
    timer   = new QTimer();

    connect(timer, &QTimer::timeout,
            this, &WorkerThread::fetchData);

    timer->start(5000);

    exec();

    delete timer;
    delete manager;
}

void WorkerThread::fetchData()
{
    if (paused || stopped)
        return;

    emit fetchingStarted();

    QString urlStr =
        QString("http://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
            .arg(city)
            .arg(apiKey);

    QNetworkRequest request{ QUrl(urlStr) };
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        if (reply->error() != QNetworkReply::NoError)
        {
            emit dataReady("Error fetching data", QPixmap());
            emit fetchingFinished();
            reply->deleteLater();
            return;
        }

        QByteArray data = reply->readAll();
        reply->deleteLater();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isObject())
        {
            emit dataReady("Invalid JSON", QPixmap());
            emit fetchingFinished();
            return;
        }

        QJsonObject obj = doc.object();

        if (!obj.contains("main") ||
            !obj.contains("weather") ||
            !obj["weather"].isArray())
        {
            emit dataReady("Invalid format", QPixmap());
            emit fetchingFinished();
            return;
        }

        double temp = obj["main"].toObject()["temp"].toDouble();

        QString text = QString("Temperature in %1: %2 °C")
                           .arg(city)
                           .arg(temp);

        QJsonArray weatherArray = obj["weather"].toArray();

        if (weatherArray.isEmpty())
        {
            emit dataReady(text, QPixmap());
            emit fetchingFinished();
            return;
        }

        QString iconCode =
            weatherArray.at(0).toObject()["icon"].toString();

        QString iconUrl =
            QString("http://openweathermap.org/img/wn/%1@2x.png")
                .arg(iconCode);

        QNetworkRequest iconRequest{ QUrl(iconUrl) };
        QNetworkReply *iconReply = manager->get(iconRequest);

        connect(iconReply, &QNetworkReply::finished, this, [=]()
        {
            QPixmap icon;
            icon.loadFromData(iconReply->readAll());

            emit dataReady(text, icon);
            emit fetchingFinished();

            iconReply->deleteLater();
        });
    });
}

void WorkerThread::pause()
{
    paused = true;
}

void WorkerThread::resume()
{
    paused = false;
}

void WorkerThread::stop()
{
    stopped = true;
    QMetaObject::invokeMethod(this, "quit", Qt::QueuedConnection);
}
