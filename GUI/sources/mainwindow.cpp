#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_actionNATURAL_triggered()
// {

// }


// void MainWindow::on_actionPOLYNOMIAL_triggered()
// {

// }


// void MainWindow::on_actionRATIONAL_triggered()
// {

// }


// void MainWindow::on_actionINTEGER_triggered()
// {

// }


void MainWindow::on_tabWidget_tabBarClicked(int index)
{

}


