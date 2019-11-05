#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

void AddDialog::setModel(QSqlRelationalTableModel* model)
{
    this->model = model;
    int count = this->model->record().count();


    ui->fieldsList->clear();

    for (int i = 0; i < count; i++) {
        ui->fieldsList->addItem(this->model->record().fieldName(i));
    }
}


AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_fieldsList_currentRowChanged(int currentRow)
{

}
