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
  Node* next_node1 = Big_int->get_first();  // последняя цифра первого числа
  Node* next_node2 = other.Big_int->get_first();  // последняя цифра второго
                                                  // числа

  int count = 0;  // если разряд первого числа превысил разряд второго, получит
                  // значение 1, иначе 0

  int flag = 1;  // равен 1, пока не обнаружится различие в разрядах

  while ((next_node1->next != nullptr) && (next_node2->next != nullptr)) {
    int num1 = next_node1->value;
    int num2 = next_node2->value;

    if (num1 > num2) {
      flag = 0;
      count = 1;
    }
    if (num1 < num2) {
      flag = 0;
      count = 0;
    }
    next_node1 = next_node1->next;
    next_node2 = next_node2->next;
  }
  if ((next_node1->next != nullptr) && (next_node2->next == nullptr)) {
    return GREATER;
  }
  if ((next_node1->next == nullptr) && (next_node2->next != nullptr)) {
    return LESS;
  }
  if (flag == 1) {
    return EQUAL;
  }
  if (count == 1) {
    return GREATER;
  }
  return LESS;
}

bool NaturalNumber::NZER_N_B() {
  if ((Big_int->get_first()->next == nullptr) &&
      (Big_int->get_first()->value == 0)) {  // проверка числа на 0
    return false;  // если число равно 0, то false
  }

  return true;
}

NaturalNumber NaturalNumber::ADD_1N_N() {
  // отвечает за сдвиг на следующий разряд числа
  NaturalNumber ans = *this;
  bool overflow = false;
  Node* ans_iter = ans.get_num().get_first();
  while (ans_iter != nullptr &&
         ans_iter->value == 9) {  // проход по числу, пока переход в следующие
    // разряды не прекратится
    ans_iter->value = 0;
    ans_iter = ans_iter->next;  // перемещение на новый разряд
  }
  if (ans_iter == nullptr) {  // если разряд числа увеличивается
    ans.get_num().push_back(1);
    return ans;
  }
  ans_iter->value += 1;
  return ans;
}

NaturalNumber& NaturalNumber::ADD_NN_N(const NaturalNumber& other) {
  Node* next_node1 =
      Big_int
          ->get_first();  // отвечает за сдвиг на следующий разряд первого числа
  Node* next_node2 =
      other.Big_int
          ->get_first();  // отвечает за сдвиг на следующий разряд второго числа
  int point = 0;  // будет принимать себя излишек, если сумма цифр выйдет за
                  // пределы одного разряда

  while (1) {
    int num1 =
        next_node1->value;  // значение соответствующего разряда первого числа
    int num2 = next_node2->value +
               point;  // значение соответствующего разряда второго числа (плюс
                       // единица от предыдущего разряда, если она есть)
    if (num1 + num2 >= 10) {  // если сумма выходит за пределы одного разряда
      num1 += num2;  // сложение разрядов двух чисел
      num1 -= 10;    // вычитание лишнего десятка
      point = 1;  // сохранение лишнего десятка для следущего разряда
    } else {  // если сумма не выходит за пределы одного разряда
      num1 += num2;  // сложение разрядов двух чисел
      point = 0;  // означает, что следующий разряд не получит десяток от этого
                  // разряда
    }
    next_node1->value = num1;  // итоговое значение суммы разрядов
    if ((next_node1->next == nullptr) && (next_node2->next == nullptr)) {
      break;
    }
    next_node1 = next_node1->next;  // переход в следующий разряд первого числа
    next_node2 = next_node2->next;  // переход в следующий разряд второго числа
  }
  if ((point == 1) && (next_node1->next == nullptr)) {
    Big_int->push_back(1);
  }
  return *this;
}

NaturalNumber& NaturalNumber::MUL_ND_N(const char c) {
  if (c == 0) {                            // если умножение на 0
    Big_int->get_first()->next = nullptr;  // отрываем остальную часть числа
    Big_int->get_first()->value = 0;  // число становится 0
  }

  Node* next_node =
      Big_int->get_first();  // отвечает за сдвиг на следующий разряд числа
  int point = 0;  // содержит в себе значение, оставшееся после умножения
                  // предыдущего разряда

  while (1) {  // проход по всему числу
    if ((next_node->value * c) + point >
        10) {  // если произведение выходит за пределы одного разряда
      int new_point = ((next_node->value * c) + point) /
                      10;  // значение, выходящее за пределы одного разряда
      next_node->value = (next_node->value * c) + point -
                         new_point * 10;  // новое значение разряда
      point = new_point;                  // новое значение point
    } else {  // если произведение не выходит за пределы одного разряда
      next_node->value =
          (next_node->value * c) + point;  // новое значение разряда
      point = 0;  // в следующий разряд не переходит остаток от предыдущего
    }
    if (next_node->next == nullptr) {
      break;
    }
    next_node = next_node->next;  // сдвиг на следующий разряд
  }
  if (point > 0) {  // если разряд после произведения повышается
    Big_int->push_back(point);  // повышение разряда
  }
  return *this;
}

NaturalNumber& NaturalNumber::SUB_NN_N(const NaturalNumber& num) {
  int point = 0;  // если вычитание выйдет за пределы одного разряда, придётся
                  // взять одну цифру из следующего

  Node* next_node1 =
      Big_int
          ->get_first();  // отвечает за сдвиг на следующий разряд первого числа
  Node* next_node2 =
      num.Big_int
          ->get_first();  // отвечает за сдвиг на следующий разряд второго числа

  while (1) {
    int num1 = next_node1->value;  // значение i-го разряда первого числа
    int num2 = next_node2->value + point;  // значение i-го разряда второго
                                           // числа

    if (num1 <
        num2) {  // если значение i-го разряда второго числа больше первого
      num1 += 10;  // разряд первого числа получает 10 от следующего
      num1 -= num2;  // вычитание разрядов
      point = 1;  // будет учитываться в дальнейшем вычитании за взятую ранее
                  // десятку
    } else {
      num1 -= num2;  // если значение i-го разряда первого числа равно или
                     // больше
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
  if (point ==
      1) {  // если осталась единица, которую надо вычесть из старших разрядов
    while (next_node1->value ==
           0) {  // поиск, пока не наткнёмся на отличное от 0 число
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
  return *this;
}

NaturalNumber& NaturalNumber::MUL_Nk_N(const NaturalNumber& k) {
  Node* next_node =
      k.get_num().get_first();  // отвечает за сдвиг на следующий разряд числа k
  if ((Big_int->get_first()->next == nullptr) &&
      (Big_int->get_first()->value == 0)) {
    return *this;
  }
  while (1) {
    if (next_node->value == 0) {
      if (next_node->next == nullptr) {
        break;
      }
      next_node = next_node->next;
      next_node->value += 9;
    }
    Big_int->push_front(0);
    next_node->value -= 1;
  }
  return *this;
}
