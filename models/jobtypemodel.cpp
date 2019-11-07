#include "jobtypemodel.h"



JobTypeModel::JobTypeModel()
{

}

JobTypeModel::JobTypeModel(QObject *parent, QSqlDatabase db)
{
    this->setTable("job_type");
    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Job Type");
}
