#ifndef BLOODGROUPMODEL_H
#define BLOODGROUPMODEL_H

#include <QSqlRelationalTableModel>



class BloodGroupModel : public QSqlRelationalTableModel
{
public:
    BloodGroupModel();
    BloodGroupModel(QObject *parent,QSqlDatabase db);
};

#endif // BLOODGROUPMODEL_H
