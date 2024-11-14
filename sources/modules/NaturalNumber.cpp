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
  Big_int->del_zero();
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
        if (cur_node1->value + cur_digit >= 10) {
            result.get_num().push_back(0);
            cur_digit = 1;
        } else {
            result.get_num().push_back(cur_node1->value + cur_digit);
            cur_digit = 0;
        }
        cur_node1 = cur_node1->next;
    }
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
    NaturalNumber result;
    Node *greater_node;
    Node *lower_node;
    if (*this > num) {
        greater_node = (*this).get_num().get_first();  // отвечает за сдвиг на следующий разряд первого числа
        lower_node = num.get_num().get_first();  // отвечает за сдвиг на следующий разряд второго числа
    } else {
        greater_node = num.get_num().get_first();  // отвечает за сдвиг на следующий разряд первого числа
        lower_node = (*this).get_num().get_first();  // отвечает за сдвиг на следующий разряд второго числа
    }

    int take_one_digit = 0; // Берем единицу из старшего разряда
    int sub_digit_result; // Разница разрядов
    while (lower_node != nullptr) {
        sub_digit_result = greater_node->value - lower_node->value - take_one_digit;
        if (sub_digit_result < 0) {
            take_one_digit = 1;
            sub_digit_result += 10;
        } else {
            take_one_digit = 0;
        }
        greater_node = greater_node->next;
        lower_node = lower_node->next;
        result.get_num().push_back(sub_digit_result);
    }
    while (greater_node != nullptr) {
        sub_digit_result = greater_node->value - take_one_digit;
        if (sub_digit_result < 0) {
            sub_digit_result += 10;
            take_one_digit = 1;
        } else {
            take_one_digit = 0;
        }
        result.get_num().push_back(sub_digit_result);
        greater_node = greater_node->next;
    }
    result.get_num().del_zero();
    return result;
}

NaturalNumber NaturalNumber::MUL_Nk_N(unsigned long long k) {
    NaturalNumber ans = *this;
    if (!ans.NZER_N_B()) {
        return ans;
    }
    for(unsigned long long i = 0; i < k; i++) {
        ans.get_num().push_front(0);
    }
    return ans;
}

// N-8
NaturalNumber NaturalNumber::MUL_NN_N(const NaturalNumber& other) {
    NaturalNumber result = NaturalNumber("0");
    Node* cur_node = other.Big_int->get_first();
    unsigned long long digit = 0;
    while (cur_node != nullptr) {
        result = result.ADD_NN_N(((*this).MUL_ND_N(cur_node->value)).MUL_Nk_N(digit));
        digit++;
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
    NaturalNumber sub_val = num.MUL_ND_N(c);
    if (result >= sub_val) {
        return result.SUB_NN_N(sub_val);
    }
    return *this;
}

// N-10
std::pair<char, unsigned long long> NaturalNumber::DIV_NN_Dk(NaturalNumber& num) {
    if (*this < num) {
        return {0, 0};
    }
    NaturalNumber greater_num = (*this);
    NaturalNumber lower_num = num;
    Node *gr_node = greater_num.Big_int->get_first();
    Node *lw_node = lower_num.Big_int->get_first();
    unsigned long long k = 0;
    while (gr_node->next != nullptr) {
        if (lw_node == nullptr) {
            lower_num = lower_num.MUL_Nk_N(1);
            k++;
        } else {
            lw_node = lw_node->next;
        }
        gr_node = gr_node->next;
    }
    if (greater_num >= lower_num.MUL_Nk_N(1)) {
        lower_num = lower_num.MUL_Nk_N(1);
        k++;
    }
    char cnt_subs = 0;
    while (greater_num >= lower_num) {
        greater_num = greater_num.SUB_NN_N(lower_num);
        greater_num.get_num().del_zero();
        cnt_subs++;
    }
    return {cnt_subs, k};
}

// N-11
NaturalNumber NaturalNumber::DIV_NN_N(NaturalNumber& num) {
    NaturalNumber divisible_num = *this;
    NaturalNumber result = NaturalNumber("0");
    std::pair<char, unsigned long long> division_result;
    NaturalNumber sub_num;
    while (divisible_num >= num) {
        division_result = divisible_num.DIV_NN_Dk(num);
        result = result.ADD_NN_N(NaturalNumber(std::to_string(division_result.first)).MUL_Nk_N(division_result.second));
        sub_num = num.MUL_Nk_N(division_result.second);
        divisible_num = divisible_num.SUB_NDN_N(sub_num, division_result.first);
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
    if (*this > arr_num) {
        greater_num = *this;
        lower_num = arr_num;
    } else {
        greater_num = arr_num;
        lower_num = *this;
    }
    NaturalNumber tmp;
    while (lower_num.NZER_N_B()) {
        tmp = lower_num;
        lower_num = greater_num.MOD_NN_N(lower_num);
        greater_num = tmp;
    }
    return greater_num;
}

// N-14
NaturalNumber NaturalNumber::LCM_NN_N(NaturalNumber& arr_num) {
    NaturalNumber GCF = (*this).GCF_NN_N(arr_num);
    NaturalNumber LCM = (*this).MUL_NN_N(arr_num.DIV_NN_N(GCF));
    return LCM;
}
