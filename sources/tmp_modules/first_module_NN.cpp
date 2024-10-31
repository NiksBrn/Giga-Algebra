#include "../../headers/NaturalNumber.h"
#include <iostream>

Compare NaturalNumber::COM_NN_D(const NaturalNumber& other) const
{
    int k1 = Big_int.get_size();
    int k2 = other.Big_int.get_size(); // количество цифр (разряд) во втором числе

    if (k1 > k2) { //если разряд больше
        return GREATER;
    }
    if (k1 < k2) { // если разряд меньше
        return LESS;
    }
    if (k1 == k2) { // если разряды равены

        int num1 = Big_int.get_last()->value; //первая цифра первого числа
        int num2 = other.Big_int.get_last()->value;//первая цифра второго числа

        if (num1 > num2) { //сравнение двух старших разрядов
            return GREATER;
        }
        if (num1 < num2) {
            return LESS;
        }

        int i = 1;

        Node* next_node1 = Big_int.get_last()->next; //сдвиг на следующий разряд первого числа
        Node* next_node2 = other.Big_int.get_last()->next;//сдвиг на следующий разряд второго числа

        while (i < k1) { //цикл для сравнения всех разрядов обоих чисел

            next_node1 = next_node1->next;//сдвиг на следующий разряд первого числа
            next_node2 = next_node2->next; //сдвиг на следующий разряд второго числа

            num1 = next_node1->value; //значение i-го разряда первого числа
            num2 = next_node2->value; //значение i-го разряда второго числа

            if (num1 > num2) { //сравнение двух разрядов
                return GREATER;
            }
            if (num1 < num2) {
                return LESS;
            }

            i++;
        }
        return EQUAL; //если числа равны
    }
}

bool NaturalNumber::NZER_N_B()
{
    if ((Big_int.get_size() == 1) && (Big_int.get_first()->value == 0)) {// проверка числа на 0
        return false; // если число равно 0, то false
    }

    return true;
}

void NaturalNumber::ADD_1N_N()
{
    if (Big_int.get_first() ->value == 9) { // если изменение числа должно выйти за пределы одного разряда 

        Big_int.get_first()->value = 0;
        Node* next_node = Big_int.get_first();

        for (int i = 1; i < Big_int.get_size(); i++) { // проход по числу, пока переход в следующие разряды не прекратится
            next_node = next_node->next;// перемещение на новый разряд
            if (next_node->value == 9) {//если следующий разряд также изменяет следующий
                next_node->value = 0;
                continue;
            }
            next_node->value += 1;
            break;
        }
        if (next_node->value == 0) { // если разряд числа увеличивается
            Big_int.push_back(1);
        }
    }
    else { // стандартное прибавление единицы
        Big_int.get_first()->value += 1;
    }
}

NaturalNumber& NaturalNumber::ADD_NN_N(const NaturalNumber& other) {

    Node* next_node1 = Big_int.get_first(); //отвечает за сдвиг на следующий разряд первого числа
    Node* next_node2 = other.Big_int.get_first();//отвечает за сдвиг на следующий разряд второго числа
    int point = 0; //будет принимать себя излишок, если сумма цифр выйдет за пределы одного разряда

    for (int i = 0; i < other.Big_int.get_size(); i++) {
        int num1 = next_node1->value;
        int num2 = next_node2->value + point;
        if (num1 < num2) {
            num1 += num2;
            num1 -= 10;
            point = 1;
        }
        else {
            num1 += num2;
            point = 0;
        }
        next_node1->value = num1;
        next_node1->next;
        next_node2->next;
    }
    if ((point == 1) && (next_node1->next == nullptr)) {
        Big_int.push_back(1);
    }
}

