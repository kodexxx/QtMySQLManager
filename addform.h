#ifndef ADDFORM_H
#define ADDFORM_H

#include <qsqlrelationaltablemodel.h>


class AddForm
{
public:
    AddForm();
    AddForm(QSqlRelationalTableModel *model);

private:
    QSqlRelationalTableModel *model;

};

#endif // ADDFORM_H
