#include "adddialog.h"
#include "ui_adddialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QVariant>

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
    ui->gridLayout->setAlignment(Qt::AlignTop);


    for (int i = 1; i < count; i++) {
        QLabel *label =  new QLabel();

        QString fieldName = this->model->record().fieldName(i);
        QString fieldTitle = this->model->headerData(i, Qt::Horizontal).toString();

        label->setText(fieldTitle);
        ui->gridLayout->addWidget(label, i, 0);

        QList<RelantionalValue>* rel = this->getList(this->model->relationModel(i), this->model->relation(i));

        if (rel != nullptr) {
            QComboBox *comboBox = new QComboBox();
            QStandardItemModel * model = this->getComboboxModel(rel);

            comboBox->setModel(model);

            ui->gridLayout->addWidget(comboBox, i, 1);
            this->widgetList->push_back(QPair<QVariant, QString>(QVariant::fromValue(comboBox), fieldName));
        } else {
            QLineEdit *field = new QLineEdit();
            ui->gridLayout->addWidget(field, i, 1);

            this->widgetList->push_back(QPair<QVariant, QString>(QVariant::fromValue(field), fieldName));
        }
    }
}

QStandardItemModel* AddDialog::getComboboxModel(QList<RelantionalValue>* qsl) {
    QStandardItemModel* model = new QStandardItemModel();

    for (auto item : *qsl) {
        QStandardItem *cmbItem = new QStandardItem();
        cmbItem->setData(item.display, Qt::DisplayRole);
        cmbItem->setData(item.key, Qt::UserRole);
        model->appendRow(cmbItem);
    }

    return model;
}


AddDialog::~AddDialog()
{
    delete ui;
}

QList<QPair<QString, QString> >* AddDialog::getValues() {
    QList<QPair<QString, QString> > *result = new QList<QPair<QString, QString> >();
    qDebug() << "getting values";

    for (auto item : *this->widgetList) {
        QString value;
        if (item.first.canConvert<QLineEdit*>()) {
            QLineEdit* input = item.first.value<QLineEdit*>();
            value = input->text();
        }

        if (item.first.canConvert<QComboBox*>()) {
            QComboBox* input = item.first.value<QComboBox*>();
            value = input->currentData(Qt::UserRole).toString();
        }

        if (value == nullptr) {
            continue;
        }

        result->push_back(QPair<QString, QString>(item.second, value));
    }

    return result;
}

QList<RelantionalValue>* AddDialog::getList(QSqlTableModel* model, QSqlRelation relation) {
    if (!relation.isValid()) {
        return nullptr;
    }

    QList<RelantionalValue>* result = new QList<RelantionalValue>();

    model->select();

    for (int i = 0; i < model->rowCount(); i++) {
        qDebug() << model->record(i).value(relation.displayColumn()).toString();

        result->push_back(RelantionalValue{
                              model->record(i).value(relation.displayColumn()).toString(),
                              model->record(i).value(relation.indexColumn()).toInt()
                          });
    }

    return result;
}
