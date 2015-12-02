/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;

int main () {
    string input = "";

    while (input != "#"){
        cout << "Please enter an expression: ";
        cin >> input;
        ArithmeticExpression exp {input};
        try{
            exp.parse();
            exp.evaluate();
            exp.print();
        } catch (const invalid_argument& e) {
            cout << "Error parsing input: " << e.what() << endl;
        }
    }

	return 0;
}

