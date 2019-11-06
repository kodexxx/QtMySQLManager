#include "personmodel.h"

PersonModel::PersonModel()
{

}


PersonModel::PersonModel(QObject *parent,QSqlDatabase db) {
    setTable("person");
    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"First name");
    this->setHeaderData(2, Qt::Horizontal,"Name");
    this->setHeaderData(3, Qt::Horizontal,"Third name");
    this->setHeaderData(4, Qt::Horizontal,"Date of born");
    this->setHeaderData(5, Qt::Horizontal,"Blood group");

    this->setRelation(5, QSqlRelation("blod_group", "blod_group_id", "blod_group"));

}
