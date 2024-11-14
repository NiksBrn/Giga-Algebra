#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

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
    if(input_ && input_2_) {
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
    } else if(input_2_){
        s1 = ui->INTEGER_INPUT1->toPlainText().toStdString();
        std::ifstream in(input2_file_name_);
        in>>s2;

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

void MainWindow::on_pushButton_17_clicked()
{
    RationalNumber first, second;
    std::string s1, s2, s3, s4;
    if(input_ && input_2_){
        std::ifstream in1(input_file_name_);
        std::string tmp, temp;
        in1>>tmp;
        s1 = tmp.substr(0,tmp.find('/'));
        s2 = tmp.substr(tmp.find('/')+1);
        std::ifstream in2(input2_file_name_);
        in2>>temp;
        s3 = temp.substr(0,temp.find('/'));
        s4 = temp.substr(temp.find('/')+1);

        if(s1[0] == '-'){
            first = RationalNumber('-', s1.substr(s1.find('-')+1), s2);
        } else {
            first = RationalNumber('+', s1, s2);
        }
        if(s3[0] == '-'){
            second = RationalNumber('-', s3.substr(s3.find('-')+1), s4);
        } else {
            second = RationalNumber('+', s3, s4);
        }
    } else if(input_){
        std::ifstream in1(input_file_name_);
        std::string tmp;
        in1>>tmp;
        s1 = tmp.substr(0,tmp.find('/'));
        s2 = tmp.substr(tmp.find('/')+1);
        s3 = ui->RATIONAL_INPUT_NUMERATOR2->toPlainText().toStdString();
        s4 = ui->RATIONAL_INPUT_DENOMINATOR2->toPlainText().toStdString();
        std::string sign = ui->RATIONAL_INPUT_SIGN2->text().toStdString();

        if(s1[0] == '-'){
            first = RationalNumber('-', s1.substr(s1.find('-')+1), s2);
        } else {
            first = RationalNumber('+', s1, s2);
        }
        if(sign[0] == '-'){
            second = RationalNumber('-', s3, s4);
        } else {
            second = RationalNumber('+', s3, s4);
        }
    } else if(input_2_){
        s1 = ui->RATIONAL_INPUT_NUMERATOR1->toPlainText().toStdString();
        s2 = ui->RATIONAL_INPUT_DENOMINATOR1->toPlainText().toStdString();
        std::string sign = ui->RATIONAL_INPUT_SIGN1->text().toStdString();
        std::string temp;
        std::ifstream in2(input2_file_name_);
        in2>>temp;
        s3 = temp.substr(0,temp.find('/'));
        s4 = temp.substr(temp.find('/')+1);

        if(sign[0] == '-'){
            first = RationalNumber('-', s1, s2);
        } else {
            first = RationalNumber('+', s1, s2);
        }
        if(s3[0] == '-'){
            second = RationalNumber('-', s3.substr(s3.find('-')+1), s4);
        } else {
            second = RationalNumber('+', s3, s4);
        }
    } else {
        s1 = ui->RATIONAL_INPUT_NUMERATOR1->toPlainText().toStdString();
        s2 = ui->RATIONAL_INPUT_DENOMINATOR1->toPlainText().toStdString();
        std::string sign1 = ui->RATIONAL_INPUT_SIGN1->text().toStdString();

        s3 = ui->RATIONAL_INPUT_NUMERATOR2->toPlainText().toStdString();
        s4 = ui->RATIONAL_INPUT_DENOMINATOR2->toPlainText().toStdString();
        std::string sign2 = ui->RATIONAL_INPUT_SIGN2->text().toStdString();

        if(sign1[0] == '-'){
            first = RationalNumber('-', s1, s2);
        } else {
            first = RationalNumber('+', s1, s2);
        }
        if(sign2[0] == '-'){
            second = RationalNumber('-', s3, s4);
        } else {
            second = RationalNumber('+', s3, s4);
        }
    }

    switch (RationalChose) {
        case 1: {
            write_rational_result(first.MUL_QQ_Q(second));
            break;
        }
        case 2: {
            if(first.INT_Q_B()){
                ui->RATIONAL_OUTPUT_NUMERATOR->setText("YES");
            } else {
                ui->RATIONAL_OUTPUT_NUMERATOR->setText("NO");
            }
            break;
        }
        case 3: {
            write_rational_result(first.RED_Q_Q());
            break;
        }
        case 4: {
            write_rational_result(first.ADD_QQ_Q(second));
            break;
        }
        case 5: {
            std::string s = ui->RATIONAL_INPUT_NUMERATOR1->toPlainText().toStdString();
            IntegerNumber a('+', s);
            if(ui->RATIONAL_INPUT_SIGN1->text().toStdString() == "-") {
                a.MUL_ZM_Z();
            }
            write_rational_result(first.Trans_Z_Q(a));
            break;
        }
        case 6: {
            write_rational_result(first.DIV_QQ_Q(second));
            break;
        }
        case 7: {
            write_rational_result(first.SUB_QQ_Q(second));
            break;
        }
        case 8: {
            try{
                IntegerNumber a = first.Trans_Q_Z();
                write_rational_result(a);
            } catch(...){
                ui->RATIONAL_OUTPUT_NUMERATOR->setText("Denominator != 1");
            }

            break;
        }
        default: {
            break;
        }
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    Polynomial first, second;
    std::string s1, s2;
    if(input_ && input_2_) {
        std::ifstream in1(input_file_name_);
        in1>>s1;
        std::ifstream in2(input2_file_name_);
        in2>>s2;

        first = Polynomial(s1);
        second = Polynomial(s2);
    } else if(input_){
        std::ifstream in(input_file_name_);
        in>>s1;
        s2 = ui->POLYNOMIAL_INPUT2->toPlainText().toStdString();

        first = Polynomial(s1);
        second = Polynomial(s2);
    } else if(input_2_){
        s1 = ui->POLYNOMIAL_INPUT1->toPlainText().toStdString();
        std::ifstream in(input2_file_name_);
        in>>s2;

        first = Polynomial(s1);
        second = Polynomial(s2);
    } else {
        s1 = ui->POLYNOMIAL_INPUT1->toPlainText().toStdString();
        s2 = ui->POLYNOMIAL_INPUT2->toPlainText().toStdString();

        first = Polynomial(s1);
        second = Polynomial(s2);
    }

    switch (PolynomialChose) {
    case 1: {
        write_polynomial_result(first.MUL_PP_P(second));
        break;
    }
    case 2: {
        // write_polynomial_result(first.NMR_P_P());
        break;
    }
    case 3: {
        write_polynomial_result(first.ADD_PP_P(second));
        break;;
    }
    case 4: {
        write_polynomial_result(first.SUB_PP_P(second));
        break;
    }
    case 5: {
        // write_polynomial_result(first.GCF_PP_P(second));
        break;
    }
    case 6: {
        write_polynomial_result(first.DER_P_P());
        break;
    }
    case 7: {
        std::stringstream s;
        s<<first.FAC_P_Q();
        ui->POLYNOMIAL_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 8: {
        std::stringstream s;
        s<<first.LED_P_Q();
        ui->POLYNOMIAL_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 9: {
        std::stringstream s;
        s<<first.DEG_P_N();
        ui->POLYNOMIAL_OUTPUT->setText(QString::fromStdString(s.str()));
        break;
    }
    case 10: {
        std::string s1, s2;
        char sign = '+';
        s1 = ui->POLYNOMIAL_INPUT2->toPlainText().toStdString();
        if(s1.find("/") == std::string::npos){
            s2 = "1";
        }
        else{
            s2 = ui->POLYNOMIAL_INPUT2->toPlainText().toStdString();
            s2 = s2.substr(s2.find("/")+1);
        }
        s1 = s1.substr(0, s1.find("/"));
        if(s1[0] == '-') {
            sign = '-';
            s1 = s1.substr(s1.find('-')+ 1);
        }
        RationalNumber s(IntegerNumber(sign, s1), NaturalNumber(s2));
        write_polynomial_result(first.MUL_PQ_P(s));
        break;
    }
    case 11:{
        // write_polynomial_result(first.DIV_PP_P(second));
        break;
    }
    case 12:{
        long long k = std::stoll(ui->POLYNOMIAL_INPUT2->toPlainText().toStdString());
        // write_polynomial_result(first.MUL_Pxk_P(k));
        break;
    }
    case 13:{
        // write_polynomial_result(first.MOD_PP_P(second));
        break;
    }
    default: {
        break;
    }
    }
}

void MainWindow::on_COM_NN_D_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 1;
    ui->NaturalOperation->setText(" == ? ");
}

void MainWindow::on_NZER_N_B_BUTTON_clicked()
{
    NaturalChose = 2;
    ui->NaturalOperation->setText(" == 0? ");
    ui->NATURAL_INPUT2->hide();
}

void MainWindow::on_ADD_1N_N_BUTTON_clicked()
{
    NaturalChose = 3;
    ui->NaturalOperation->setText(" += 1 ");
    ui->NATURAL_INPUT2->hide();
}

void MainWindow::on_ADD_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 4;
    ui->NaturalOperation->setText(" + ");
}

void MainWindow::on_SUB_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 5;
    ui->NaturalOperation->setText(" - ");
}

void MainWindow::on_MUL_ND_N_BUTTON_clicked()
{
    NaturalChose = 6;
    ui->NaturalOperation->setText(QString::fromStdString(" × ") + QChar(ui->MUL_ND_N_D->value()+'0'));
    ui->NATURAL_INPUT2->hide();
}

void MainWindow::on_MUL_Nk_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 7;
    ui->NaturalOperation->setText(" >> k");
}

