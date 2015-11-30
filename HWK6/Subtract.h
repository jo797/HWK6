#include "ArithmeticExpression.h"
#include <string>

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

using namespace std;

class Subtract: public ArithmeticExpression{
    public:
        Subtract();
        string evaluate();
        void print();
        virtual ~Subtract();
	private:
};
#endif
