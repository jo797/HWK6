#include "Expression.h"
#include <string>
#include <stdexcept>

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

using namespace std;

class ArithmeticExpression : public Expression {

    public:
        ArithmeticExpression *left;
        ArithmeticExpression *right;

        ArithmeticExpression();
        ArithmeticExpression(string);
        bool parse();
        //string evaluate(); //evaluate left expression and right expression
        void print();
        float convert (string);
        virtual ~ArithmeticExpression();
    private:
        void parseBrackets();
        void parseExpression(string);
        bool checkCharIs(char, string);
};
#endif
