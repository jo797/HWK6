#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;

ArithmeticExpression::ArithmeticExpression() : Expression::Expression(){
    left = NULL;
    right = NULL;
}

ArithmeticExpression::ArithmeticExpression(string s) : Expression::Expression(s){
    left = NULL;
    right = NULL;
}

bool ArithmeticExpression::parse(){
    parseBrackets();
    return true;
}

/*string ArithmeticExpression::evaluate (){//evaluate left expression and right expression
    return "";
}*/

void ArithmeticExpression::parseBrackets(){
    int leftBracket = -1, rightBracket = -1;
    for (unsigned int C = 0;C < exp.length();C++){
        if (exp[C] == '('){
            leftBracket = C;
            for (unsigned int i = C;i < exp.length();i++){
                if (exp[i] == ')'){
                    rightBracket = i;
                }
            }
        }
    }
    if ((leftBracket == -1 && rightBracket != -1) || (rightBracket == -1 && leftBracket != -1))
        throw invalid_argument("Bracket mismatch error!");
    if ((unsigned) rightBracket == exp.length()-1 && leftBracket != -1){ //Brackets around entire expression
        cout << "Unnecessary brackets L-> " << exp.substr(leftBracket+1, rightBracket-1) << endl;
        left = new ArithmeticExpression(exp.substr(leftBracket+1, rightBracket-1));
        right = NULL;
        left->parseBrackets();
    } else if (leftBracket != -1 && rightBracket != -1) { //Inline brackets
        cout << "Inline brackets" << endl;
        cout << "L-> " << exp.substr(leftBracket+1, rightBracket-1) << endl;
        cout << "R-> " << exp.substr(rightBracket+1, exp.length()-1) << endl;
        left = new ArithmeticExpression(exp.substr(leftBracket+1, rightBracket-1));
        right = new ArithmeticExpression(exp.substr(rightBracket+1, exp.length()-1));
        left->parseBrackets();
        right->parseBrackets();
    } else if (leftBracket == -1 && rightBracket == -1){ //No brackets in expression
        cout << "No brackets L-> " << exp << endl;
        left = new ArithmeticExpression(exp);
        right = NULL;
    }
}

void ArithmeticExpression::print(){
    if (left == NULL && right == NULL){
        cout << "E: " << exp << endl;
    } else if (left != NULL && right == NULL) {
        cout << "L: " << endl;
        left->print();
    } else if (left == NULL && right != NULL){
        cout << "R: " << endl;
        right->print();
    } else if (left != NULL && right != NULL){
        cout << "L: " << endl;
        left->print();
        cout << "R: " << endl;
        right->print();
    }
}

float ArithmeticExpression::convert (string){
    return 0.0f;
}

ArithmeticExpression::~ArithmeticExpression(){
    //delete left;
    //delete right;
}
