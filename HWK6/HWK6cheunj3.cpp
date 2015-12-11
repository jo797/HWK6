/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Multiply.h"
#include "Divide.h"
#include "Add.h"
#include "Subtract.h"

using namespace std;

bool checkCharIs(char, string);
void parseBrackets(ArithmeticExpression **);
void parseExpression(ArithmeticExpression **, char);

void parse(ArithmeticExpression **expr){ //BEDMAS reversed
    parseBrackets(&(*expr));
    parseExpression(expr, '-');
    parseExpression(expr, '+');
    parseExpression(expr, '*');
    parseExpression(expr, '/');
}

void parseBrackets(ArithmeticExpression **expr){
    int leftBracket = -1, rightBracket = -1;

    for (unsigned int i = 0; i < (*expr)->exp.length(); i++){ //Finding first open bracket
        if ((*expr)->exp[i] == '('){
            leftBracket = i;
            break;
        }
    }

    for (unsigned int i =0; i < (*expr)->exp.length(); i++) //Finding last close bracket
        if ((*expr)->exp[i] == ')')
            rightBracket = i;

    if ((leftBracket == -1 && rightBracket != -1) || (leftBracket != -1 && rightBracket == -1))//One bracket is defined and the other is not!
        throw invalid_argument("Bracket Mismatch error!");

    if (leftBracket == -1 && rightBracket == -1){  //No brackets in expression
        cout << "No brackets L-> " << (*expr)->exp<< endl;
        return;
    }

    if ( (unsigned)rightBracket == (*expr)->exp.length()-1 && leftBracket == 0){  //Brackets around entire expression
        cout << "Unnecessary brackets L-> " << (*expr)->exp.substr(leftBracket+1, rightBracket-1) << endl;
        (*expr)->left = new ArithmeticExpression((*expr)->exp.substr(leftBracket+1, rightBracket-1));
        (*expr)->right = NULL;
        parse(&(*expr)->left);
    }
    else if (leftBracket != -1 && rightBracket != -1){   //Inline brackets
        cout << "Inline brackets" << endl;
        cout << "L-> " << (*expr)->exp.substr(leftBracket+1, rightBracket-1) << endl;
        cout << "R-> " << (*expr)->exp.substr(rightBracket+1, (*expr)->exp.length()-1) << endl;
        (*expr)->left = new ArithmeticExpression((*expr)->exp.substr(leftBracket+1, rightBracket-1));
        (*expr)->right = new ArithmeticExpression((*expr)->exp.substr(rightBracket+1, (*expr)->exp.length()-1));
        parse(&(*expr)->left);
        parse(&(*expr)->right);
    }
}

void parseExpression(ArithmeticExpression **expr, char obj){
    string lef = "", rig = "";
    size_t findPlace = (*expr)->exp.find(obj);
    if (findPlace != string::npos){
        lef = (*expr)->exp.substr(0, findPlace);
        rig = (*expr)->exp.substr(findPlace+1, (*expr)->exp.length());
    } else {
        return;
    }
    cout << "Converting " << (*expr)->exp << " to " << obj << " @ " << findPlace << endl;
    cout << "Left=" << lef << endl;
    cout << "Right=" << rig << endl;
    if (lef == "" && rig == "")
        return;
    if ((lef == "" && rig != "") || (lef != "" && rig == ""))
        throw invalid_argument("Operator parsing error!");

    switch (obj){
        case '*':
            *expr = new Multiply();
            break;
        case '/':
            *expr = new Divide();
            break;
        case '+':
            *expr = new Add();
            break;
        case '-':
            *expr = new Subtract();
            break;
        default:
            *expr = NULL;
            throw invalid_argument("Operator parsing error!");
            break;
    }

    if (expr != NULL){
        (*expr)->setLR(lef, rig);
        parse(&(*expr)->left);
        parse(&(*expr)->right);
    }
}

bool checkCharIs(char chr, string s){
    for (unsigned int C = 0;C < s.length();C++)
        if (s[C] == chr)
            return true;
    return false;
}

int main () {
    string input = "";

    while (input != "#"){
        cout << endl << "Please enter an expression: ";
        cin >> input;
        ArithmeticExpression *inputExp = new ArithmeticExpression(input);//{input};
        try{
            parse(&inputExp);
            //inputExp.evaluate();
            //cout << (*inputExp).left->exp << "::" << (*inputExp).right->exp << endl;
            //cout << inputExp->left->exp << "::" << inputExp->right->exp << endl;
            cout << endl << endl;
            inputExp->print();
        } catch (const invalid_argument& e) {
            cout << "Error parsing input: " << e.what() << endl;
        }
    }

	return 0;
}

