
#include <string>

using namespace std;

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

class ArithmeticExpression : public Expression{
	Expression *left;
	Expression *right;
	string evaluate (){ //evaluate left expression and right expression
	void print(); // prints expression…
	}
	float convert (string s){ // Converts a string (as would be returned by evaluate) to a float
	}
}
#endif
