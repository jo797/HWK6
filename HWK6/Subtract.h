#include "ArithmeticExpression.h"
#include <string>

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

using namespace std;

class Subtract: public ArithmeticExpression { //Subtraction class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
	private:
};
#endif
