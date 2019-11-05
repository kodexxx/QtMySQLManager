#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QtSql>

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

private slots:
    void on_fieldsList_currentRowChanged(int currentRow);

private:
    Ui::AddDialog *ui;
    QSqlRelationalTableModel *model;
};

#endif // ADDDIALOG_H
