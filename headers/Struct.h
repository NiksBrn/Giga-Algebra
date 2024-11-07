#ifndef GIGA_ALGEBRA_STRUCT_H
#define GIGA_ALGEBRA_STRUCT_H

struct Node{
    char value;
    Node* next;

    Node(char _value) : value(_value), next(nullptr){};
};

class List{
public:
    List() : first(nullptr), last(nullptr){};
    ~List() = default;
    List(const List& other);
    List& operator =(const List& other);
    void clear();
    void push_back(unsigned char value);
    void push_front(unsigned char value);
    Node* get_first() const;
    Node* get_last() const;
private:
    Node* first;
    Node* last;
};
#endif //GIGA_ALGEBRA_STRUCT_H
