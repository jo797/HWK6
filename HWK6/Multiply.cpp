#include "Multiply.h"

string Multiply::evaluate(){
    if (left != NULL && right != NULL){
        return to_string(convert(left->evaluate()) * convert(right->evaluate()));
    } else {
        return exp;
    }
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
