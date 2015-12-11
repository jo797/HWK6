#include "Subtract.h"

string Subtract::evaluate(){
    if (left != NULL && right != NULL){
        return to_string(convert(left->evaluate()) - convert(right->evaluate()));
    } else {
        return exp;
    }
}

void Subtract::print(){
    if (left != NULL && right != NULL){
        cout << "(";
        if (left->exp != "0")
            left->print();
        cout << "-";
        right->print();
        cout << ")";
    } else {
        cout << exp;
    }
}
