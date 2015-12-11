#ifndef MULTIPLY_H_
#define MULTIPLY_H_

#include "ArithmeticExpression.h"
#include <string>

using namespace std;

class Multiply: public ArithmeticExpression{
    public:
        string evaluate() override;
        void print() override;
	private:
};
#endif
