#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QtSql>

struct RelantionalValue {
    QString display;
    int key;
};

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    void setModel(QSqlRelationalTableModel* model);
    ~AddDialog();

    QList<QPair<QString, QString> >* getValues();

private:
    Ui::AddDialog *ui;
    QSqlRelationalTableModel *model;
    QList<RelantionalValue>* getList(QSqlTableModel* model, QSqlRelation relation);
    QStandardItemModel *getComboboxModel(QList<RelantionalValue> *qsl);
    QList<QPair<QVariant, QString> > *widgetList = new QList<QPair<QVariant, QString> >();
};

#endif // ADDDIALOG_H
