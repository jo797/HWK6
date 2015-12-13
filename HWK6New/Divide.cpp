#include "Divide.h"

string Divide::evaluate(){
    if (ArithmeticExpression::isValue){
        cout << "value" << endl;
        return ArithmeticExpression::curr;
    } else{
        cout << "ech" << endl;
        cout << ArithmeticExpression::right->isValue << endl;
        return "0";
        return ArithmeticExpression::ftosconvert(ArithmeticExpression::convert(ArithmeticExpression::right->evaluate())+ArithmeticExpression::convert(ArithmeticExpression::left->evaluate()));
    }
    return "0";
}

void Divide::print(){
}
