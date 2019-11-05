#include "education_level_model.h"
#include "employee_model.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>

const QStringList TABLES = {"Edication level", "Employee"};

const QList<QSqlRelationalTableModel> p = {};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << typeid (EducationLevelModel).name();

    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName("127.0.0.1");
    this->db.setDatabaseName("kodex");
    this->db.setUserName("user");
    this->db.setPassword("password");
    bool ok = db.open();




    if (ok) {
        ui->statusbar->showMessage("Connection to DB is ready");


        this->listModels = {new EducationLevelModel(this, this->db), new employee_model(this, this->db)};
         ui->tableChanger->addItems(TABLES);

         this->updateModel();


        ui->tableView->verticalHeader()->setVisible(false);


    } else {
        ui->statusbar->showMessage("Failed connect to db: " + this->db.lastError().text());
    }

    //    ui->tableChanger->

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->listModels.at(this->selected)->insertRow(this->listModels.at(this->selected)->rowCount());
}

void MainWindow::on_deleteButton_clicked()
{
    QItemSelection selection( ui->tableView->selectionModel()->selection() );

    QList<int> rows;
    foreach( const QModelIndex & index, selection.indexes() ) {
       rows.append( index.row() );
    }

    int prev = -1;
    for(int i = rows.count() - 1; i >= 0; i -= 1) {
       int current = rows[i];
       if( current != prev ) {
          this->educationLevelModel->removeRow(current);
          prev = current;
       }
    }
}

void MainWindow::on_tableChanger_currentIndexChanged(int selected)
{
    this->selected = selected;
    this->updateModel();
}


void MainWindow::updateModel() {
    this->listModels.at(this->selected)->select();
    ui->tableView->setModel(this->listModels.at(this->selected));
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->resizeColumnsToContents();
}
