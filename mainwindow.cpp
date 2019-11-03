#include "education_level_model.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("kodex");
    db.setUserName("user");
    db.setPassword("password");
    bool ok = db.open();


    if (ok) {
        ui->dbConnectStatus->setText("Connected successfully!");

        this->educationLevelModel = new EducationLevelModel(this, db);

        this->educationLevelModel->select();

        ui->tableView->setModel(this->educationLevelModel);
        ui->tableView->resizeColumnsToContents();


    } else {      
        ui->dbConnectStatus->setText(db.lastError().text());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->educationLevelModel->insertRow(this->educationLevelModel->rowCount());
}

void MainWindow::on_deleteButton_clicked()
{

}
