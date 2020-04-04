#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Qtimer>
#include <QTime>
#include <QMainWindow>
#include <fstream>
#include <cstring>
#include <sstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void TimeCallback();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H

class Plan{

public:

    int id = 0;
    std::string name;
    std::string description;
    bool repeat;
    int periodicity;
    QTime date_day;
    std::array<std::string,1> task_name;
    std::array<bool,1> task_completed;
    bool enabled;
    bool check_alarm;

    void saveData(Plan plan);
    void readData(std::string filename, Plan plan);

};
