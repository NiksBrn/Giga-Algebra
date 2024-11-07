#ifndef GIGA_ALGEBRA_STRUCTPOLYNOMIAL_H
#define GIGA_ALGEBRA_STRUCTPOLYNOMIAL_H
#include "NaturalNumber.h"
#include "RationalNumber.h"


struct NodePolynomial{
    RationalNumber coefficient;
    NaturalNumber degree;
    NodePolynomial* next;
    NodePolynomial* prev;
    NodePolynomial(RationalNumber coefficient_, NaturalNumber degree_):coefficient(coefficient_),degree(degree_), next(nullptr),prev(nullptr){};
};

class ListPolynomial{
public:
    ListPolynomial();
    NodePolynomial* get_head();
    NodePolynomial* get_tail();
    void push(RationalNumber coefficient, NaturalNumber degree);
    void pop(NodePolynomial* node);
private:
    NodePolynomial *head;
    NodePolynomial* tail;
};
#endif //GIGA_ALGEBRA_STRUCTPOLYNOMIAL_H
