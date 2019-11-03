#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "education_level_model.h"

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

private:
    Ui::MainWindow *ui;

    EducationLevelModel* educationLevelModel;
};
#endif // MAINWINDOW_H