void MainWindow::on_MUL_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 8;
    ui->NaturalOperation->setText(" × ");
}

void MainWindow::on_SUB_NDN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 9;
    ui->NaturalOperation->setText(" - N × D");
}

void MainWindow::on_DIV_NN_Dk_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 10;
    ui->NaturalOperation->setText(" ÷ -> D");
}

void MainWindow::on_DIV_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 11;
    ui->NaturalOperation->setText(" ÷ ");
}

void MainWindow::on_MOD_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 12;
    ui->NaturalOperation->setText(" % ");
}

void MainWindow::on_GCF_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 13;
    ui->NaturalOperation->setText(" GCF ");
}

void MainWindow::on_LCM_NN_N_BUTTON_clicked()
{
    show_second_natural();
    NaturalChose = 14;
    ui->NaturalOperation->setText(" LCM ");
}

void MainWindow::on_MUL_ZZ_Z_BUTTON_clicked()
{
    show_second_integer();
    IntegerChose = 1;
    ui->INTEGER_OPERATION->setText(" * ");
}

void MainWindow::on_ADD_ZZ_Z_BUTTON_clicked()
{
    show_second_integer();
    IntegerChose = 2;
    ui->INTEGER_OPERATION->setText(" + ");
}

void MainWindow::on_SUB_ZZ_Z_BUTTON_clicked()
{
    show_second_integer();
    IntegerChose = 3;
    ui->INTEGER_OPERATION->setText(" - ");
}

