#include "addform.h"

#include <qsqlrelationaltablemodel.h>

AddForm::AddForm(QSqlRelationalTableModel * model) {
    this->model = model;
}
