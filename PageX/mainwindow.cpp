#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPushButton>
#include <QHeaderView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadJsonToTableView(":/sessions.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadJsonToTableView(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file:" << fileName;
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning() << "JSON is not an array!";
        return;
    }

    QJsonArray array = doc.array();

    // Create model with 10 columns
    QStandardItemModel* model = new QStandardItemModel(array.size(), 10, this);

    model->setHorizontalHeaderLabels({
        "Session Count", "Start Date", "End Date", "Start Time", "Stop Time",
        "Working Time", "Status", "Sorting Type", "View Detail Report", "Download"
    });

    // Fill model with JSON data
    int rowIndex = 0;
    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();

        model->setItem(rowIndex, 0, new QStandardItem(QString::number(obj["session_count"].toInt())));
        model->setItem(rowIndex, 1, new QStandardItem(obj["session_start_date"].toString()));
        model->setItem(rowIndex, 2, new QStandardItem(obj["session_end_date"].toString()));
        model->setItem(rowIndex, 3, new QStandardItem(obj["session_start_time"].toString()));
        model->setItem(rowIndex, 4, new QStandardItem(obj["session_stop_time"].toString()));
        model->setItem(rowIndex, 5, new QStandardItem(obj["session_working_time"].toString()));
        model->setItem(rowIndex, 6, new QStandardItem(obj["status"].toString()));
        model->setItem(rowIndex, 7, new QStandardItem(obj["sorting_type"].toString()));
        model->setItem(rowIndex, 8, new QStandardItem("")); // Placeholder for button
        model->setItem(rowIndex, 9, new QStandardItem(""));
        ++rowIndex;
    }

    ui->tableView->setModel(model);

    // =========================
    // Table appearance & behavior
    // =========================

    // Hide vertical header
    ui->tableView->verticalHeader()->setVisible(false);

    // Resize rows to fit content
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Stretch columns except buttons
    for (int i = 0; i < 8; ++i) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);

    // Remove grid lines
    ui->tableView->setShowGrid(false);

    // Make sure text wraps and is visible
    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideNone);

    // =========================
    // Add buttons
    // =========================

    rowIndex = 0;
    for (const QJsonValue &value : array) {
        int currentRow = rowIndex;

        // View Detail button
        QPushButton *viewBtn = new QPushButton("View Detail");
        viewBtn->setObjectName("viewDetailButton");
        viewBtn->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        viewBtn->setMinimumHeight(30);       // Ensure text is visible
        viewBtn->setMinimumWidth(100);       // Avoid shrinking too much
        connect(viewBtn, &QPushButton::clicked, this, [currentRow]() {
            qDebug() << "View Detail clicked at row:" << currentRow;

        });
        ui->tableView->setIndexWidget(model->index(rowIndex, 8), viewBtn);

        // Download button
        QPushButton *downloadBtn = new QPushButton("Download");
        downloadBtn->setObjectName("downloadButton");
        downloadBtn->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        downloadBtn->setMinimumHeight(30);
        downloadBtn->setMinimumWidth(100);
        connect(downloadBtn, &QPushButton::clicked, this, [currentRow,downloadBtn]() {
            qDebug() << "Download clicked at row:" << currentRow;
            qDebug() << "Detail clicked at row:" << downloadBtn->text();
        });
        ui->tableView->setIndexWidget(model->index(rowIndex, 9), downloadBtn);

        ++rowIndex;
    }

    // Optional: alternate row colors for readability
    ui->tableView->setAlternatingRowColors(true);
}
