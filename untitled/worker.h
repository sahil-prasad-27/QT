#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void progress(int value);
    void finished();

public slots:
    void doWork() {
        for (int i = 1; i <= 10; ++i) {
            QThread::msleep(100);
            emit progress(i);
        }
        emit finished();
    }
};

#endif // WORKER_H
