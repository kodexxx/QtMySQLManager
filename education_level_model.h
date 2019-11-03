#ifndef EDUCATION_LEVEL_MODEL_H
#define EDUCATION_LEVEL_MODEL_H

#include <QSqlRelationalTableModel>


class EducationLevelModel : public QSqlRelationalTableModel {
public:
    EducationLevelModel() {

    }

    EducationLevelModel(QObject *parent,QSqlDatabase db) {
        this->setTable("education_level");

        this->setEditStrategy(QSqlTableModel::OnFieldChange);
        this->setHeaderData(0, Qt::Horizontal,"ID");
        this->setHeaderData(1, Qt::Horizontal,"Level");
        this->setHeaderData(2, Qt::Horizontal,"Level short");
    }
};

#endif // EDUCATION_LEVEL_MODEL_H
