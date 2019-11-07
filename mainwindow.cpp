#include "adddialog.h"
#include "bloodgroupmodel.h"
#include "departmentmodel.h"
#include "educationlevelmodel.h"
#include "employeemodel.h"
#include "facultymodel.h"
#include "jobsmodel.h"
#include "jobtypemodel.h"
#include "mainwindow.h"
#include "personmodel.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>

const QStringList TABLES = {"Edication level",
                            "Employee",
                            "Job Type",
                            "Jobs",
                            "Department",
                            "Faculty",
                            "Blood Group",
                            "Person"};

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


        this->listModels = {
            new EducationLevelModel(this, this->db),
            new EmployeeModel(this, this->db),
            new JobTypeModel(this, this->db),
            new JobsModel(this, this->db),
            new DepartmentModel(this, this->db),
            new FacultyModel(this, this->db),
            new BloodGroupModel(this, this->db),
            new PersonModel(this, this->db)
        };
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
    QSqlRelationalTableModel *model = this->listModels.at(this->selected);

    AddDialog *dialog = new AddDialog(this);
    dialog->setModal(true);
    dialog->setModel(model);

    if (dialog->exec()) {
        qDebug() << "adding data";
        QList<QPair<QString, QString> >* values = dialog->getValues();

        QSqlRelationalTableModel *model = this->listModels.at(this->selected);
        QSqlRecord record = model->record();

        for (auto item : *values) {
            record.setValue(item.first, item.second);
        }

        if (model->insertRecord(-1, record) ) {
            model->submitAll();
            model->select();
            ui->tableView->resizeColumnsToContents();
        } else {
            this->showError(model->lastError().text());
        }
    }
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
            this->listModels.at(this->selected)->removeRow(current);
            prev = current;
        }
    }

    this->listModels.at(this->selected)->select();
}

void MainWindow::on_tableChanger_currentIndexChanged(int selected)
{
    this->selected = selected;
    this->updateModel();
}

void MainWindow::showError(QString message) {
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.exec();
}

void MainWindow::updateModel() {
    this->listModels.at(this->selected)->select();
    ui->tableView->setModel(this->listModels.at(this->selected));
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->resizeColumnsToContents();

    QSqlRelationalTableModel *model = this->listModels.at(this->selected);

    model->record().count();
}
