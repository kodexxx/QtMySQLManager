#ifndef FACULTYMODEL_H
#define FACULTYMODEL_H

#include <QSqlRelationalTableModel>



class FacultyModel: public QSqlRelationalTableModel
{
public:
    FacultyModel();
    FacultyModel(QObject *parent,QSqlDatabase db);
};

#endif // FACULTYMODEL_H
