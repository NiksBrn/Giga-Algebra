cmake_minimum_required(VERSION 3.28)
project(Giga_Algebra)

set(CMAKE_CXX_STANDARD 17)

add_executable(Giga_Algebra main.cpp
        headers/NaturalNumber.h
        headers/Struct.h
        sources/modules/NaturalNumber.cpp
        sources/struct/Struct.cpp
        headers/Overload.h
        sources/overload/Overload.cpp
        sources/struct/NaturalNumber.cpp
        sources/tmp_modules/first_module_NN.cpp)
