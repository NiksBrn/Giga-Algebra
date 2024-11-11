#include "../../headers/Struct.h"

Node *List::get_first() const { return first; }
Node *List::get_last() const { return last; }


List::List(const List& other) : first(nullptr), last(nullptr){
    Node* node = other.get_first();
    while(node!=nullptr){
        push_back(node->value);
        node = node->next;
    }
}

List& List::operator =(const List& other){
    clear();
    first = nullptr;
    last = nullptr;
    List temp(other);
    Node *node = temp.get_first();
    while(node!=nullptr){
        push_back(node->value);
        node = node->next;
    }
    return *this;
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

void List::del_zero(){
    Node *tmp = first;
    Node *run = first->next;
    while(run!=nullptr){
        if(run->value != 0){
            tmp = run;
        }
        run = run->next;
    }
    last = tmp;
    last->next = nullptr;
    tmp = tmp->next;
    while(tmp!=nullptr){
        Node *tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
}

void List::clear() {
  Node *current = first;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
}
