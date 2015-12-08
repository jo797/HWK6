#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <iostream>

using namespace std;

class Expression {
    public:
        string exp;

        Expression();
        Expression(string);
        string evaluate(); // evaluate expression and return string representation of the result.
        void print(); // prints expression
        virtual bool parse();
        virtual ~Expression();
};
#endif
