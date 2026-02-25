#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QPixmap>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = nullptr);
    ~WorkerThread();

    void run() override;

    void pause();
    void resume();
    void stop();

signals:
    void dataReady(const QString &text, const QPixmap &icon);
    void fetchingStarted();
    void fetchingFinished();

private slots:
    void fetchData();

private:
    QNetworkAccessManager *manager;
    QTimer *timer;

    bool paused;
    bool stopped;

    QString apiKey;
    QString city;
};

#endif