void MainWindow::on_ABS_Z_N_BUTTON_clicked()
{
    IntegerChose = 4;
    ui->INTEGER_OPERATION->setText(" || ");
    ui->INTEGER_INPUT2->hide();
}

void MainWindow::on_TRANS_N_Z_BUTTON_clicked()
{
    IntegerChose = 5;
    ui->INTEGER_OPERATION->setText(" N -> Z ");
    ui->INTEGER_INPUT2->hide();
}

void MainWindow::on_TRANS_Z_N_BUTTON_clicked()
{
    IntegerChose = 6;
    ui->INTEGER_OPERATION->setText(" Z -> N ");
    ui->INTEGER_INPUT2->hide();
}

void MainWindow::on_POZ_Z_D_BUTTON_clicked()
{
    IntegerChose = 7;
    ui->INTEGER_OPERATION->setText(" sign? ");
    ui->INTEGER_INPUT2->hide();
}

void MainWindow::on_MUL_ZM_Z_BUTTON_clicked()
{
    IntegerChose = 8;
    ui->INTEGER_OPERATION->setText(" *(-1) ");
    ui->INTEGER_INPUT2->hide();
}

void MainWindow::on_DIV_ZZ_Z_BUTTON_clicked()
{
    show_second_integer();
    IntegerChose = 9;
    ui->INTEGER_OPERATION->setText(" / ");
}

