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

void MainWindow::on_COM_NN_D_BUTTON_clicked() {
  NaturalChose = 1;
  ui->NaturalOperation->setText(" == ? ");
}

void MainWindow::on_NZER_N_B_BUTTON_clicked() {
  NaturalChose = 2;
  ui->NaturalOperation->setText(" == 0? ");
}

void MainWindow::on_ADD_1N_N_BUTTON_clicked() {
  NaturalChose = 3;
  ui->NaturalOperation->setText(" += 1 ");
}

void MainWindow::on_ADD_NN_N_BUTTON_clicked() {
  NaturalChose = 4;
  ui->NaturalOperation->setText(" + ");
}

void MainWindow::on_SUB_NN_N_BUTTON_clicked() {
  NaturalChose = 5;
  ui->NaturalOperation->setText(" - ");
}

void MainWindow::on_MUL_ND_N_BUTTON_clicked() {
  NaturalChose = 6;
    ui->NaturalOperation->setText(QString::fromStdString(" × ") + QChar(ui->MUL_ND_N_D->value()+'0'));
}

void MainWindow::on_MUL_Nk_N_BUTTON_clicked() {
  NaturalChose = 7;
  ui->NaturalOperation->setText(" >> k");
}

void MainWindow::on_MUL_NN_N_BUTTON_clicked() {
  NaturalChose = 8;
  ui->NaturalOperation->setText(" × ");
}

void MainWindow::on_SUB_NDN_N_BUTTON_clicked() {
  NaturalChose = 9;
  ui->NaturalOperation->setText(" - N × D");
}

void MainWindow::on_DIV_NN_Dk_BUTTON_clicked() {
  NaturalChose = 10;
  ui->NaturalOperation->setText(" ÷ -> D");
}

void MainWindow::on_DIV_NN_N_BUTTON_clicked() {
  NaturalChose = 11;
  ui->NaturalOperation->setText(" ÷ ");
}

void MainWindow::on_MOD_NN_N_BUTTON_clicked() {
  NaturalChose = 12;
  ui->NaturalOperation->setText(" % ");
}

void MainWindow::on_GCF_NN_N_BUTTON_clicked() {
  NaturalChose = 13;
  ui->NaturalOperation->setText(" GCF ");
}

void MainWindow::on_LCM_NN_N_BUTTON_clicked() {
  NaturalChose = 14;
  ui->NaturalOperation->setText(" LCM ");
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

}

void MainWindow::write_rational_result(RationalNumber a){

}

void MainWindow::write_polynomial_result(Polynomial a){

}


