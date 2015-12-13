/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include "Expression.h"

using namespace std;

Expression::Expression() { // set the expression to a blank expression if this is called
    (*this).exp = "";
}

Expression::Expression(string s) { // if a string is passes, set the expression to a string
    (*this).exp = s;
}

string Expression::evaluate(){ // Expression evaluation
    cout << "Expression Evaluate " << (*this).exp << endl;
    return ""; // blank return
}

void Expression::print(){ // Expression printing
    cout << "Expression print" << exp << endl;
}

Expression::~Expression() { //Destructor
}
