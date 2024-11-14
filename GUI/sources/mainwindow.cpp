#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

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

void MainWindow::on_tabWidget_tabBarClicked(int index) {}

void MainWindow::on_pushButton_15_clicked() {
    NaturalNumber first, second;
  std::string s1, s2;
    if(input_ && input_2_){
      std::ifstream in1(input_file_name_);
      in1>>s1;
      std::ifstream in2(input2_file_name_);
      in2>>s2;
      first = NaturalNumber(s1);
      second = NaturalNumber(s2);
  } else if(input_){
        std::ifstream in(input_file_name_);
        in>>s1;
        first = NaturalNumber(s1);
        second = NaturalNumber(ui->NATURAL_INPUT2->toPlainText().toStdString());
  } else if(input_2_){
      std::ifstream in(input2_file_name_);
      in>>s2;
      first = NaturalNumber(ui->NATURAL_INPUT1->toPlainText().toStdString());
      second = NaturalNumber(s2);
  } else {
    first = NaturalNumber(ui->NATURAL_INPUT1->toPlainText().toStdString());
    second = NaturalNumber(ui->NATURAL_INPUT2->toPlainText().toStdString());
  }
  switch (NaturalChose) {
    case 1: {
        std::stringstream s;
        s<<CompareToString(first.COM_NN_D(second));
        ui->NATURAL_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 2: {
        std::stringstream s;
        s<<first.NZER_N_B();
        ui->NATURAL_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 3: {
        write_natural_result(first.ADD_1N_N());
        break;;
    }
    case 4: {
        write_natural_result(first.ADD_NN_N(second));
        break;
    }
    case 5: {
        write_natural_result(first.SUB_NN_N(second));
        break;
    }
    case 6: {
        write_natural_result(first.MUL_ND_N(ui->MUL_ND_N_D->value()));
        break;
    }
    case 7: {
        write_natural_result(first.MUL_Nk_N(std::stoi(ui->NATURAL_INPUT2->toPlainText().toStdString())));
        break;
    }
    case 8: {
        write_natural_result(first.MUL_NN_N(second));
        break;
    }
    case 9: {
        write_natural_result(first.SUB_NDN_N(second, ui->SUB_NDN_N_D->value()));
        break;
    }
    case 10: {
        write_natural_result(NaturalNumber(std::to_string((first.DIV_NN_Dk(second)).second)));
        break;
    }
    case 11: {
        write_natural_result(first.DIV_NN_N(second));
        break;
    }
    case 12: {
        write_natural_result(first.MOD_NN_N(second));
        break;
    }
    case 13: {
        write_natural_result(first.GCF_NN_N(second));
        break;
    }
    case 14: {
        write_natural_result(first.LCM_NN_N(second));
        break;
    }
    default: {
        break;
    }
  }
}

void MainWindow::on_pushButton_16_clicked()
{
    IntegerNumber first, second;
    std::string s1, s2;
    if(input_ && input_2_){
        std::ifstream in1(input_file_name_);
        in1>>s1;
        std::ifstream in2(input2_file_name_);
        in2>>s2;
        if(s1[0] == '-'){
            first = IntegerNumber('-', s1.substr(s1.find('-')+1));
        } else {
            first = IntegerNumber('+',s1);
        }
        if(s2[0] == '-'){
            second = IntegerNumber('-', s2.substr(s2.find('-')+1));
        } else {
            second = IntegerNumber('+',s2);
        }
    } else if(input_){
        std::ifstream in(input_file_name_);
        in>>s1;
        if(s1[0] == '-'){
            first = IntegerNumber('-', s1.substr(s1.find('-')+1));
        } else {
            first = IntegerNumber('+',s1);
        }
        s2 = ui->INTEGER_INPUT2->toPlainText().toStdString();
        if(s2[0] == '-'){
            second = IntegerNumber('-', s2.substr(s2.find('-')+1));
        } else {
            second = IntegerNumber('+',s2);
        }
    } else if(input_2_){
        s1 = ui->INTEGER_INPUT1->toPlainText().toStdString();
        if(s1[0] == '-'){
            first = IntegerNumber('-', s1.substr(s1.find('-')+1));
        } else {
            first = IntegerNumber('+',s1);
        }
        std::ifstream in(input2_file_name_);
        in>>s2;
        if(s2[0] == '-'){
            second = IntegerNumber('-', s2.substr(s2.find('-')+1));
        } else {
            second = IntegerNumber('+',s2);
        }
    } else {
        s1 = ui->INTEGER_INPUT1->toPlainText().toStdString();
        s2 = ui->INTEGER_INPUT2->toPlainText().toStdString();
        if(s1[0] == '-'){
            first = IntegerNumber('-', s1.substr(s1.find('-')+1));
        } else {
            first = IntegerNumber('+',s1);
        }
        if(s2[0] == '-'){
            second = IntegerNumber('-', s2.substr(s2.find('-')+1));
        } else {
            second = IntegerNumber('+',s2);
        }
    }
    switch (IntegerChose) {
    case 1: {
        write_integer_result(first.MUL_ZZ_Z(second));
        break;
    }
    case 2: {
        write_integer_result(first.ADD_ZZ_Z(second));
        break;
    }
    case 3: {
        write_integer_result(first.SUB_ZZ_Z(second));
        break;;
    }
    case 4: {
        write_integer_result(first.ABS_Z_Z());
        break;
    }
    case 5: {
        std::stringstream s;
        s<<first;
        std::string str = s.str();
        if(str[0] == '-'){
            ui->INTEGER_OUTPUT->setText("input number is not natural");
        }else {
        write_integer_result(second.TRANS_N_Z(NaturalNumber(str)));
        }
        break;
    }
    case 6: {
        std::stringstream s;
        s<<first;
        std::string str = s.str();
        if(str[0] == '-'){
            ui->INTEGER_OUTPUT->setText("input number can not be natural");
        }else {
        write_integer_result(first.TRANS_Z_N(first));
        }
        break;
    }
    case 7: {
        std::stringstream s;
        s<<SignToString(first.POZ_Z_D());
        ui->INTEGER_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 8: {
        write_integer_result(first.MUL_ZM_Z());
        break;
    }
    case 9: {
        write_integer_result(first.DIV_ZZ_Z(second));
        break;
    }
    case 10: {
        write_integer_result(first.MOD_ZZ_Z(second));
        break;
    }
    default: {
        break;
    }
    }
}

void MainWindow::on_COM_NN_D_BUTTON_clicked()
{
  NaturalChose = 1;
  ui->NaturalOperation->setText(" == ? ");
}

void MainWindow::on_NZER_N_B_BUTTON_clicked()
{
  NaturalChose = 2;
  ui->NaturalOperation->setText(" == 0? ");
}

void MainWindow::on_ADD_1N_N_BUTTON_clicked()
{
  NaturalChose = 3;
  ui->NaturalOperation->setText(" += 1 ");
}

void MainWindow::on_ADD_NN_N_BUTTON_clicked()
{
  NaturalChose = 4;
  ui->NaturalOperation->setText(" + ");
}

void MainWindow::on_SUB_NN_N_BUTTON_clicked()
{
  NaturalChose = 5;
  ui->NaturalOperation->setText(" - ");
}

void MainWindow::on_MUL_ND_N_BUTTON_clicked()
{
  NaturalChose = 6;
  ui->NaturalOperation->setText(QString::fromStdString(" × ") + QChar(ui->MUL_ND_N_D->value()+'0'));
}

void MainWindow::on_MUL_Nk_N_BUTTON_clicked()
{
  NaturalChose = 7;
  ui->NaturalOperation->setText(" >> k");
}

void MainWindow::on_MUL_NN_N_BUTTON_clicked()
{
  NaturalChose = 8;
  ui->NaturalOperation->setText(" × ");
}

void MainWindow::on_SUB_NDN_N_BUTTON_clicked()
{
  NaturalChose = 9;
  ui->NaturalOperation->setText(" - N × D");
}

void MainWindow::on_DIV_NN_Dk_BUTTON_clicked()
{
  NaturalChose = 10;
  ui->NaturalOperation->setText(" ÷ -> D");
}

void MainWindow::on_DIV_NN_N_BUTTON_clicked()
{
  NaturalChose = 11;
  ui->NaturalOperation->setText(" ÷ ");
}

void MainWindow::on_MOD_NN_N_BUTTON_clicked()
{
  NaturalChose = 12;
  ui->NaturalOperation->setText(" % ");
}

void MainWindow::on_GCF_NN_N_BUTTON_clicked()
{
  NaturalChose = 13;
  ui->NaturalOperation->setText(" GCF ");
}

void MainWindow::on_LCM_NN_N_BUTTON_clicked()
{
  NaturalChose = 14;
  ui->NaturalOperation->setText(" LCM ");
}


void MainWindow::on_MUL_ZZ_Z_BUTTON_clicked()
{
    IntegerChose = 1;
    ui->INTEGER_OPERATION->setText(" * ");
}


void MainWindow::on_ADD_ZZ_Z_BUTTON_clicked()
{
    IntegerChose = 2;
    ui->INTEGER_OPERATION->setText(" + ");
}


void MainWindow::on_SUB_ZZ_Z_BUTTON_clicked()
{
    IntegerChose = 3;
    ui->INTEGER_OPERATION->setText(" - ");
}


void MainWindow::on_ABS_Z_N_BUTTON_clicked()
{
    IntegerChose = 4;
    ui->INTEGER_OPERATION->setText(" || ");
}


void MainWindow::on_TRANS_N_Z_BUTTON_clicked()
{
    IntegerChose = 5;
    ui->INTEGER_OPERATION->setText(" N -> Z ");
}


void MainWindow::on_TRANS_Z_N_BUTTON_clicked()
{
    IntegerChose = 6;
    ui->INTEGER_OPERATION->setText(" Z -> N ");
}


void MainWindow::on_POZ_Z_D_BUTTON_clicked()
{
    IntegerChose = 7;
    ui->INTEGER_OPERATION->setText(" sign? ");
}


void MainWindow::on_MUL_ZM_Z_BUTTON_clicked()
{
    IntegerChose = 8;
    ui->INTEGER_OPERATION->setText(" *(-1) ");
}


void MainWindow::on_DIV_ZZ_Z_BUTTON_clicked()
{
    IntegerChose = 9;
    ui->INTEGER_OPERATION->setText(" / ");
}


void MainWindow::on_MOD_ZZ_Z_BUTTON_clicked()
{
    IntegerChose = 10;
    ui->INTEGER_OPERATION->setText(" % ");
}


void MainWindow::on_actionOpen_Input_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open file"), "input", tr("Text files (*.txt)"));
    if(fileName!=nullptr){
        input_file_name_ = fileName.toStdString();
    }
    std::string s;
    std::ifstream in(input_file_name_);
    in>>s;
    if(s.size()<1000){
        ui->NATURAL_INPUT1->setText(QString::fromStdString(s));
    }else{
        ui->NATURAL_INPUT1->setText("Number readed from file and because of size can't be shown");
        input_ = true;
    }
}


void MainWindow::on_actionOpen_Input2_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open file"), "input2", tr("Text files (*.txt)"));
    if(fileName!=nullptr){
        input2_file_name_ = fileName.toStdString();
    }
    std::string s;
    std::ifstream in(input2_file_name_);
    in>>s;
    if(s.size()<1000){
        ui->NATURAL_INPUT2->setText(QString::fromStdString(s));
    }else{
        ui->NATURAL_INPUT2->setText("Number readed from file and because of size can't be shown");
        input_2_ = true;
    }
}

void MainWindow::on_actionChoose_Output_File_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Open file"), "output", tr("Text files (*.txt)"));
    if(fileName!=nullptr){
        output_file_name_ = fileName.toStdString();
    }
    output_ = true;
}

