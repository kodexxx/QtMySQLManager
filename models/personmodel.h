#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QSqlRelationalTableModel>



class PersonModel : public QSqlRelationalTableModel
{
public:
    PersonModel();
    PersonModel(QObject *parent,QSqlDatabase db);
};

#endif // PERSONMODEL_H
