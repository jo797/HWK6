#include "Divide.h"

string Divide::evaluate(){
    return "";
}

void Divide::print(){
    if (left != NULL && right != NULL){
        cout << "(";
        left->print();
        cout << "/";
        right->print();
        cout << ")";
    } else {
        cout << exp;
    }
}
