#include "departmentmodel.h"

DepartmentModel::DepartmentModel()
{

}


DepartmentModel::DepartmentModel(QObject *parent,QSqlDatabase db) {
    setTable("department");
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Name short");
    this->setHeaderData(2, Qt::Horizontal,"Name");
    this->setHeaderData(3, Qt::Horizontal,"Faculty");

    this->setRelation(3, QSqlRelation("faculty", "faculty_id", "name_short"));
}
