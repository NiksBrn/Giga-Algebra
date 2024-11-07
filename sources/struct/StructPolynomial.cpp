#include "../../headers/StructPolynomial.h"

ListPolynomial::ListPolynomial(){
    head = nullptr;
    tail = nullptr;
}

void ListPolynomial::push(RationalNumber coefficient, NaturalNumber degree) {
    NodePolynomial* node = new NodePolynomial(coefficient, degree);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        bool flag = true;
        NodePolynomial* tmp = head;
        while (tmp != nullptr) {
            if(tmp->degree.COM_NN_D(node->degree) == LESS){
                if(tmp == head){
                    node->next = tmp;
                    tmp->prev = node;
                    head = node;
                }else{
                    node->next = tmp;
                    tmp->prev->next = node;
                    node->prev = tmp->prev;
                    tmp->prev = node;
                }
                flag = false;
                break;
            }
            tmp = tmp->next;
        }
        if(flag){
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
}

void ListPolynomial::pop(NodePolynomial *node) {
    NodePolynomial* tmp = node;
    if (node == head){
        head = head->next;
        head->prev = nullptr;
        delete tmp;
    }
    else if (node == tail){
        tail = tail->prev;
        tail->next = nullptr;
        delete tmp;
    }else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
}

NodePolynomial* ListPolynomial::get_head(){
    return head;
}

NodePolynomial* ListPolynomial::get_tail(){
    return tail;
}
