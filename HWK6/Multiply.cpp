/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include "Multiply.h"

string Multiply::evaluate(){ // Evaluation function
    if (left != NULL && right != NULL){ // If the left and right expressions are not empty
        try{
            return to_string(convert(left->evaluate()) * convert(right->evaluate())); // return this objects evaluation ie. (x * y) for multiplication. calls evaluation for left and right objects.
        } catch (const invalid_argument &e) { //Float conversion error
            throw invalid_argument("Arithmetic error");
        }
    } else { // if the evaluation is a value
        return exp; // return just the value
    }
}

void Multiply::print(){ // Print function
    if (left != NULL && right != NULL){ // If something points to the left and right, ie. it is not a value
        cout << "("; // Print outside brackets
        left->print(); // print the left expression, calling this function from the left expression
        cout << "*"; // Multiplication, so * sign
        right->print(); // call print for the right expression
        cout << ")"; // print out a closing bracket
    } else {
        cout << exp; // print out the expression, ie. the value.
    }
}
