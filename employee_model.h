#ifndef EMPLOYEE_MODEL_H
#define EMPLOYEE_MODEL_H

#include <QSqlRelationalTableModel>



class employee_model  : public QSqlRelationalTableModel
{
public:
    employee_model();
    employee_model(QObject *parent,QSqlDatabase db);
};

#endif // EMPLOYEE_MODEL_H
