/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include "HWK6cheunj3.h"
#include <iostream>
#include "ArithmeticExpression.h"
#include "Add.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
#include <string>
#include<sstream>

using namespace std;

int indexOperator(string toCheck, string stringToCheck){
    int sway = 0;
    for (unsigned int i = 0; i < stringToCheck.length(); i++){
        if (stringToCheck.substr(i, 1) == toCheck && sway == 0){
            return i;
        } else if (stringToCheck.substr(i, 1) == "(") {
            sway--;
        } else if (stringToCheck.substr(i, 1) == ")") {
            sway++;
        }
    }
    return -1;
}

string clipBrackets(string input){
    string in = input;
    bool clipped = false;
    while (!clipped){
        int bracketNum = 0, depth = 0;
        int indexCheck[4] = {indexOperator("-", in), indexOperator("+", in), indexOperator("*", in), indexOperator("/", in)};
        if ((indexCheck[0] + indexCheck[0] + indexCheck[0] + indexCheck[0])!=-4){
            return in;
        }
        for (unsigned int i = 0; i < in.length(); i++){
            if (in.substr(i, 1) == "(" || in.substr(i, 1) == ")"){
                bracketNum++;
            }
            if (in.substr(i, 1) == "("){
                depth++;
            } else if (in.substr(i, 1) == ")"){
                depth--;
            }
            if (depth >= 2 || depth <= -2){
                in = in.substr(1, in.length()-2);
                clipped = true;
                break;
            }
        }
        if (in.substr(0, 1) == "(" && in.substr(in.length()-1, 1) == ")" && bracketNum == 2 && !clipped){
            in = in.substr(1, in.length()-2);
            clipped = true;
            continue;
        }
        if (clipped){
            clipped = false;
            continue;
        }
        clipped = true;
    }
    return in;
}

bool checkOperator(string in){
    for (unsigned int i = 0; i < in.length(); i++){
        if (in.substr(i, 1) == "-" || in.substr(i, 1) == "+" || in.substr(i, 1) == "*" || in.substr(i, 1) == "/"){
            return true;
        }
    }
    return false;
}

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

        input = clipBrackets(input);

        if (checkOperator(input)){
            int indexCheck[4] = {indexOperator("-", input), indexOperator("+", input), indexOperator("*", input), indexOperator("/", input)};

            if (indexCheck[0] != -1){
                Subtract exp;
                exp.setExp(input, indexCheck[0]);
                string output = "";
                cout << exp.getExp() << " = " << output << endl;
            } else if (indexCheck[1] != -1){
                Add exp;
                exp.setExp(input, indexCheck[1]);
                string output = "";
                cout << exp.getExp() << " = " << output << endl;
            } else if (indexCheck[2] != -1){
                Multiply exp;
                exp.setExp(input, indexCheck[2]);
                string output = "";
                cout << exp.getExp() << " = " << output << endl;
            } else if (indexCheck[3] != -1){
                Divide exp;
                exp.setExp(input, indexCheck[3]);
                string output = "";
                cout << exp.getExp() << " = " << output << endl;
            }
        }
        else {
            cout << input << " = " << input << endl;
        }
    }

	return 0;
}

