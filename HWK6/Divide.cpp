#include "Divide.h"

string Divide::evaluate(){ // Evaluation method
    if (left != NULL && right != NULL){ // If the left and right expressions are not empty
        return to_string(convert(left->evaluate()) / convert(right->evaluate())); // return this objects evaluation ie. (x / y) for division. calls evaluation for left and right objects.
    } else { // if the evaluation is a value
        return exp; // return just the value
    }
}

void Divide::print(){ //Print method
    if (left != NULL && right != NULL){ // If something points to the left and right, ie. it is not a value
        cout << "("; // Print outside brackets
        left->print(); // print the left expression, calling this function from the left expression
        cout << "/"; // Division, so / sign.
        right->print(); // call print for the right expression
        cout << ")"; // print out a closing bracket
    } else {
        cout << exp; // print out the expression, ie. the value.
    }
}
