#include <iostream>

#include "../../headers/NaturalNumber.h"

bool NaturalNumber::operator==(const NaturalNumber& other) const {
  if (COM_NN_D(other) == EQUAL) return true;
  return false;
}

bool NaturalNumber::operator!=(const NaturalNumber& other) const {
  if (COM_NN_D(other) != EQUAL) return true;
  return false;
}

bool NaturalNumber::operator>=(const NaturalNumber& other) const {
  if (COM_NN_D(other) == EQUAL || COM_NN_D(other) == GREATER) return true;
  return false;
}

bool NaturalNumber::operator<=(const NaturalNumber& other) const {
  if (COM_NN_D(other) == EQUAL || COM_NN_D(other) == LESS) return true;
  return false;
}

bool NaturalNumber::operator<(const NaturalNumber& other) const {
  if (COM_NN_D(other) == LESS) return true;
  return false;
}

bool NaturalNumber::operator>(const NaturalNumber& other) const {
  if (COM_NN_D(other) == GREATER) return true;
  return false;
}

Compare NaturalNumber::COM_NN_D(const NaturalNumber& other) const {
  Node* n1 = Big_int->get_first();
  Node* n2 = other.Big_int->get_first(); // для итерации по числам
  bool greater = false; // для сравнения
  bool less = false; // для сравнения
  while(n1 != nullptr && n2 != nullptr) {
      if (n1->value > n2->value) { // если первое больше то меняем флаги
          greater = true;
          less = false;
      }
      if (n1->value < n2->value) { // если первое меньше то меняем флаги
          greater = false;
          less = true;
      }
      n1 = n1->next;
      n2 = n2->next; // итерируемся на следующий разряд
  }
  if(n1 == nullptr && n2 == nullptr) { // если длины чисел равны
      if (greater) return GREATER;
      else if (less) return LESS;
      else return EQUAL;
  }else{ // если длины чисел разные
      if (n1 == nullptr) return LESS;
      else return GREATER;
  }
}

bool NaturalNumber::NZER_N_B() {
  if ((Big_int->get_first()->next == nullptr) && (Big_int->get_first()->value == 0)) {  // проверка числа на 0
    return false;  // если число равно 0, то false
  }
  return true;
}

NaturalNumber NaturalNumber::ADD_1N_N() {
  // отвечает за сдвиг на следующий разряд числа
  NaturalNumber ans = *this;
  Node* next_node = ans.get_num().get_first();
  while (next_node != nullptr) {  // проход по числу, пока переход в следующие разряды не прекратится
    if (next_node->value==9){
      next_node->value = 0;
      if(next_node->next==nullptr){
        break;
      }
      next_node = next_node->next;// перемещение на новый разряд
    }
    else{
      next_node->value += 1;
      return ans;
    }
  }
  ans.get_num().push_back(1);// если разряд числа увеличивается
  return ans;
}


NaturalNumber NaturalNumber::ADD_NN_N(const NaturalNumber& other) {
  NaturalNumber result;
  Node* cur_node1 = (*this).get_num().get_first();  // отвечает за сдвиг на следующий разряд первого числа
  Node* cur_node2 = other.get_num().get_first();  // отвечает за сдвиг на следующий разряд второго числа

  char cur_digit = 0;
  while (cur_node1 != nullptr && cur_node2 != nullptr) {
    cur_digit += cur_node1->value + cur_node2->value;
    if (cur_digit >= 10) {
      result.get_num().push_back(cur_digit - 10);
      cur_digit = 1; // В следующий разряд
    } else {
      result.get_num().push_back(cur_digit);
      cur_digit = 0;
    }
    cur_node1 = cur_node1->next;
    cur_node2 = cur_node2->next;
  }
  while (cur_node1 != nullptr) {
    result.get_num().push_back(cur_node1->value + cur_digit);
    cur_node1 = cur_node1->next;
    cur_digit = 0;
  }
  while (cur_node2 != nullptr) {
    result.get_num().push_back(cur_node2->value + cur_digit);
    cur_node2 = cur_node2->next;
    cur_digit = 0;
  }
  if (cur_digit != 0) {
    result.get_num().push_back(cur_digit);
  }
  return result;
}