void MainWindow::on_MOD_ZZ_Z_BUTTON_clicked()
{
    show_second_integer();
    IntegerChose = 10;
    ui->INTEGER_OPERATION->setText(" % ");
}

void MainWindow::on_MUL_QQ_Q_BUTTON_clicked()
{
    show_second_rational();
    RationalChose = 1;
    ui->RATIONAL_OPERATION->setText(" * ");
}

void MainWindow::on_INT_Q_B_BUTTON_clicked()
{
    RationalChose = 2;
    ui->RATIONAL_OPERATION->setText(" is int? ");
    ui->RATIONAL_INPUT_DENOMINATOR2->hide();
    ui->RATIONAL_INPUT_NUMERATOR2->hide();
    ui->RATIONAL_INPUT_SIGN2->hide();
}

void MainWindow::on_RED_Q_Q_BUTTON_clicked()
{
    RationalChose = 3;
    ui->RATIONAL_OPERATION->setText(" reduce ");
    ui->RATIONAL_INPUT_DENOMINATOR2->hide();
    ui->RATIONAL_INPUT_NUMERATOR2->hide();
    ui->RATIONAL_INPUT_SIGN2->hide();
}

void MainWindow::on_ADD_QQ_Q_BUTTON_clicked()
{
    show_second_rational();
    RationalChose = 4;
    ui->RATIONAL_OPERATION->setText(" + ");
}

void MainWindow::on_TRANS_Z_Q_BUTTON_clicked()
{
    RationalChose = 5;
    ui->RATIONAL_OPERATION->setText(" Z -> Q ");
    // ui->RATIONAL_INPUT_DENOMINATOR1->hide();
}

void MainWindow::on_DIV_QQ_Q_BUTTON_clicked()
{
    show_second_rational();
    RationalChose = 6;
    ui->RATIONAL_OPERATION->setText(" / ");
}

void MainWindow::on_SUB_QQ_Q_BUTTON_clicked()
{
    show_second_rational();
    RationalChose = 7;
    ui->RATIONAL_OPERATION->setText(" - ");
}

void MainWindow::on_TRANS_Q_Z_BUTTON_clicked()
{
    RationalChose = 8;
    ui->RATIONAL_OPERATION->setText(" Q -> Z ");
    ui->RATIONAL_INPUT_DENOMINATOR2->hide();
    ui->RATIONAL_INPUT_NUMERATOR2->hide();
    ui->RATIONAL_INPUT_SIGN2->hide();
}

void MainWindow::on_MUL_PP_P_BUTTON_clicked()
{
    PolynomialChose = 1;
    ui->POLYNOMIAL_OPERATOR->setText(" * ");
}


void MainWindow::on_NMR_P_P_clicked()
{
    PolynomialChose = 2;
    ui->POLYNOMIAL_OPERATOR->setText(" NMR ");
}


void MainWindow::on_ADD_PP_P_BUTTON_clicked()
{
    PolynomialChose = 3;
    ui->POLYNOMIAL_OPERATOR->setText(" + ");
}


void MainWindow::on_SUB_PP_P_BUTTON_clicked()
{
    PolynomialChose = 4;
    ui->POLYNOMIAL_OPERATOR->setText(" - ");
}


void MainWindow::on_GCF_PP_P_BUTTON_clicked()
{
    PolynomialChose = 5;
    ui->POLYNOMIAL_OPERATOR->setText(" GCF ");
}


