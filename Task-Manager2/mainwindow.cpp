#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimeCallback()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimeCallback()
{
    qDebug() << "update";
}


void Plan::saveData(Plan plan)
{
    std::ofstream file_(std::to_string(plan.id) + ".txt");
    file_.open(std::to_string(plan.id) + ".txt");

    if (file_.is_open()){

        file_ << plan.name + "\n";
        file_ << plan.description + "\n";
        file_ << std::to_string(plan.repeat) + "\n";
        file_ << std::to_string(plan.periodicity) + "\n";
        file_ << plan.date_day.toString().toStdString() + "\n";

        file_ << "task_status + \n";
        for (unsigned int i=0;i < plan.task_completed.size();i++){

            file_ << std::to_string(plan.task_completed[i]) + "\n";

        }

        file_ << "task_name + \n";
        for (unsigned int i=0;i < plan.task_name.size();i++){

            file_ << plan.task_name[i] + "\n";

        }

        file_ << std::to_string(plan.enabled) + "\n";
        file_ << std::to_string(plan.check_alarm) + "\n";

    }

}



void Plan::readData(std::string filename, Plan plan)
{
    std::ifstream file_(filename);
    std::string line;
    int i = 0;



    if (file_.is_open()){

        while(getline(file_,line)){

            for (unsigned int j=0; j<line.size(); j++){

                if (&line[j] == ":"){

                    switch (i) {

                    case 1:{

                        std::stringstream parser(line.substr(j+1,line.size()-1));
                        parser >> plan.id;
                        break;
                    }

                    case 2:{

                        plan.name = line.substr(j+1,line.size()-1);
                        break;
                    }

                    case 3:{
                         plan.description = line.substr(j+1,line.size()-1);
                         break;
                    }

                    case 4:{

                        std::stringstream parser(line.substr(j+1,line.size()-1));
                        parser >> plan.repeat;
                        break;
                    }

                    case 5:{

                        std::stringstream parser(line.substr(j+1,line.size()-1));
                        parser >> plan.periodicity;
                        break;

                    }

                    case 6:{

                        plan.date_day = line.substr(j+1,line.size()-1);
                        break;

                    }


                    }
                    break;
                }
            }

        i ++;
        }

        file_.close();
    }

}
