#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"

#include <string>
#include <stdexcept>

#define FLOATERRMSG "Can't convert expression to float"

using namespace std;

class ArithmeticExpression : public Expression { //Arithmetic Expression class, child of Expression, parent of Addition, Subtraction, Multiplication, Division

    public:
        ArithmeticExpression *left; //Left pointer to branch of the ArithmeticExpression tree
        ArithmeticExpression *right; //Right pointer to branch of the ArithmeticExpression tree

        ArithmeticExpression(); //Constructor
        ArithmeticExpression(string); //Constructor
        virtual string evaluate(); //Recursively evaluate left expression and right expression
        virtual void print(); //Recursively print the expression with the added brackets
        virtual void increment(); //Recursively increment the expression
        float convert(string); //Function to convert from string to float
        void setLR(string, string); //Method to create the left and right branches based on the given strings
        virtual ~ArithmeticExpression(); //Destructor
    private:
};
#endif
