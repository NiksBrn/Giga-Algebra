#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../headers/IntegerNumber.h"
#include "../../headers/NaturalNumber.h"
#include "../../headers/RationalNumber.h"
#include "../../headers/Polynomial.h"
#include "../../headers/Struct.h"
#include "../../headers/Overload.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void on_actionNATURAL_triggered();

    // void on_actionPOLYNOMIAL_triggered();

    // void on_actionRATIONAL_triggered();

    // void on_actionINTEGER_triggered();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
