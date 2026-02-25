#include "LiveImageWidget.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPixmap>
#include <QUrl>
#include <QTimer>
#include <iostream>

LiveImageWidget::LiveImageWidget(QWidget* parent)
    : QWidget(parent), lblTitle(nullptr), lblImage(nullptr),
      loadingLabel(nullptr), loadingGif(nullptr), thread(nullptr)
{
    mainLayout = new QVBoxLayout(this);

    lblTitle = new QLabel("Title: --", this);
    lblTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(lblTitle);

    lblImage = new QLabel(this);
    lblImage->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(lblImage);

    loadingLabel = new QLabel(this);
    loadingGif = new QMovie(":/loading.gif");
    loadingLabel->setMovie(loadingGif);
    loadingGif->start();
    mainLayout->addWidget(loadingLabel);

    buttonLayout = new QHBoxLayout;
    startBtn = new QPushButton("Start", this);
    pauseBtn = new QPushButton("Pause", this);
    resumeBtn = new QPushButton("Resume", this);
    buttonLayout->addWidget(startBtn);
    buttonLayout->addWidget(pauseBtn);
    buttonLayout->addWidget(resumeBtn);
    mainLayout->addLayout(buttonLayout);

    // Thread
    thread = new LiveImageThread();
    connect(thread, &LiveImageThread::imageUpdated, this, [=](const QPixmap& pixmap, const QString& title){
        lblTitle->setText("Title: " + title);
        lblImage->setPixmap(pixmap.scaled(400,400,Qt::KeepAspectRatio));
    });

    connect(startBtn, &QPushButton::clicked, thread, &LiveImageThread::startThread);
    connect(pauseBtn, &QPushButton::clicked, thread, &LiveImageThread::pauseThread);
    connect(resumeBtn, &QPushButton::clicked, thread, &LiveImageThread::resumeThread);
}

LiveImageWidget::~LiveImageWidget()
{
    if(thread) {
        thread->stopThread();
        delete thread;
    }
    if(loadingGif) delete loadingGif;
}

// ------------------ LiveImageThread ------------------

LiveImageWidget::LiveImageThread::LiveImageThread()
    : runFlag(false), terminateFlag(false)
{}

LiveImageWidget::LiveImageThread::~LiveImageThread()
{
    stopThread();
}

void LiveImageWidget::LiveImageThread::run()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager();

    while(!terminateFlag.load()) {

        // Pause mechanism
        {
            std::unique_lock<std::mutex> lock(cvMutex);
            cv.wait(lock, [this]{ return runFlag.load() || terminateFlag.load(); });
        }
        if(terminateFlag.load()) break;

        // Fetch JSON from NASA API
        QNetworkRequest request(QUrl("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY"));
        QNetworkReply* reply = manager->get(request); // Qt5-safe: named variable

        QObject::connect(reply, &QNetworkReply::finished, [this, reply, manager]() {

            if(reply->error() == QNetworkReply::NoError) {
                QByteArray resp = reply->readAll();
                QJsonDocument doc = QJsonDocument::fromJson(resp);
                QJsonObject obj = doc.object();
                QString title = obj["title"].toString();
                QString imageUrl = obj["url"].toString();

                // Fetch image
                QNetworkRequest imgReq(QUrl(imageUrl)); // Qt5-safe
                QNetworkReply* imgReply = manager->get(imgReq);

                QObject::connect(imgReply, &QNetworkReply::finished, [this, imgReply, title]() {
                    if(imgReply->error() == QNetworkReply::NoError){
                        QByteArray imgData = imgReply->readAll();
                        QPixmap pixmap;
                        pixmap.loadFromData(imgData);
                        emit imageUpdated(pixmap, title);
                    }
                    imgReply->deleteLater();
                });
            }
            reply->deleteLater();
        });

        // Sleep 10 seconds
        for(int i = 0; i < 100; ++i){
            if(terminateFlag.load()) break;
            QThread::msleep(100);
        }
    }

    delete manager;
}

// Control methods
void LiveImageWidget::LiveImageThread::startThread()
{
    runFlag.store(true);
    cv.notify_one();
    if(!isRunning()) start();
}

void LiveImageWidget::LiveImageThread::pauseThread()
{
    runFlag.store(false);
}

void LiveImageWidget::LiveImageThread::resumeThread()
{
    runFlag.store(true);
    cv.notify_one();
}

void LiveImageWidget::LiveImageThread::stopThread()
{
    terminateFlag.store(true);
    cv.notify_one();
    wait();
}
