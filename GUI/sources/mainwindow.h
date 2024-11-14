#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include "../../headers/IntegerNumber.h"
#include "../../headers/NaturalNumber.h"
#include "../../headers/RationalNumber.h"
#include "../../headers/Polynomial.h"
#include "../../headers/Struct.h"
#include "../../headers/Overload.h"
#include <fstream>
#include <QFileDialog>

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

    void on_pushButton_15_clicked();

    void on_COM_NN_D_BUTTON_clicked();

    void on_NZER_N_B_BUTTON_clicked();

    void on_ADD_1N_N_BUTTON_clicked();

    void on_ADD_NN_N_BUTTON_clicked();

    void on_SUB_NN_N_BUTTON_clicked();

    void on_MOD_NN_N_BUTTON_clicked();

    void on_DIV_NN_N_BUTTON_clicked();

    void on_GCF_NN_N_BUTTON_clicked();

    void on_LCM_NN_N_BUTTON_clicked();

    void on_DIV_NN_Dk_BUTTON_clicked();

    void on_SUB_NDN_N_BUTTON_clicked();

    void on_MUL_ND_N_BUTTON_clicked();

    void on_MUL_Nk_N_BUTTON_clicked();

    void on_MUL_NN_N_BUTTON_clicked();

    void on_actionOpen_Input_File_triggered();

    void on_actionChoose_Output_File_triggered();

    void write_natural_result(NaturalNumber a);

    void write_integer_result(IntegerNumber a);

    void write_integer_result(NaturalNumber a);

    void write_rational_result(RationalNumber a);

    void write_polynomial_result(Polynomial a);

    void on_actionOpen_Input2_File_triggered();

    void on_pushButton_16_clicked();

    void on_MUL_ZZ_Z_BUTTON_clicked();

    void on_ADD_ZZ_Z_BUTTON_clicked();

    void on_SUB_ZZ_Z_BUTTON_clicked();

    void on_ABS_Z_N_BUTTON_clicked();

    void on_TRANS_N_Z_BUTTON_clicked();

    void on_TRANS_Z_N_BUTTON_clicked();

    void on_POZ_Z_D_BUTTON_clicked();

    void on_MUL_ZM_Z_BUTTON_clicked();

    void on_DIV_ZZ_Z_BUTTON_clicked();

    void on_MOD_ZZ_Z_BUTTON_clicked();


private:
    Ui::MainWindow *ui;
    int NaturalChose = 0, IntegerChose = 0;
    std::string output_file_name_ = "./output.txt";
    std::string input_file_name_ = "./input.txt";
    std::string input2_file_name_ = "./input2.txt";
    bool input_ = false, output_ = false, input_2_ = false;
};

#endif // MAINWINDOW_H
