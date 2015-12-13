#include "ArithmeticExpression.h"
#include <string>

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

using namespace std;

class Subtraction: public ArithmeticExpression { //Subtraction class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
	private:
};
#endif
