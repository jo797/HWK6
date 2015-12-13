#include "ArithmeticExpression.h"
#include <string>

#ifndef DIVISION_H_
#define DIVISION_H_

using namespace std;

class Division: public ArithmeticExpression { //Division class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
    private:
};
#endif
