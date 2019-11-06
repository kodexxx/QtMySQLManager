#include "employee_model.h"

employee_model::employee_model()
{

}


employee_model::employee_model(QObject *parent,QSqlDatabase db) {
    this->setTable("employee");

    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Job");
    this->setHeaderData(2, Qt::Horizontal,"Job Type");
    this->setHeaderData(3, Qt::Horizontal,"Department");
    this->setHeaderData(4, Qt::Horizontal,"Person");

    this->setRelation(1, QSqlRelation("jobs", "jobs_id", "job"));
    this->setRelation(2, QSqlRelation("job_type", "job_type_id", "job_type"));
    this->setRelation(3, QSqlRelation("department", "department_id", "name_short"));
    this->setRelation(4, QSqlRelation("person", "person_id", "name"));
}
