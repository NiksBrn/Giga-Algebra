// project Giga-Algebra
// Developers: Borivets Savely, Yakushev Peter.
// Debuggers: Alexander Galkin, Nikita Skobelev

#include "../../headers/NaturalNumber.h"

// struct start

NaturalNumber::NaturalNumber() { Big_int = new List(); }

NaturalNumber::NaturalNumber(std::string s) {
  Big_int = new List();
  for (int i = s.size() - 1; i >= 0; i--) {
    Big_int->push_back(s[i] - '0');
  }
}

NaturalNumber::NaturalNumber(const NaturalNumber& other) {
  Big_int = new List(other.get_num());
}

NaturalNumber NaturalNumber::operator=(const NaturalNumber& other) {
  Big_int = new List(other.get_num());
  return *this;
}

List& NaturalNumber::get_num() const { return *Big_int; }

void NaturalNumber::clear() {
  Big_int->clear();
  delete Big_int;
}
//architect Nikita Skobelev
// struct end

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
  Compare flag = EQUAL;
  while(n1 != nullptr && n2 != nullptr) {
    if (n1->value > n2->value) { // если первое больше то меняем флаги
      flag = GREATER;
    }
    if (n1->value < n2->value) { // если первое меньше то меняем флаги
      flag = LESS;
    }
    n1 = n1->next;
    n2 = n2->next; // итерируемся на следующий разряд
  }
  if(n1 == nullptr && n2 == nullptr) { // если длины чисел равны
    return flag;
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
        if (next_node->value == 9){
            next_node->value = 0;
            if(next_node->next == nullptr){
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
    Node* cur_node1 = (*this).get_num().get_first();  // Начинаем с нулевого разряда первого слагаемого
    Node* cur_node2 = other.get_num().get_first();  // и с нулевого разряда второго слагаемого

    char cur_digit = 0; // Переменная отвечает за сумму двух текущих разрядов
    while (cur_node1 != nullptr && cur_node2 != nullptr) { // Пока оба разряда существуют
        cur_digit += cur_node1->value + cur_node2->value; // Сумма разрядов
        if (cur_digit >= 10) { // Если сумма выходит за макс. значение разряда
            result.get_num().push_back(cur_digit - 10); // Убираем десяток, который перейдет в следующий разряд
            cur_digit = 1; // В следующий разряд
        } else {
            result.get_num().push_back(cur_digit); // Сумма не вышла за макс. значение
            cur_digit = 0; // Ничего не переходит в следующий разряд
        }
        // Перемещение по разрядам
        cur_node1 = cur_node1->next;
        cur_node2 = cur_node2->next;
    }
    // Оставшиеся разряды с первого слагаемого
    while (cur_node1 != nullptr) {
        if (cur_node1->value + cur_digit >= 10) { // Если значение переполняет
            result.get_num().push_back(0); // Так как переполнение происходит лишь при 9
            cur_digit = 1; // Единица для следующего разряда
        } else { // Если нет переполнения
            result.get_num().push_back(cur_node1->value + cur_digit); // Добавляем разряд от первого числа, учитывая возможную единицу с предыдущего разряда
            cur_digit = 0;
        }
        cur_node1 = cur_node1->next; // Следующий разряд
    }
    // Оставшиеся разряды со второго слагаемого
    while (cur_node2 != nullptr) {
        if (cur_node2->value + cur_digit >= 10) {
            result.get_num().push_back(0);
            cur_digit = 1;
        } else {
            result.get_num().push_back(cur_node2->value + cur_digit);
            cur_digit = 0;
        }
        cur_node2 = cur_node2->next;
    }
    if (cur_digit != 0) { // Если осталась единичка с предыдущих разрядов
        result.get_num().push_back(cur_digit);
    }
    return result;
}

NaturalNumber NaturalNumber::MUL_ND_N(const char c) {
    NaturalNumber result;
    if (!(*this).NZER_N_B() || c == 0) { // Если какой-нибудь множитель равен нулю ответ = 0
        return NaturalNumber("0");
    }
    Node* cur_node = (*this).get_num().get_first();  // Начинаем с первого разряда числа

    char cur_digit = 0; // Здесь сохраняется работа над разрядом(будет принимать значения от 0 до 89)
    while (cur_node != nullptr) {
        cur_digit += cur_node->value * c; // К сохраненным десяткам добавляем перемножение текущего разряда со значением
        result.get_num().push_back(cur_digit - cur_digit / 10 * 10); // Убираем десятки, добавляем новый разряд
        cur_digit /= 10; // Сохраняем десятки
        cur_node = cur_node->next; // Переходим на следующий разряд
    }
    if (cur_digit != 0) { // Если осталась единичка с предыдущих разрядов
        result.get_num().push_back(cur_digit);
    }
    return result;
}

NaturalNumber NaturalNumber::SUB_NN_N(const NaturalNumber& num) {
    NaturalNumber result;
    Node *greater_node;
    Node *lower_node;
    if (*this > num) { // Определяем большее число
      // Начинаем с первых разрядов
      greater_node = (*this).get_num().get_first();
      lower_node = num.get_num().get_first();
    } else {
      greater_node = num.get_num().get_first();
      lower_node = (*this).get_num().get_first();
    }

    int take_one_digit = 0; // Берем единицу из старшего разряда
    int sub_digit_result; // Разница разрядов
    while (lower_node != nullptr) {
        sub_digit_result = greater_node->value - lower_node->value - take_one_digit; // Вычитаем один разряд из другого, учитывая взятие единички для предыдущих разрядов
        if (sub_digit_result < 0) {
            take_one_digit = 1; // Берем единицу
            sub_digit_result += 10; // Добавляем взятую единицу со старших разрядов
        } else {
            take_one_digit = 0; // Не берем единицу
        }
        // Следующий разряд
        greater_node = greater_node->next;
        lower_node = lower_node->next;
        result.get_num().push_back(sub_digit_result); // Добавляем новый разряд
    }
    while (greater_node != nullptr) { // Если у большего числа остались разряды
        sub_digit_result = greater_node->value - take_one_digit; // Учитываем единицу для предыдущих разрядов
        if (sub_digit_result < 0) {
            sub_digit_result += 10; // Снова берем единицу
            take_one_digit = 1;
        } else {
            take_one_digit = 0;
        }
        result.get_num().push_back(sub_digit_result);
        greater_node = greater_node->next;
    }
    result.get_num().del_zero(); // Убираем нули в начале
    return result;
}

NaturalNumber NaturalNumber::MUL_Nk_N(unsigned long long k) {
    NaturalNumber ans = *this;
    if (!ans.NZER_N_B()) { // Если N равно нулю
        return ans;
    }
    for(unsigned long long i = 0; i < k; i++) {
        ans.get_num().push_front(0); // Добавляем нули в количестве k
    }
    return ans;
}

// N-8
NaturalNumber NaturalNumber::MUL_NN_N(const NaturalNumber& other) {
    NaturalNumber result = NaturalNumber("0");
    Node* cur_node = other.Big_int->get_first();
    unsigned long long digit = 0; // Для сдвига разрядов
    while (cur_node != nullptr) { // Пока разряды у второго числа не закончится
        result = result.ADD_NN_N(((*this).MUL_ND_N(cur_node->value)).MUL_Nk_N(digit)); // Домножаем каждую цифру второго числа на первое, делая сдвиг разрядов
        digit++; // Следующий разряд
        cur_node = cur_node->next;
    }
    return result;
}

// N-8 oper "*"
//NaturalNumber NaturalNumber::operator*(const NaturalNumber& other) {
//  return MUL_NN_N(other);
//}
//
//// N-8 oper "*="
//NaturalNumber NaturalNumber::operator*=(const NaturalNumber& other) {
//  (*this) = MUL_NN_N(other);
//  return *this;
//}

// N-9
NaturalNumber NaturalNumber::SUB_NDN_N(NaturalNumber& num, char c) { // Возвращает NN
    NaturalNumber result = *this;
    NaturalNumber sub_val = num.MUL_ND_N(c); // Домножаем число на цифру
    if (result >= sub_val) {
        return result.SUB_NN_N(sub_val); // Вычитаем
    }
    return *this;
}

// N-10
std::pair<char, unsigned long long> NaturalNumber::DIV_NN_Dk(NaturalNumber& num) {
    if (*this < num) { // Если делитель больше - возвращается 0
        return {0, 0};
    }
    NaturalNumber greater_num = (*this);
    NaturalNumber lower_num = num;
    Node *gr_node = greater_num.Big_int->get_first(); // Начинаем с первых разрядов
    Node *lw_node = lower_num.Big_int->get_first();
    unsigned long long k = 0;
    while (gr_node->next != nullptr) { // Пока в большем числе есть разряды
        if (lw_node == nullptr) { // Дополняем нулями меньшее до предпоследнего разряда большего
            lower_num = lower_num.MUL_Nk_N(1);
            k++;
        } else {
            lw_node = lw_node->next;
        }
        gr_node = gr_node->next;
    }
    if (greater_num >= lower_num.MUL_Nk_N(1)) { // Пробуем дополнить до последнего разряда большего, сравниваем
        lower_num = lower_num.MUL_Nk_N(1); // Если меньшее остается меньшим или равным, добавляем еще нуль в начало
        k++;
    }
    char cnt_subs = 0; // Счетчик количества вычитаний(от 0 до 9)
    while (greater_num >= lower_num) {
        greater_num = greater_num.SUB_NN_N(lower_num); // Вычитаем пока большее не стало меньшим
        cnt_subs++; // Добавляем к счетчику вычитание
    }
    return {cnt_subs, k}; // Возвращаем первую цифру и разряд на котором она стоит
}

// N-11
NaturalNumber NaturalNumber::DIV_NN_N(NaturalNumber& num) {
    NaturalNumber divisible_num = *this;
    NaturalNumber result = NaturalNumber("0"); // В эту переменную будем добавлять первые цифры деления
    std::pair<char, unsigned long long> division_result;
    NaturalNumber sub_num;
    while (divisible_num >= num) {
        division_result = divisible_num.DIV_NN_Dk(num); // находим первую цифру деления
        result = result.ADD_NN_N(NaturalNumber(std::to_string(division_result.first)).MUL_Nk_N(division_result.second)); // Добавляем ее на нужный разряд
        sub_num = num.MUL_Nk_N(division_result.second); // дополним нулями делитель до разряда первой цифры
        divisible_num = divisible_num.SUB_NDN_N(sub_num, division_result.first); // Обновляем делимое(вычитаем делитель с доп нулями, умноженный на первую цифру деления)
    }
    return result;
}

// N-11 oper "/"
//NaturalNumber NaturalNumber::operator/(NaturalNumber& other) {
//  return DIV_NN_N(other);
//}
//
//// N-11 oper "/="
//NaturalNumber NaturalNumber::operator/=(NaturalNumber& other) {
//  (*this) = DIV_NN_N(other);
//  return *this;
//}

// N-12
NaturalNumber NaturalNumber::MOD_NN_N(NaturalNumber& num) {
    // Из первого числа вычитаем произведение неполного частного и делителя
    // a = b*q + r -----> r = a - b*q
    NaturalNumber result = (*this).SUB_NN_N(num.MUL_NN_N((*this).DIV_NN_N(num)));
    return result;
}

//// N-12 oper "%="
//NaturalNumber NaturalNumber::operator%(NaturalNumber& other) {
//  return MOD_NN_N(other);
//}
//
//// N-12 oper "%="
//NaturalNumber NaturalNumber::operator%=(NaturalNumber& other) {
//  (*this) = MOD_NN_N(other);
//  return *this;
//}

// N-13
NaturalNumber NaturalNumber::GCF_NN_N(NaturalNumber& arr_num) {
    NaturalNumber greater_num;
    NaturalNumber lower_num;
    if (*this > arr_num) { // Определяем большее и меньшее число
        greater_num = *this;
        lower_num = arr_num;
    } else {
        greater_num = arr_num;
        lower_num = *this;
    }
    NaturalNumber tmp;
    // Находим НОД, находим остаток деления большего на меньшее, меньшее становится результатом этого деления
    // Большее становится предыдущим меньшим, так пока меньшее не станет равным нулю
    while (lower_num.NZER_N_B()) { // Пока меньшее не равно нулю
        tmp = lower_num; // Сохраняем меньшее
        lower_num = greater_num.MOD_NN_N(lower_num); // Находим остаток, сохраняем в меньшем
        greater_num = tmp; // Обновляем большее
    }
    return greater_num;
}

// N-14
NaturalNumber NaturalNumber::LCM_NN_N(NaturalNumber& arr_num) {
    NaturalNumber GCF = (*this).GCF_NN_N(arr_num); // Находим НОД
    // НОД - наименьший общий делитель, значит разделим одно из чисел на НОД, и перемножим со вторым
    // НОК = a*b/НОД
    NaturalNumber LCM = (*this).MUL_NN_N(arr_num.DIV_NN_N(GCF));
    return LCM;
}