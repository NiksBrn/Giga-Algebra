// project Giga-Algebra
// Developers:
// Debuggers: Alexander Galkin, Nikita Skobelev

#include "../../headers/Polynomial.h"

Polynomial::Polynomial(std::string poly) {
    polynomial = new ListPolynomial;
    parsePolynomial(poly);
}

Polynomial::Polynomial(const Polynomial& other){
    polynomial = new ListPolynomial(*other.polynomial);
}
Polynomial& Polynomial::operator=(const Polynomial& other){
    polynomial = new ListPolynomial(*other.polynomial);
    return *this;
}

Polynomial::Polynomial(ListPolynomial* poly){
    polynomial = poly;
}

void Polynomial::parsePolynomial(std::string poly) {
    std::regex term_regex(R"(([+-]?)\s*(\d*)(?:/(\d+))?\s*x(?:\^(\d+))?|([+-]?)\s*(\d+)(?:/(\d+))?)");
    auto terms_begin = std::sregex_iterator(poly.begin(), poly.end(), term_regex);
    auto terms_end = std::sregex_iterator();

    for (std::sregex_iterator i = terms_begin; i != terms_end; ++i) {
        std::smatch match = *i;

        // Инициализируем переменные для знака, числителя, знаменателя и степени
        char sign = match[1].str().empty() ? '+' : match[1].str()[0];
        std::string numerator = match[2].str().empty() ? "1" : match[2].str(); // Если числитель отсутствует, считаем его равным "1"
        std::string denominator = match[3].matched ? match[3].str() : "1";     // Если знаменатель отсутствует, считаем его равным "1"
        std::string exponent = match[4].matched ? match[4].str() : "1";        // Если степень не указана, считаем ее "1"

        if (match[5].matched) { // Константный член, считаем его x^0
            sign = match[5].str().empty() ? '+' : match[5].str()[0];
            numerator = match[6].str();
            denominator = match[7].matched ? match[7].str() : "1";
            exponent = "0"; // Константа всегда имеет степень 0
        }
        polynomial->push(RationalNumber(sign, numerator, denominator), NaturalNumber(exponent));
    }
}

ListPolynomial &Polynomial::getPolynomial() const{
    return *polynomial;
}

// Сложение многочленов
Polynomial Polynomial::ADD_PP_P(const Polynomial& other) {
    ListPolynomial* newPol = new ListPolynomial();
    NodePolynomial* tmp1 = polynomial->get_tail();
    NodePolynomial* tmp2 = other.polynomial->get_tail();
    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->degree == tmp2->degree) {
            newPol->push(tmp1->coefficient.ADD_QQ_Q(tmp2->coefficient), tmp1->degree);
        } else {
            newPol->push(tmp1->coefficient, tmp1->degree);
            newPol->push(tmp2->coefficient, tmp2->degree);
        }
        tmp1 = tmp1->prev;
        tmp2 = tmp2->prev;
    }
    while (tmp1 != nullptr) {
        newPol->push(tmp1->coefficient, tmp1->degree);
        tmp1 = tmp1->prev;
    }
    while (tmp2 != nullptr) {
        newPol->push(tmp2->coefficient, tmp2->degree);
        tmp2 = tmp2->prev;
    }
    Polynomial newPolynomial(newPol);
    newPolynomial.polynomial->balance();
    return newPolynomial;
}

// Вычитание многочленов
Polynomial Polynomial::SUB_PP_P(const Polynomial& other) {
    ListPolynomial* newPol = new ListPolynomial();
    NodePolynomial* tmp1 = polynomial->get_tail();
    NodePolynomial* tmp2 = other.polynomial->get_tail();
    RationalNumber reverse('-', "1", "1");
    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->degree == tmp2->degree) {
            newPol->push(tmp1->coefficient.SUB_QQ_Q(tmp2->coefficient), tmp1->degree);
        } else {
            // auto neg_coeff1 = tmp1->coefficient.MUL_QQ_Q(reverse);
            newPol->push(tmp1->coefficient, tmp1->degree);
            newPol->push(tmp2->coefficient.MUL_QQ_Q(reverse), tmp2->degree);
        }
        tmp1 = tmp1->prev;
        tmp2 = tmp2->prev;
    }
    while (tmp1 != nullptr) {
        newPol->push(tmp1->coefficient, tmp1->degree);
        tmp1 = tmp1->prev;
    }
    while (tmp2 != nullptr) {
        newPol->push(tmp2->coefficient.MUL_QQ_Q(reverse), tmp2->degree);
        tmp2 = tmp2->prev;
    }
    Polynomial newPolynomial(newPol);
    newPolynomial.polynomial->balance();
    return newPolynomial;
}

// Умножение многочлена на рациональное число
Polynomial Polynomial::MUL_PQ_P(const RationalNumber& other) {
    ListPolynomial* newPol = new ListPolynomial();
    NodePolynomial* tmp = polynomial->get_tail();
    while (tmp != nullptr) {
        newPol->push(tmp->coefficient.MUL_QQ_Q((RationalNumber&)other),
                     tmp->degree);
        tmp = tmp->prev;
    }
    Polynomial newPolynomial(newPol);
    newPolynomial.polynomial->balance();
    return newPolynomial;
}

// Умножение многочлена на x^k, k-натуральное или 0
Polynomial Polynomial::MUL_Pxk_P(const NaturalNumber& other) {
    ListPolynomial* newPol = new ListPolynomial();
    NodePolynomial* tmp = polynomial->get_tail();
    while (tmp != nullptr) {
        newPol->push(tmp->coefficient, tmp->degree.ADD_NN_N(other));
        tmp = tmp->prev;
    }
    Polynomial newPolynomial(newPol);
    newPolynomial.polynomial->balance();
    return newPolynomial;
}

