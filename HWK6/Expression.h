#include <string>
#include <iostream>

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

using namespace std;

class Expression {
    public:
        string exp;

        Expression(string);
        string evaluate(); // evaluate expression and return string representation of the result.
        void print(); // prints expression
        virtual ~Expression();
};
#endif
