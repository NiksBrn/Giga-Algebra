cmake_minimum_required(VERSION 3.28)
project(Giga_Algebra)

set(CMAKE_CXX_STANDARD 17)

add_executable(Giga_Algebra main.cpp
        headers/NaturalNumber.h
        headers/Polynomial.h
        headers/IntegerNumber.h
        headers/RationalNumber.h
        headers/Struct.h
        sources/modules/NaturalNumber.cpp
        sources/modules/Polynomial.cpp
        sources/modules/IntegerNumber.cpp
        sources/modules/RationalNumber.cpp
        sources/struct/Struct.cpp
        sources/struct/NaturalNumber.cpp
        sources/struct/Polynomial.cpp
        sources/struct/IntegerNumber.cpp
        sources/struct/RationalNumber.cpp
        headers/Overload.h
        sources/overload/Overload.cpp
        sources/tmp_modules/first_module_NN.cpp)