// Старший коэффициент многочлена
RationalNumber Polynomial::LED_P_Q() {
    NodePolynomial* tmp = polynomial->get_head();
    return tmp->coefficient;
}

// Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
RationalNumber Polynomial::FAC_P_Q() {
    NodePolynomial* tmp = polynomial->get_tail();
    NaturalNumber nok("1");
    NaturalNumber nod("1");
    if (tmp != nullptr) {
        nok = tmp->coefficient.getDenominator();
        nod = tmp->coefficient.getNumerator().ABS_Z_Z();
        tmp = tmp->prev;
    }
    while (tmp != nullptr) {
        nok = tmp->coefficient.getDenominator().LCM_NN_N(nok);
        nod = tmp->coefficient.getNumerator().ABS_Z_Z().GCF_NN_N(nod);
        tmp = tmp->prev;
    }
    IntegerNumber nok_i(nok);
    RationalNumber answer(nok_i, nod);
    return answer;
}

// Производная многочлена
Polynomial Polynomial::DER_P_P() {
    ListPolynomial* newPol = new ListPolynomial();
    RationalNumber k('+', "0", "1");
    NodePolynomial* tmp = polynomial->get_tail();
    while (tmp != nullptr) {
        if (tmp->degree.COM_NN_D(NaturalNumber("0")) == Compare::EQUAL) {
            tmp = tmp->prev;
            continue;
        }
        k = RationalNumber(IntegerNumber(tmp->degree), NaturalNumber("1"));
        newPol->push(tmp->coefficient.MUL_QQ_Q(k),
                     tmp->degree.SUB_NN_N(NaturalNumber("1")));
        tmp = tmp->prev;
    }
    Polynomial newPolynomial(newPol);
    newPolynomial.polynomial->balance();
    return newPolynomial;
}

// Частное от деления многочлена на многочлен при делении с остатком
Polynomial Polynomial::DIV_PP_P(const Polynomial& other) {
    ListPolynomial* object = new ListPolynomial();
    Polynomial temp_poly = *this;
    Polynomial temp_other = other;
    NodePolynomial* poly = temp_poly.polynomial->get_head();
    NaturalNumber maxDegree = temp_other.polynomial->get_head()->degree;
    RationalNumber coefficient_poly =
            temp_other.polynomial->get_head()->coefficient;
    // пока полином существует и пока его можно поделить
    while (poly != nullptr && poly->degree.COM_NN_D(maxDegree) != Compare::LESS) {
        // получение степени
        NaturalNumber degree = poly->degree.SUB_NN_N(maxDegree);
        // получение коэффициента
        RationalNumber coefficient = poly->coefficient.DIV_QQ_Q(coefficient_poly);
        // добалвение монома в полином
        object->push(coefficient, degree);
        // вычитание из делимого делителя, умноженного на моном
        temp_poly =
                temp_poly.SUB_PP_P(temp_other.MUL_PQ_P(coefficient).MUL_Pxk_P(degree));
        poly = temp_poly.polynomial->get_head();
    }
    // если цикл ни разу не сработал
    if (poly == polynomial->get_head()) {
        object->push(RationalNumber(IntegerNumber('+', "0")), NaturalNumber("0"));
    }
    return Polynomial(object);
}

// Преобразование многочлена — кратные корни в простые
Polynomial Polynomial::NMR_P_P() {
    Polynomial Der = (*this).DER_P_P();  // Производная многочлена
    Polynomial GCF = (*this).GCF_PP_P(Der);  // НОД многочлена
    Polynomial NMR = *this;
    if (!(GCF.DEG_P_N() == NaturalNumber("0")) ||
        !(GCF.polynomial->get_tail()->coefficient.Trans_Q_Z().POZ_Z_D() ==
          ZERO)) {
        NMR = (*this).DIV_PP_P(GCF);
    } else {
        NMR = GCF;
    }
    return NMR;
}

// Умножение многочленов
Polynomial Polynomial::MUL_PP_P(const Polynomial& other) {
    NodePolynomial* tmp = other.polynomial->get_head();
    ListPolynomial* newPol = new ListPolynomial();
    newPol->push(RationalNumber('+', "0", "1"), NaturalNumber("0"));
    Polynomial poly(newPol);
    Polynomial copy = *this;
    while (tmp != nullptr) {
        Polynomial mul = copy.MUL_PQ_P(tmp->coefficient).MUL_Pxk_P(tmp->degree);
        poly = poly.ADD_PP_P(mul);
        tmp = tmp->next;
    }
    poly.polynomial->balance();
    return poly;
}





// Остаток от деление многочлена на многочлен при делении с остатком
Polynomial Polynomial::MOD_PP_P(const Polynomial &other) {
    Polynomial MOD = (*this).DIV_PP_P(other);
    Polynomial ans = (*this).SUB_PP_P(MOD.MUL_PP_P(other));
    return ans;
}

// НОД многочленов
Polynomial Polynomial::GCF_PP_P(const Polynomial& other) {
    Polynomial A = (*this);
    Polynomial B = other;
    Polynomial tmp("1");
    NaturalNumber deg_stop("0");
    while(B.getPolynomial().get_head() != nullptr && deg_stop.COM_NN_D(B.DEG_P_N()) != EQUAL){
        tmp = A;
        A = B;
        B = tmp.MOD_PP_P(B);
    }
    return A;
}