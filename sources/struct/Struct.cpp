#include "../../headers/Struct.h"

Node* List::get_first() const{
    return first;
}
Node *List::get_last() const{
    return last;
}

void List::push_back(unsigned char value) {
    Node *new_node = new Node(value);
    if (first == nullptr) {
        first = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
}

void List::push_front(unsigned char value) {
    Node *new_node = new Node(value);
    if (first == nullptr) {
        first = new_node;
        last = new_node;
    } else {
        new_node->next = first;
        first = new_node;
    }
}

void List::clear(){
    Node *current = first;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}