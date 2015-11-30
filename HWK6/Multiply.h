#include "ArithmeticExpression.h"
#include <string>

#ifndef MULTIPLY_H_
#define MULTIPLY_H_

using namespace std;

class Multiply: public ArithmeticExpression{
    public:
        Multiply();
        string evaluate();
        void print();
        virtual ~Multiply();
	private:
};
#endif
