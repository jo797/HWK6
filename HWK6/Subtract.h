#include "ArithmeticExpression.h"
#include <string>

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

using namespace std;

class Subtract: public ArithmeticExpression{
    public:
        string evaluate();
        void print();
	private:
};
#endif
