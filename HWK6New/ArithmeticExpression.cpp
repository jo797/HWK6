#include "ArithmeticExpression.h"
#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Subtract.h"

#include <string>
#include <cstdlib>
#include<sstream>
#include <typeinfo>

using namespace std;

//WHAT IM TRYING TO DO
// Basically, evaluate should propagate thoughout the tree if its called from the oricinal expression. It should return a string/float if the expression is only a value (boolean) or tell its parts to
// evaluate if not. Pretty much:
// evaluate(){
// return: number if you only have a number as string
// else
// return: (right expression.evaluate() as string converted to float (operator of your class, eg. "+", "-", ect...) left expression.evaluate() as string converted to float) as string
//}
string ArithmeticExpression::evaluate(){
    return "0";
}

int ArithmeticExpression::indexOperator(string toCheck, string stringToCheck){
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

string ArithmeticExpression::clipEndBrackets(string input){
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

void ArithmeticExpression::setExp(string input, int opIndex){
    curr = input;
    operatorIndex = opIndex;
    curr = clipEndBrackets(curr);
    if (!checkOperator()){
        isValue = true;
        return;
    }
    string rightString = curr.substr(0, operatorIndex);
    string leftString = curr.substr(operatorIndex+1, curr.length()-operatorIndex-1);
    rightString = clipEndBrackets(rightString);
    leftString = clipEndBrackets(leftString);
    int rightIndexCheck[4] = {indexOperator("-", rightString), indexOperator("+", rightString), indexOperator("*", rightString), indexOperator("/", rightString)};
    int leftIndexCheck[4] = {indexOperator("-", leftString), indexOperator("+", leftString), indexOperator("*", leftString), indexOperator("/", leftString)};

    cout << rightString << " " << leftString << endl;

    if (rightIndexCheck[0] != -1){
        Subtract R;
        R.setExp(rightString, rightIndexCheck[0]);
        right = &R;
    } else if (rightIndexCheck[1] != -1){
        Add R;
        R.setExp(rightString, rightIndexCheck[1]);
        right = &R;
    } else if (rightIndexCheck[2] != -1){
        Multiply R;
        R.setExp(rightString, rightIndexCheck[2]);
        right = &R;
    } else if (rightIndexCheck[3] != -1){
        Divide R;
        R.setExp(rightString, rightIndexCheck[3]);
        right = &R;
    }

    if (leftIndexCheck[0] != -1){
        Subtract L;
        L.setExp(leftString, leftIndexCheck[0]);
        left = &L;
    } else if (leftIndexCheck[1] != -1){
        Add L;
        L.setExp(leftString, leftIndexCheck[1]);
        left = &L;
    } else if (leftIndexCheck[2] != -1){
        Multiply L;
        L.setExp(leftString, leftIndexCheck[2]);
        left = &L;
    } else if (leftIndexCheck[3] != -1){
        Divide L;
        L.setExp(leftString, leftIndexCheck[3]);
        left = &L;
    }
}

void ArithmeticExpression::print(){
    //Something
}

float ArithmeticExpression::convert(string in){
    return atof(in.c_str());
}

string ArithmeticExpression::ftosconvert(float in){
    stringstream ss;
    ss << in;
    return ss.str();
}

bool ArithmeticExpression::checkOperator(){
    for (unsigned int i = 0; i < ArithmeticExpression::curr.length(); i++){
        if (ArithmeticExpression::curr.substr(i, 1) == "-" || ArithmeticExpression::curr.substr(i, 1) == "+" || ArithmeticExpression::curr.substr(i, 1) == "*" || ArithmeticExpression::curr.substr(i, 1) == "/"){
            return true;
        }
    }
    return false;
}
