#ifndef EMPLOYEE_MODEL_H
#define EMPLOYEE_MODEL_H

#include <QSqlRelationalTableModel>



class EmployeeModel  : public QSqlRelationalTableModel
{
public:
    EmployeeModel();
    EmployeeModel(QObject *parent,QSqlDatabase db);
};

#endif // EMPLOYEE_MODEL_H
