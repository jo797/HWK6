#include "Expression.h"
#include <string>

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

using namespace std;

class ArithmeticExpression : public Expression {
    public:
        //Expression *left;
        //Expression *right;

        ArithmeticExpression();
        string evaluate (); //evaluate left expression and right expression
        void print();
        float convert (string);
        virtual ~ArithmeticExpression();
    private:
};
#endif
