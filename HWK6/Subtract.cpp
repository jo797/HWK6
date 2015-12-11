#include "Subtract.h"

string Subtract::evaluate(){
    return "";
}

void Subtract::print(){
    if (left != NULL && right != NULL){
        cout << "(";
        left->print();
        cout << "-";
        right->print();
        cout << ")";
    } else {
        cout << exp;
    }
}
