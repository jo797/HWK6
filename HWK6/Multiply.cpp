#include "Multiply.h"

string Multiply::evaluate(){
    return "";
}

void Multiply::print(){
    if (left != NULL && right != NULL){
        cout << "(";
        left->print();
        cout << "*";
        right->print();
        cout << ")";
    } else {
        cout << exp;
    }
}
