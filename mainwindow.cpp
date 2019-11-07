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


//        this->listModels = {
//            new EducationLevelModel(this, this->db),
//            new EmployeeModel(this, this->db),
//            new JobTypeModel(this, this->db),
//            new JobsModel(this, this->db),
//            new DepartmentModel(this, this->db),
//            new FacultyModel(this, this->db),
//            new BloodGroupModel(this, this->db),
//            new PersonModel(this, this->db)
//        };

        this->modelsMap->insert("Edication level", new EducationLevelModel(this, this->db));
        this->modelsMap->insert("Employee", new EmployeeModel(this, this->db));
        this->modelsMap->insert("Job Type", new JobTypeModel(this, this->db));
        this->modelsMap->insert("Jobs", new JobsModel(this, this->db));
        this->modelsMap->insert("Department", new DepartmentModel(this, this->db));
        this->modelsMap->insert("Faculty", new FacultyModel(this, this->db));
        this->modelsMap->insert("Blood Group", new BloodGroupModel(this, this->db));
        this->modelsMap->insert("Person", new PersonModel(this, this->db));
        this->selectedStr = "Edication level";

        ui->tableChanger->addItems(*this->getTableName());

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
    QSqlRelationalTableModel *model = this->modelsMap->value(this->selectedStr);

    AddDialog *dialog = new AddDialog(this);
    dialog->setModal(true);
    dialog->setModel(model);

    if (dialog->exec()) {
        qDebug() << "adding data";
        QList<QPair<QString, QString> >* values = dialog->getValues();

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
    QSqlRelationalTableModel *model = this->modelsMap->value(this->selectedStr);

    QList<int> rows;
    foreach( const QModelIndex & index, selection.indexes() ) {
        rows.append( index.row() );
    }

    int prev = -1;
    for(int i = rows.count() - 1; i >= 0; i -= 1) {
        int current = rows[i];
        if( current != prev ) {
            model->removeRow(current);
            prev = current;
        }
    }

    model->select();
}

void MainWindow::on_tableChanger_currentIndexChanged(int selected)
{
    //    this->selected = selected;
    //    this->updateModel();
}

void MainWindow::showError(QString message) {
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.exec();
}

QStringList* MainWindow::getTableName()
{
    QStringList* result = new QStringList();

    for (auto item: this->modelsMap->toStdMap()) {
        result->push_back(item.first);
    }

    return result;
}

void MainWindow::updateModel() {
    QSqlRelationalTableModel *model = this->modelsMap->value(this->selectedStr);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->resizeColumnsToContents();


    model->record().count();
}

void MainWindow::on_tableChanger_currentIndexChanged(const QString &selected)
{
    this->selectedStr = selected;
    this->updateModel();
}
