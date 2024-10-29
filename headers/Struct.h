#ifndef GIGA_ALGEBRA_STRUCT_H
#define GIGA_ALGEBRA_STRUCT_H

struct Node{
    unsigned char value;
    Node* next;

    Node(unsigned char _value) : value(_value), next(nullptr){};
};

struct List{
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr){};
};
#endif //GIGA_ALGEBRA_STRUCT_H
