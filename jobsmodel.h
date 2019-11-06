#ifndef JOBSMODEL_H
#define JOBSMODEL_H

#include <QSqlRelationalTableModel>



class JobsModel : public QSqlRelationalTableModel
{
public:
    JobsModel();
    JobsModel(QObject *parent,QSqlDatabase db);
};

#endif // JOBSMODEL_H
