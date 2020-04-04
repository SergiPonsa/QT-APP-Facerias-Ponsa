#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NewPlan_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_SetPlan_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidget_NewTask->addItem("plan_1");
}

void MainWindow::on_listWidget_NewTask_itemSelectionChanged()
{
    ui->stackedWidget->setCurrentIndex(2);
    QListWidgetItem* itemSelect = ui->listWidget_NewTask->currentItem();
}

void MainWindow::on_Edit_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Delete_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_TaskManager_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Back2Plan_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_BACKTASK_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