void MainWindow::write_natural_result(NaturalNumber a){
    std::stringstream ss;
    ss<<a;
    if(ss.str().size()<1000){
        ui->NATURAL_OUTPUT->setText(QString::fromStdString(ss.str()));
    } else{
        ui->NATURAL_OUTPUT->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

void MainWindow::write_integer_result(IntegerNumber a){
    std::stringstream ss;
    ss<<a;
    if(ss.str().size()<1000){
        ui->INTEGER_OUTPUT->setText(QString::fromStdString(ss.str()));
    } else{
        ui->INTEGER_OUTPUT->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

void MainWindow::write_integer_result(NaturalNumber a){
    std::stringstream ss;
    ss<<a;
    if(ss.str().size()<1000){
        ui->INTEGER_OUTPUT->setText(QString::fromStdString(ss.str()));
    } else{
        ui->INTEGER_OUTPUT->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

void MainWindow::write_polynomial_result(Polynomial a){
}

void MainWindow::write_rational_result(RationalNumber a){
    // std::stringstream ss;
    // ss<<a;
    // if(ss.str().size()<1000){
    //     ui->RATIONAL_OUTPUT->setText(QString::fromStdString(ss.str()));
    // } else{
    //     ui->RATIONAL_OUTPUT->setText("Number so big that was writen into file ./output.txt");
    //     std::ofstream out(output_file_name_);
    //     out<<a;
    // }
}

