#ifndef GIGA_ALGEBRA_STRUCT_H
#define GIGA_ALGEBRA_STRUCT_H

struct Node{
    char value;
    Node* next;

    Node(char _value) : value(_value), next(nullptr){};
};

class List{
public:
    List() : first(nullptr), last(nullptr), size(0){};
    ~List() = default;
    void clear();
    void push_back(unsigned char value);
    void push_front(unsigned char value);
    Node* get_first() const;
    Node* get_last() const;
    long long get_size() const;
private:
    Node* first;
    Node* last;
    long long size;
};
#endif //GIGA_ALGEBRA_STRUCT_H
