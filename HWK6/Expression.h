#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <iostream>

using namespace std;

class Expression {
    public:
        string exp;

        Expression(); //Constructor
        Expression(string); //Constructor
        virtual string evaluate() = 0; //Pure virtual function to evaluate expression and return a string representation of the result
        virtual void print() = 0; //Pure virtual function for printing expressions
        virtual ~Expression(); //Destructor
};
#endif
