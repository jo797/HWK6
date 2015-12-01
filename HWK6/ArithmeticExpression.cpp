#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;

ArithmeticExpression::ArithmeticExpression() : Expression::Expression(){

}

string ArithmeticExpression::evaluate (){//evaluate left expression and right expression

}

void ArithmeticExpression::print(){

}

float ArithmeticExpression::convert (string){

}

ArithmeticExpression::~ArithmeticExpression(){
    delete left;
    delete right;
}
