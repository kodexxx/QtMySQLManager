#ifndef DEPARTMENTMODEL_H
#define DEPARTMENTMODEL_H

#include <QSqlRelationalTableModel>



class DepartmentModel : public QSqlRelationalTableModel
{
public:
    DepartmentModel();
    DepartmentModel(QObject *parent,QSqlDatabase db);
};

#endif // DEPARTMENTMODEL_H
