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

    void on_tableChanger_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    EducationLevelModel* educationLevelModel;
    QList<QSqlRelationalTableModel*> listModels;
    int selected = 0;
    QSqlDatabase db;

    void updateModel();
    void showError(QString message);
};
#endif // MAINWINDOW_H
