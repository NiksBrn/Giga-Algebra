#include "generate_number.h"

void generate_new_number1(long long len){
    std::ofstream out1("number1.txt");
    srand(time(NULL));
    out1 << 1;
    for (int i = 0; i < len; i++) {
        out1<< rand()%10;
    }
    out1.close();
}

void generate_new_number2(long long len){
    std::ofstream out2("number2.txt");
    srand(time(NULL));
    out2 <<1;
    for (int i = 0; i < len; i++) {
        out2 << rand()%10;
    }
    out2.close();
}

std::string get_number1(){
    std::ifstream in1("number1.txt");
    std::string s1;
    in1 >> s1;
    in1.close();
    return s1;
}
std::string get_number2(){
    std::ifstream in2("number2.txt");
    std::string s2;
    in2 >> s2;
    in2.close();
    return s2;
}
