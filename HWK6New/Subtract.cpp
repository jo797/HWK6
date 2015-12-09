#include "Subtract.h"

string Subtract::evaluate(){
    if (ArithmeticExpression::isValue){
        return ArithmeticExpression::curr;
    } else {
        return ArithmeticExpression::ftosconvert(ArithmeticExpression::convert(ArithmeticExpression::right->evaluate())-ArithmeticExpression::convert(ArithmeticExpression::left->evaluate()));
    }
}

void Subtract::print(){
}
