// project Giga-Algebra
// Developers: Zlobin Ivan.
// Debuggers: Nikita Skobelev

#include "../../headers/IntegerNumber.h"


//struct start

const NaturalNumber& IntegerNumber::get_num() const{
    return *number;
}

IntegerNumber::IntegerNumber(char sign, std::string s) {
    // если знак = -, то поле примет значение true
    isNegative = sign == '-' ? true : false;
    // инициализация поля цифр числа
    number = new NaturalNumber(s);
}

// конструктор целого числа из натурального
IntegerNumber::IntegerNumber(const NaturalNumber &n) {
    isNegative = false;
    number = new NaturalNumber(n);
};

// конструктор копирование
IntegerNumber::IntegerNumber(const IntegerNumber &other) {
    isNegative = other.isNegative;
    number = new NaturalNumber(*other.number);
}

// переопределение опрератора копирования
IntegerNumber &IntegerNumber::operator=(const IntegerNumber &other) {
    number = new NaturalNumber(*other.number);
    isNegative = other.isNegative;
    return *this;
}
//architect Nikita Skobelev
//struct end

NaturalNumber &IntegerNumber::ABS_Z_Z() { return *number; }

Sign IntegerNumber::POZ_Z_D() const {
    // если число равно нулю, возвращаем enum Sign::ZERO
    if (*number == NaturalNumber("0")) return Sign::ZERO;
    // если поле isNegative равно true, возвращаем enum Sign::NEGATIVE
    // иначе возвращаем enum Sign::POSITIVE
    return isNegative ? Sign::NEGATIVE : Sign::POSITIVE;
}

IntegerNumber &IntegerNumber::MUL_ZM_Z() {
    // инвертирование значения поля isNegative
    this->isNegative = !this->isNegative;
    return *this;
}

IntegerNumber IntegerNumber::TRANS_N_Z(const NaturalNumber &n) {
    return IntegerNumber(n);
}

NaturalNumber IntegerNumber::TRANS_Z_N(const IntegerNumber &n) {
    return *n.number;
}

IntegerNumber IntegerNumber::ADD_ZZ_Z(const IntegerNumber &other) {
    // создаем 3 число, куда запишем результат
    IntegerNumber object = *this;
    // получаем модуль первого числа
    NaturalNumber number = ABS_Z_Z();
    // полуаем модуль второго числа, const_cast для приведения типов
    NaturalNumber other_number = const_cast<IntegerNumber &>(other).ABS_Z_Z();
    if (POZ_Z_D() == other.POZ_Z_D()) {  // если знаки равны
        *object.number = number.ADD_NN_N(other_number);  // просто складываем числа
        return object;
    }
    // если знаки не равны, сложение чисел превращается в вычитание
    // из большего числа меньшее, при этом знак получившегося числа
    // будет таким же, как у большего по модулю
    if (number.COM_NN_D(other_number) == Compare::LESS) {  // сравниваем числа
        *object.number =
                other_number.SUB_NN_N(number);  // вычитаем из второго первое
        object.MUL_ZM_Z(); // смена знака
    } else {
        *object.number =
                number.SUB_NN_N(other_number);  // вычитаем из первого второе
    }
    return object;  // возвращаем третье число
}

// переопределение оператора сложения
IntegerNumber IntegerNumber::operator+(const IntegerNumber &other) {
    return ADD_ZZ_Z(other);
}

// переопределение оператора +=
IntegerNumber &IntegerNumber::operator+=(const IntegerNumber &other) {
    *this = ADD_ZZ_Z(other);
    return *this;
}

IntegerNumber IntegerNumber::SUB_ZZ_Z(const IntegerNumber &other) {
    IntegerNumber object = other;
    // при вычитании целых чисел
    // можно поменять знак у вычитаемого
    // и сложить эти числа
    object.MUL_ZM_Z();  // смена знака
    return ADD_ZZ_Z(object);
}

