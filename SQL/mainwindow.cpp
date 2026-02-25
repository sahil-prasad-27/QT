#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectToDatabase();
    createTable();
    readUsers();

    model = new QSqlTableModel(this, db);
    model->setTable("users");
    model->select();
    ui->tableViewUsers->setModel(model);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "mainConnection");
    db.setDatabaseName(QDir::currentPath() + "/mydatabase.db");
    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
    } else {
        qDebug() << "Database connected";
    }
}

void MainWindow::createTable()
{
    QSqlQuery query(db);
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            age INTEGER
        )
    )";
    if (!query.exec(createTable)) {
        qDebug() << "Table creation error:" << query.lastError().text();
    } else {
        qDebug() << "Table ready";
    }
}

void MainWindow::insertUser(const QString &name, int age)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (name, age) VALUES (:name, :age)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
    } else {
        qDebug() << "User inserted";
    }
}

void MainWindow::readUsers()
{
    QSqlQuery query(db);
    if (!query.exec("SELECT id, name, age FROM users")) {
        qDebug() << "Read error:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << id << name << age;
    }
}

void MainWindow::on_pushButtonAdd_clicked()
{
    QString name = ui->lineEditName->text();
    int age = ui->lineEditAge->text().toInt();

    if (!name.isEmpty()) {
        insertUser(name, age);
        model->select();  // refresh view
    }

    ui->lineEditName->clear();
    ui->lineEditAge->clear();
}

// This is the button to trigger threaded updates
void MainWindow::on_pushButtonUpdate_clicked()
{
    runWorkerThread();
}

void MainWindow::runWorkerThread()
{
    QThread* thread = new QThread;
    DbWorker* worker = new DbWorker;
    worker->setDbFile(QDir::currentPath() + "/mydatabase.db");

    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &DbWorker::updateUsers);
    connect(worker, &DbWorker::finished, thread, &QThread::quit);
    connect(worker, &DbWorker::finished, worker, &DbWorker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // Refresh UI after worker finishes
    connect(worker, &DbWorker::finished, this, [=]() {
        model->select();
        qDebug() << "Users updated in background thread";
    });

    thread->start();
}
