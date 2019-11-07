#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "educationlevelmodel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_deleteButton_clicked();

    void on_tableChanger_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString selectedStr = "";
    QSqlDatabase db;

    QMap<QString, QSqlRelationalTableModel*>* modelsMap = new QMap<QString, QSqlRelationalTableModel*>();

    void updateModel();
    void showError(QString message);

    QStringList getTableName();

};
#endif // MAINWINDOW_H
