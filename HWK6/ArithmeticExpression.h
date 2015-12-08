#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"
#include <string>
#include <stdexcept>

using namespace std;

class Multiply;
class Divide;
class Add;
class Subtract;

class ArithmeticExpression : public Expression {

    public:
        Expression *left;
        Expression *right;

        ArithmeticExpression();
        ArithmeticExpression(string);
        bool parse();
        //string evaluate(); //evaluate left expression and right expression
        void print();
        float convert (string);
        virtual ~ArithmeticExpression();
    private:
        void parseBrackets();
        void parseExpression(char);
        bool checkCharIs(char, string);
};
#endif
