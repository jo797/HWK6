#ifndef MULTIPLY_H_
#define MULTIPLY_H_

#include "ArithmeticExpression.h"
#include <string>

using namespace std;

class Multiply: public ArithmeticExpression{
    public:
        string evaluate();
        void print();
	private:
};
#endif