// переопределение оператора вычитания
IntegerNumber IntegerNumber::operator-(const IntegerNumber &other) {
    return SUB_ZZ_Z(other);
}

// переопределение оператора -=
IntegerNumber &IntegerNumber::operator-=(const IntegerNumber &other) {
    *this = SUB_ZZ_Z(other);
    return *this;
}

IntegerNumber IntegerNumber::MUL_ZZ_Z(const IntegerNumber &other) {
    // создаем 3 число, куда запишем результат
    IntegerNumber object = *this;
    // получаем модуль первого числа
    NaturalNumber number = ABS_Z_Z();
    // полуаем модуль второго числа, const_cast для приведения типов
    NaturalNumber other_number = const_cast<IntegerNumber &>(other).ABS_Z_Z();
    // перемножаем модули чисел
    *object.number = number.MUL_NN_N(other_number);
    // выбор правильного знака
    // при умножении на отрицательное число
    // знак результата будет противоположным
    if (other.POZ_Z_D() == Sign::NEGATIVE) {
        object.MUL_ZM_Z();
    }
    return object;
}

// переопределение оператора *
IntegerNumber IntegerNumber::operator*(const IntegerNumber &other) {
    return MUL_ZZ_Z(other);
}

// переопределение оператора *=
IntegerNumber &IntegerNumber::operator*=(const IntegerNumber &other) {
    *this = MUL_ZZ_Z(other);
    return *this;
}

IntegerNumber IntegerNumber::DIV_ZZ_Z(const IntegerNumber &other) {
    // создание 3 числа для записи результата
    IntegerNumber object = *this;
    // получение модуля первого числа
    NaturalNumber number = ABS_Z_Z();
    // полуаем модуль второго числа, const_cast для приведения типов
    NaturalNumber other_number = const_cast<IntegerNumber &>(other).ABS_Z_Z();
    // случай для отрицательного делимого
    if (POZ_Z_D() == Sign::NEGATIVE) {
        NaturalNumber quotient = number.DIV_NN_N(other_number);
        if (number != quotient.MUL_NN_N(other_number)) {
            quotient = quotient.ADD_1N_N();
        }
        *object.number = quotient;
        // установка корректного знака
        // при делении на отрицательное число
        // знак результата будет противоположным
        if (other.POZ_Z_D() == Sign::NEGATIVE) {
            object.MUL_ZM_Z();
        }
        return object;
    }
    *object.number = number.DIV_NN_N(other_number);
    // установка корректного знака
    // при делении на отрицательное число
    // знак результата будет противоположным
    if (other.POZ_Z_D() == Sign::NEGATIVE) {
        object.MUL_ZM_Z();
    }
    return object;
}

// переопределение оператора деления
IntegerNumber IntegerNumber::operator/(const IntegerNumber &other) {
    return DIV_ZZ_Z(other);
}

// переопределение оператора /=
IntegerNumber &IntegerNumber::operator/=(const IntegerNumber &other) {
    *this = DIV_ZZ_Z(other);
    return *this;
}

IntegerNumber IntegerNumber::MOD_ZZ_Z(const IntegerNumber &other) {
    // получение частного от деления
    const IntegerNumber denominator = DIV_ZZ_Z(other);
    // получения неполного делимого, const_cast для приведения типов
    auto half_enominator =
            const_cast<IntegerNumber &>(other).MUL_ZZ_Z(denominator);
    // расчет остатка от деления
    auto object = this->SUB_ZZ_Z(half_enominator);
    // смена знака, если модуль отрицательный
    if (object.POZ_Z_D() == Sign::NEGATIVE) {
        object = object.MUL_ZM_Z();
    }
    return object;
}

// переопределение оператора взятия остатка
IntegerNumber IntegerNumber::operator%(const IntegerNumber &other) {
    return MOD_ZZ_Z(other);
}

// переопределение оператора %=
IntegerNumber &IntegerNumber::operator%=(const IntegerNumber &other) {
    *this = MOD_ZZ_Z(other);
    return *this;
}