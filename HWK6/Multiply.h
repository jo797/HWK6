#ifndef MULTIPLY_H_
#define MULTIPLY_H_

#include "ArithmeticExpression.h"
#include <string>

using namespace std;

class Multiply: public ArithmeticExpression { //Multiplication class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
	private:
};
#endif
