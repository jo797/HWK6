#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"

#include <string>
#include <stdexcept>

using namespace std;

class ArithmeticExpression: public Expression{
    Expression *left;
    Expression *right;

    public:
        string evaluate(){};
        void print(){};
        float convert(string){};
};

#endif
