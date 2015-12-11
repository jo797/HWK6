#include "Add.h"

string Add::evaluate(){
    return "";
}

void Add::print(){
    if (left != NULL && right != NULL){
        cout << "(";
        left->print();
        cout << "+";
        right->print();
        cout << ")";
    } else {
        cout << exp;
    }
}
