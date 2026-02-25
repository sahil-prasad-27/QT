#ifndef DBWORKER_H
#define DBWORKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QThread>

class DbWorker : public QObject
{
    Q_OBJECT
public:
    explicit DbWorker(QObject *parent = nullptr) : QObject(parent) {}

    void setDbFile(const QString &path) { dbFile = path; }

public slots:
    void updateUsers() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", QString("workerConnection_%1").arg((quintptr)QThread::currentThreadId()));
        db.setDatabaseName(dbFile);

        if (!db.open()) {
            qDebug() << "Worker DB open error:" << db.lastError().text();
            emit finished();
            return;
        }

        QSqlQuery query(db);
        if (!query.exec("UPDATE users SET age = age")) {
            qDebug() << "Worker update error:" << query.lastError().text();
        } else {
            qDebug() << "Worker: users updated successfully";
        }

        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());

        emit finished();
    }

signals:
    void finished();

private:
    QString dbFile;
};

#endif // DBWORKER_H
