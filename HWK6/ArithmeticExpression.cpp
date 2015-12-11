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

string ArithmeticExpression::evaluate(){
    if (left != NULL)
        return left->evaluate();
    else if (right != NULL)
        return right->evaluate();
    else
        return exp;
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

float ArithmeticExpression::convert (string s){
    return stof(s, nullptr);
}

ArithmeticExpression::~ArithmeticExpression(){
    //delete left;
    //delete right;
}
