FORMS += \
    mainwindow.ui

SOURCES += \
    ../../sources/modules/IntegerNumber.cpp         \
    ../../sources/modules/NaturalNumber.cpp         \
    ../../sources/modules/RationalNumber.cpp        \
    ../../sources/modules/Polynomial.cpp            \
    ../../sources/overload/Overload.cpp             \
    ../../sources/struct/Struct.cpp                 \
    main.cpp                                        \
    mainwindow.cpp                                  \
    ../../sources/struct/StructPolynomial.cpp

HEADERS += \
    ../../headers/IntegerNumber.h                   \
    ../../headers/NaturalNumber.h                   \
    ../../headers/RationalNumber.h                  \
    ../../headers/Polynomial.h                      \
    ../../headers/Overload.h                        \
    ../../headers/Struct.h                          \
    mainwindow.h                                    \
    ../../headers/StructPolynomial.h

QT += widgets
