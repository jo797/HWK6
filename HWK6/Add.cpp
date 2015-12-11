#include "Add.h"

string Add::evaluate(){
    if (left != NULL && right != NULL){
        return to_string(convert(left->evaluate()) + convert(right->evaluate()));
    } else {
        return exp;
    }
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
