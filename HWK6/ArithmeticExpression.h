#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"
#include <string>
#include <stdexcept>

using namespace std;

class Multiply;
class Add;

class ArithmeticExpression : public Expression {

    public:
        ArithmeticExpression *left;
        ArithmeticExpression *right;

        ArithmeticExpression();
        ArithmeticExpression(string);
        virtual string evaluate(); //evaluate left expression and right expression
        virtual void print();
        float convert(string);
        void setLR(string, string);
        virtual ~ArithmeticExpression();
    private:
};
#endif
