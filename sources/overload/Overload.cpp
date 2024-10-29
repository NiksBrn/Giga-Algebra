#include "../../headers/overload.h"


std::ostream& operator << (std::ostream &os,const NaturalNumber &num){
    std::string str;
    Node* tmp = num.get_num().get_first();
    while(tmp != nullptr){
        str += std::to_string(tmp->value);
        tmp = tmp->next;
    }
    reverse(str.begin(), str.end());
    return os << str;
}