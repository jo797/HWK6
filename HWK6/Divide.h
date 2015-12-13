#include "ArithmeticExpression.h"
#include <string>

#ifndef DIVIDE_H_
#define DIVIDE_H_

using namespace std;

class Divide: public ArithmeticExpression { //Division class, child of ArithmeticExpression
    public:
        string evaluate() override; //Override the evaluate function from Arithmetic Expression
        void print() override; //Override the print function from Arithmetic Expression
    private:
};
#endif
