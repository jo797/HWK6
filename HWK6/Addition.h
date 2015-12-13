#include "ArithmeticExpression.h"
#include <string>

#ifndef ADDITION_H_
#define ADDITION_H_

using namespace std;

class Addition : public ArithmeticExpression { //Addition class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
    private:
};
#endif
