#include "bloodgroupmodel.h"

BloodGroupModel::BloodGroupModel()
{

}


BloodGroupModel::BloodGroupModel(QObject *parent,QSqlDatabase db) {
    setTable("blod_group");

    this->setEditStrategy(QSqlTableModel::OnFieldChange);
    this->setHeaderData(0, Qt::Horizontal,"ID");
    this->setHeaderData(1, Qt::Horizontal,"Blood group");
}