NaturalNumber NaturalNumber::MUL_ND_N(const char c) {
  NaturalNumber result;
  if (!(*this).NZER_N_B() || c == 0) {
    return NaturalNumber("0");
  }
  Node* cur_node = (*this).get_num().get_first();  // отвечает за сдвиг на следующий разряд первого числа

  char cur_digit = 0;
  while (cur_node != nullptr) {
    cur_digit += cur_node->value * c;
    result.get_num().push_back(cur_digit - cur_digit / 10 * 10);
    cur_digit /= 10;
    cur_node = cur_node->next;
  }
  if (cur_digit != 0) {
    result.get_num().push_back(cur_digit);
  }
  return result;
}

NaturalNumber NaturalNumber::SUB_NN_N(const NaturalNumber& num) {
  NaturalNumber ans = *this;
  Node* next_node1 = ans.get_num().get_first(); // отвечает за сдвиг на следующий разряд первого числа
  int point = 0;  // если вычитание выйдет за пределы одного разряда, придётся взять одну цифру из следующего
  Node* next_node2 =num.Big_int->get_first();  // отвечает за сдвиг на следующий разряд второго числа

  while (next_node2 != nullptr) {
    int num1 = next_node1->value;  // значение i-го разряда первого числа
    int num2 = next_node2->value + point;  // значение i-го разряда второго числа

    if (num1 <num2) {  // если значение i-го разряда второго числа больше первого
      num1 += 10;  // разряд первого числа получает 10 от следующего
      num1 -= num2;  // вычитание разрядов
      point = 1;  // будет учитываться в дальнейшем вычитании за взятую ранее
                  // десятку
    } else {
      num1 -= num2;  // если значение i-го разряда первого числа равно или больше
      point = 0;
    }
    next_node1->value = num1;  // полученная разность
    if (next_node2->next == nullptr) {
      break;
    }
    next_node1 = next_node1->next;  // сдвиг на следующий разряд первого числа
    next_node2 = next_node2->next;  // сдвиг на следующий разряд второго числа
  }
  next_node1 = next_node1->next;
  if (point == 1) {  // если осталась единица, которую надо вычесть из старших разрядов
    while (next_node1->value == 0) {  // поиск, пока не наткнёмся на отличное от 0 число
      next_node1->value = 9;
      next_node1 = next_node1->next;
    }
    next_node1->value -= 1;  // вычитание единицы
  }
  // Node* check_node = Big_int.get_last();
  // for (int j = 0; j < size1; j++) {
  //     if (check_node->value != 0) {
  //        break;                         ////удаление незначащих нулей слева
  //        направо, надо добавить prev
  //    }
  //    if (check_node->value == 0) {
  //         check_node->prev = nullptr;
  //   }
  //}
  return ans;
}

NaturalNumber NaturalNumber::MUL_Nk_N(const NaturalNumber& k) {
  NaturalNumber ans = *this;
  if (!ans.NZER_N_B()) {
    return ans;
  }
  NaturalNumber i("0");
  for(i;i.COM_NN_D(k) != EQUAL;i = i.ADD_1N_N()){
    ans.get_num().push_front(0);
  }
  return ans;
} //Created by Skobelev Nikita 3383


//NaturalNumber NaturalNumber::MUL_Nk_N(const NaturalNumber& k) {
//  NaturalNumber ans = *this;
//  Node* next_node1 = ans.get_num().get_first(); // отвечает за сдвиг на следующий разряд числа
//  Node* next_node = k.get_num().get_first();  // отвечает за сдвиг на следующий разряд числа k
//  if ((next_node1->next == nullptr) && (next_node1->value == 0)) {
//    return ans;
//  }
//  while (next_node != nullptr) {
//    if (next_node->value == 0) {
//      if (next_node->next == nullptr) {
//        break;
//      }
//      next_node = next_node->next;
//      next_node->value += 9;
//    }
//    ans.get_num().push_front(0);
//    next_node->value -= 1;
//  }
//  return ans;
//}
