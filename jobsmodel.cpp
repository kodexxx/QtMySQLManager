#include "jobsmodel.h"

JobsModel::JobsModel()
{

}

JobsModel::JobsModel(QObject *parent,QSqlDatabase db) {
    this->setTable("jobs");
    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Job");
}
