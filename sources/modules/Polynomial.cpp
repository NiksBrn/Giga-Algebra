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
    std::vector<Term> terms;
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