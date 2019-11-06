#include "facultymodel.h"

FacultyModel::FacultyModel()
{

}

FacultyModel::FacultyModel(QObject *parent,QSqlDatabase db) {
    setTable("faculty");
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Name short");
    this->setHeaderData(2, Qt::Horizontal,"Name long");
}
