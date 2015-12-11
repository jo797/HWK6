/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;

ArithmeticExpression::ArithmeticExpression() : Expression::Expression(){ //Constructor when nothing is given
    left = NULL; //If we just want a new object, first call the expression constructor
    right = NULL; //Then set the left and right objects to null
}

ArithmeticExpression::ArithmeticExpression(string s) : Expression::Expression(s){ //Constructor when passing in a string
    left = NULL; //First call the Expression constructor
    right = NULL; //Then set the left and right objects to null
}

string ArithmeticExpression::evaluate(){ //Evaluate override from Expression
    if (left != NULL) //If there's a left branch
        return left->evaluate(); //Evaluate the left branch
    else if (right != NULL) //If there's a right branch
        return right->evaluate(); //Evaluate the right branch
    else //Else this is an end node
        return exp; //Print the expression string
}

void ArithmeticExpression::print(){ //Print override from Expression
    if (left != NULL) //If there's a left branch
        left->print(); //Print the left branch
    else if (right != NULL) //If there's a right branch
        right->print(); //Print the right branch
    else //Else this is an end node
        cout << exp; //Print the expression string
}

void ArithmeticExpression::setLR(string L, string R){ //Method to initialize the left and right Expression pointers from two strings
    left = new ArithmeticExpression(L);
    right = new ArithmeticExpression(R);
}

float ArithmeticExpression::convert (string s){ //Function to convert a string to a float
    return stof(s, nullptr);
}

ArithmeticExpression::~ArithmeticExpression(){
    //delete left;
    //delete right;
}