void MainWindow::on_DER_P_P_clicked()
{
    PolynomialChose = 6;
    ui->POLYNOMIAL_OPERATOR->setText(" DER ");
}


void MainWindow::on_FAC_P_Q_BUTTON_clicked()
{
    PolynomialChose = 7;
    ui->POLYNOMIAL_OPERATOR->setText(" FAC ");
}


void MainWindow::on_LED_P_Q_BUTTON_clicked()
{
    PolynomialChose = 8;
    ui->POLYNOMIAL_OPERATOR->setText(" LED ");
}


void MainWindow::on_DEG_P_N_BUTTON_clicked()
{
    PolynomialChose = 9;
    ui->POLYNOMIAL_OPERATOR->setText(" deg ");
}


void MainWindow::on_MUL_PQ_P_BUTTON_clicked()
{
    PolynomialChose = 10;
    ui->POLYNOMIAL_OPERATOR->setText(" *Q ");
}


void MainWindow::on_DIV_PP_P_BUTTON_clicked()
{
    PolynomialChose = 11;
    ui->POLYNOMIAL_OPERATOR->setText(" / ");
}


void MainWindow::on_MUL_PXK_BUTTON_clicked()
{
    PolynomialChose = 12;
    ui->POLYNOMIAL_OPERATOR->setText(" *x^k ");
}


void MainWindow::on_MOD_PP_P_BUTTON_clicked()
{
    PolynomialChose = 13;
    ui->POLYNOMIAL_OPERATOR->setText(" % ");
}

void MainWindow::show_second_rational(){
    ui->RATIONAL_INPUT_DENOMINATOR2->show();
    ui->RATIONAL_INPUT_NUMERATOR2->show();
    ui->RATIONAL_INPUT_SIGN2->show();
}

void MainWindow::show_second_integer(){
    ui->INTEGER_INPUT2->show();
}

void MainWindow::show_second_natural(){
    ui->NATURAL_INPUT2->show();
}

void MainWindow::on_actionOpen_Input_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open file"), "input.txt", tr("Text files (*.txt)"));
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
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open file"), "input2.txt", tr("Text files (*.txt)"));
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

void MainWindow::write_rational_result(RationalNumber a){
    std::stringstream ss;
    ss<<a;
    std::string num = ss.str();
    if(num.size()<1000){
        std::string sign = "+";
        if(num[0] == '-') sign = "-";
        std::string numerator = num.substr(num.find('-')+1);
        numerator = numerator.substr(0, numerator.find('/'));
        std::string denominator = num.substr(num.find('/')+1);
        ui->RATIONAL_OUTPUT_SIGN->setText(QString::fromStdString(sign));
        ui->RATIONAL_OUTPUT_NUMERATOR->setText(QString::fromStdString(numerator));
        ui->RATIONAL_OUTPUT_DENOMINATOR->setText(QString::fromStdString(denominator));
    } else{
        ui->RATIONAL_OUTPUT_NUMERATOR->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

void MainWindow::write_rational_result(IntegerNumber a){
    std::stringstream ss;
    ss<<a;
    std::string num = ss.str();
    if(num.size()<1000){
        std::string sign = "+";
        if(num[0] == '-') sign = "-";
        std::string numerator = num.substr(num.find('-')+1);
        ui->RATIONAL_OUTPUT_SIGN->setText(QString::fromStdString(sign));
        ui->RATIONAL_OUTPUT_NUMERATOR->setText(QString::fromStdString(numerator));
        ui->RATIONAL_OUTPUT_DENOMINATOR->setText("1");
    } else{
        ui->RATIONAL_OUTPUT_NUMERATOR->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

void MainWindow::write_polynomial_result(Polynomial a){
    std::stringstream ss;
    ss<<a;
    if(ss.str().size()<1000){
        ui->POLYNOMIAL_OUTPUT->setText(QString::fromStdString(ss.str()));
    } else{
        ui->POLYNOMIAL_OUTPUT->setText("Number so big that was writen into file ./output.txt");
        std::ofstream out(output_file_name_);
        out<<a;
    }
}

