#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_NewPlan_Button_clicked();

    void on_SetPlan_Button_clicked();

    void on_listWidget_NewTask_itemSelectionChanged();

    void on_Edit_Button_clicked();

    void on_Delete_Button_clicked();

    void on_TaskManager_Button_clicked();

    void on_Back2Plan_Button_clicked();

    void on_BACKTASK_Button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
