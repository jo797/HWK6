/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include "Expression.h"

using namespace std;

int main () {
    string input = "";

    while (input != "#"){
        cout << "Please enter an expression: ";
        cin >> input;
        Expression exp {input};
        exp.evaluate();
        cout << "Finished" << endl;
    }

	return 0;
}

