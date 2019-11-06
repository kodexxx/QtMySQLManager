#include "education_level_model.h"


EducationLevelModel::EducationLevelModel() {

}

EducationLevelModel::EducationLevelModel(QObject *parent, QSqlDatabase db) {
    this->setTable("education_level");

    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Level");
    this->setHeaderData(2, Qt::Horizontal,"Level short");
}
