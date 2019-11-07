#ifndef JOBTYPEMODEL_H
#define JOBTYPEMODEL_H

#include <QSqlRelationalTableModel>



class JobTypeModel : public QSqlRelationalTableModel
{
public:
    JobTypeModel();
    JobTypeModel(QObject *parent,QSqlDatabase db);
};

#endif // JOBTYPEMODEL_H
