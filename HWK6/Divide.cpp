#include "Divide.h"

string Divide::evaluate(){
    if (left != NULL && right != NULL){
        return to_string(convert(left->evaluate()) / convert(right->evaluate()));
    } else {
        return exp;
    }
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
