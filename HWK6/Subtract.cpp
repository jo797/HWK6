/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include "Subtract.h"

string Subtract::evaluate(){ // Evaluation function
    if (left != NULL && right != NULL){ // If the left and right expressions are not empty
        return to_string(convert(left->evaluate()) - convert(right->evaluate())); // return this objects evaluation ie. (x - y) for subtraction. calls evaluation for left and right objects.
    } else { // if the evaluation is a value
        return exp; // return just the value
    }
}

void Subtract::print(){ // Print method, recursive
    if (left != NULL && right != NULL){ // If something points to the left and right, ie. it is not a value
        cout << "("; // Print outside brackets
        if (left->exp != "0")
            left->print(); // print the left expression, calling this function from the left expression
        cout << "-"; // Subtraction, so print a minus
        right->print(); // call print for the right expression
        cout << ")"; // print out a closing bracket
    } else {
        cout << exp; // print out the expression, ie. the value.
    }
}
