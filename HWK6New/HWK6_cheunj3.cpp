/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include "ArithmeticExpression.h"
#include <string>
#include<sstream>

using namespace std;

int main () {

    /*string a = "a b c d    e";
    string b = "";
    for (int i = 0; i < a.length();i++){
        if (a.substr(i, 1) != " "){
            b+=a.substr(i, 1);
        }
    }

    cout << b;*/

    string input;


    while (true){
        input = "";
        cout << "Please enter an expression: ";
        cin >> input;
        if (input == "#"){
            break;
        }

        string temp = "";
        for (unsigned int i = 0; i < input.length();i++){
            if (input.substr(i, 1) != " "){
                temp+=input.substr(i, 1);
            }
        }
        input = temp;

        ArithmeticExpression exp;
        exp.setExp(input);
        string output = "";
        //output = exp.evaluate();
        cout << exp.getExp() << " = " << output << endl;
    }

	return 0;
}
