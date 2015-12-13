#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"
#include <string>
#include <stdexcept>
#include<sstream>

using namespace std;

class ArithmeticExpression : public Expression {
    public:
        int indexOperator(string, string);
        bool checkOperator();
        string clipEndBrackets(string);

        int operatorIndex = -1;

        Expression *left;
        Expression *right;

        string evaluate();
        void print();
        float convert (string);
        string ftosconvert(float);
        void setExp(string, int);
};
#endif
