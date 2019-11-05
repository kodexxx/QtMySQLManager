#ifndef EDUCATION_LEVEL_MODEL_H
#define EDUCATION_LEVEL_MODEL_H

#include <QSqlRelationalTableModel>


class EducationLevelModel : public QSqlRelationalTableModel {
public:
    EducationLevelModel();

    EducationLevelModel(QObject *parent,QSqlDatabase db);

    bool insertRowIntoTable(QSqlRecord &values);
};

#endif // EDUCATION_LEVEL_MODEL_H