NaturalNumber& NaturalNumber::MUL_ND_N(const char c)
{
    if (c == 0) { // если умножение на 0
        Big_int.get_first()->next = nullptr; // отрываем остальную часть числа
        Big_int.get_first()->value = 0; // число становится 0
    }
    if (Big_int.get_first()->value * c >= 10) { // если умножение последней цифры даёт двузначное число

        int desatok = (Big_int.get_first()->value * c) / 10; // десяток от умножения
        Big_int.get_first()->value = (Big_int.get_first()->value * c) - (desatok * 10); // замена последней цифры

        if (Big_int.get_size() > 1) { //если число не однозначное
            Node* next_node = Big_int.get_first()->next;//получение следующего разряда
            if (next_node->value + desatok > 10) { // если сумма второй с конца цифры и десятка произведения даёт двузначное число

                next_node->value = (next_node->value + desatok - 10); // новое значение второй с конца цифры

                if (Big_int.get_size() > 2) { // если число больше 99
                    for (int i = 2; i < Big_int.get_size(); i++) { // проход по числу, пока переход в следующие разряды не прекратится
                        next_node->next;
                        if (next_node->value == 9) {
                            next_node->value = 0;
                            continue;
                        }
                        next_node->value += 1;
                        break;
                    }
                    if (next_node->value == 0) { // если разряд числа увеличивается
                        Big_int.push_back(1);
                    }
                }
                else { // двузначному числу добавляется разряд сотен
                    Big_int.push_front(1);
                }
            }
            else { // двузначное число не меняет своей разрядности
                next_node->value += desatok;
            }
        }
        else { // одозначное число становится двузначным
            Big_int.push_back(desatok);
        }
    }       
    else {
        Big_int.get_first()->value *= c;
    }
}

NaturalNumber& NaturalNumber::SUB_NN_N(const NaturalNumber& num)
{
    int size1 = Big_int.get_size(); // размер первого числа
    int size2 = num.Big_int.get_size(); // размер второго числа

    int point = 0; // если вычитание выйдет за пределы одного разряда, придётся взять одну цифру из следущего
    int i = 1;

    int num1 = Big_int.get_first()->value; //значение первого разряда первого числа
    int num2 = num.Big_int.get_first()->value; //значение первого разряда второго числа

    if (num1 < num2) { //если значение первого разряда второго числа больше первого
        num1 += 10; //разряд первого числа получает 10 от следущего
        num1 -= num2; //вычитание разрядов
        point = 1; //будет учитываться в дальнейшем вычитании за взятую ранее десятку
    }
    else {
        num1 -= num2; //если значение первого разряда первого числа равно или больше
        point = 0;
    }

    Big_int.get_first()->value = num1; //полученная разность

    Node* next_node1 = Big_int.get_first()->next; //сдвиг на следующий разряд первого числа
    Node* next_node2 = num.Big_int.get_first()->next;//сдвиг на следующий разряд второго числа

    while (i < size2) {

        next_node1 = next_node1->next;//сдвиг на следующий разряд первого числа
        next_node2 = next_node2->next; //сдвиг на следующий разряд второго числа

        num1 = next_node1->value; //значение i-го разряда первого числа
        num2 = next_node2->value; //значение i-го разряда второго числа

        if (num1 < num2) { //если значение i-го разряда второго числа больше первого
            num1 += 10; //разряд первого числа получает 10 от следущего
            num1 -= num2; //вычитание разрядов
            point = 1; //будет учитываться в дальнейшем вычитании за взятую ранее десятку
        }
        else {
            num1 -= num2; //если значение i-го разряда первого числа равно или больше
            point = 0;
        }

        next_node1->value = num1; //полученная разность

        i++;
    }
    next_node1 = next_node1->next;//сдвиг на следующий разряд первого числа
    if ((point == 1) && (next_node1->value == 0)) {//если осталась единица, которую надо вычесть из старших разрядов, но там 0
        while (next_node1->value != 0) { //поиск, пока не наткнёмся на отличное от 0 число
            next_node1->value = 9;
            next_node1->next;
        }
        point = 0;
        next_node1->value -= 1; //вычитание единицы
    }
    if (point == 1) {//если осталась единица, которую надо вычесть из старших разрядов, при этом там не 0
        next_node1->value -= 1;
    }
    //Node* check_node = Big_int.get_last();
    //for (int j = 0; j < size1; j++) {
    //    if (check_node->value != 0) {
    //       break;                         ////удаление незначащих нулей слева направо, надо добавить prev
    //   }
    //   if (check_node->value == 0) {
    //        check_node->prev = nullptr;
      //  }
    //}
}
    
NaturalNumber& NaturalNumber::MUL_Nk_N(const NaturalNumber& k)
{
    if ((Big_int.get_size() != 1) && (Big_int.get_first()->value != 0)) {
        if (k.Big_int.get_first()->value != 1) {
            for (int i = 0; i < k.Big_int.get_size(); i++) {
                Big_int.push_front(0);
            }
        }
    }
}