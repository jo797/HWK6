/*
 * Expression.h
 *
 *  Created on: Nov 28, 2015
 *      Author: Joletta
 */
#include <string>

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class Expression{

	virtual string evaluate(); // evaluate expression and return string representation of the result.
	virtual void print(); // prints expression
};
#endif
