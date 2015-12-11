#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;

ArithmeticExpression::ArithmeticExpression() : Expression::Expression(){
    left = NULL;
    right = NULL;
}

ArithmeticExpression::ArithmeticExpression(string s) : Expression::Expression(s){
    left = NULL;
    right = NULL;
}

void ArithmeticExpression::print(){
    if (left != NULL)
        left->print();
    else if (right != NULL)
        right->print();
    else
        cout << exp;
}

void ArithmeticExpression::setLR(string L, string R){
    left = new ArithmeticExpression(L);
    right = new ArithmeticExpression(R);
}

float ArithmeticExpression::convert (string){
    return 0.0f;
}

ArithmeticExpression::~ArithmeticExpression(){
    //delete left;
    //delete right;
}
