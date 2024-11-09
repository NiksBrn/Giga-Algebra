#ifndef GIGA_ALGEBRA_OVERLOAD_H
#define GIGA_ALGEBRA_OVERLOAD_H

#include <iostream>
#include <fstream>

#include "IntegerNumber.h"
#include "NaturalNumber.h"
#include "Polynomial.h"
#include "RationalNumber.h"

std::ostream &operator<<(std::ostream &os, const NaturalNumber &num);

std::ostream &operator<<(std::ostream &os, const IntegerNumber &num);

std::ostream &operator<<(std::ostream &os, const RationalNumber &num);

std::ostream &operator<<(std::ostream &os, const Polynomial &num);

void WriteMD(const Polynomial &num);
#endif  // GIGA_ALGEBRA_OVERLOAD_H
