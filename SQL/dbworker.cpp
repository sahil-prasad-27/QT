#include "dbworker.h"

void DbWorker::updateUsers() {
    // Each thread needs its own DB connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", QString("workerConnection_%1").arg((quintptr)QThread::currentThreadId()));
    db.setDatabaseName(dbFile);

    if (!db.open()) {
        qDebug() << "Worker DB open error:" << db.lastError().text();
        emit finished();
        return;
    }

    QSqlQuery query(db);

    // Example: increment age of all users
    if (!query.exec("UPDATE users SET age = age + 1")) {
        qDebug() << "Worker update error:" << query.lastError().text();
    } else {
        qDebug() << "Worker: users updated successfully";
    }

    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());

    emit finished();
}
