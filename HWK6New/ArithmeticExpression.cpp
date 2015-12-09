#include "ArithmeticExpression.h"
#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Subtract.h"

#include <string>
#include <cstdlib>
#include<sstream>

using namespace std;

string ArithmeticExpression::evaluate(){
    if (ArithmeticExpression::isValue){
        cout << "value" << endl;
        return ArithmeticExpression::curr;
    } else{
        cout << "ech" << endl;
        cout << ArithmeticExpression::right->isValue << endl;
        return "0";
        return ArithmeticExpression::ftosconvert(ArithmeticExpression::convert(ArithmeticExpression::right->evaluate())+ArithmeticExpression::convert(ArithmeticExpression::left->evaluate()));
    }
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

void ArithmeticExpression::clipEndBrackets(){
    /*int bracketNum = 0;
    for (unsigned int i = 0; i < ArithmeticExpression::curr.length(); i++){
        cout << depth << " : " << ArithmeticExpression::curr.substr(i, 1) << endl;
        if (ArithmeticExpression::curr.substr(i, 1) == "("){
            depth+=1;
        } else if (ArithmeticExpression::curr.substr(i, 1) == ")") {
            depth=-1;
        }
        if (depth >= 2 || depth <= -2){
            ArithmeticExpression::curr = ArithmeticExpression::curr.substr(1, ArithmeticExpression::curr.length()-2);
            return;
        }
    }*/
}

void ArithmeticExpression::setExp(string input){
    ArithmeticExpression::curr = input;
    clipEndBrackets();
    int index [4] = {-1, -1, -1, -1};
    if (!checkOperator()){
        ArithmeticExpression::isValue = true;
        return;
    }
    cout << ArithmeticExpression::curr << endl;
    index[0] = indexOperator("-", ArithmeticExpression::curr);
    index[1] = indexOperator("+", ArithmeticExpression::curr);
    index[2] = indexOperator("*", ArithmeticExpression::curr);
    index[3] = indexOperator("/", ArithmeticExpression::curr);
    if (index[0] != -1){
        string rightString = ArithmeticExpression::curr.substr(0, index[0]);
        string leftString = ArithmeticExpression::curr.substr(index[0]+1, ArithmeticExpression::curr.length()-index[0]-1);
        cout << rightString << " - " << leftString << endl;
        Subtract R;
        Subtract L;
        ArithmeticExpression::left = &L;
        ArithmeticExpression::right = &R;
        R.setExp(rightString);
        L.setExp(leftString);
    } else if (index[1] != -1){
        string rightString = ArithmeticExpression::curr.substr(0, index[1]);
        string leftString = ArithmeticExpression::curr.substr(index[1]+1, ArithmeticExpression::curr.length()-index[1]-1);
        cout << rightString << " + " << leftString << endl;
        Add R;
        Add L;
        ArithmeticExpression::left = &L;
        ArithmeticExpression::right = &R;
        R.setExp(rightString);
        L.setExp(leftString);
    } else if (index[2] != -1){
        string rightString = ArithmeticExpression::curr.substr(0, index[2]);
        string leftString = ArithmeticExpression::curr.substr(index[2]+1, ArithmeticExpression::curr.length()-index[2]-1);
        cout << rightString << " * " << leftString << endl;
        Multiply R;
        Multiply L;
        ArithmeticExpression::left = &L;
        ArithmeticExpression::right = &R;
        R.setExp(rightString);
        L.setExp(leftString);
    } else if (index[3] != -1){
        string rightString = ArithmeticExpression::curr.substr(0, index[3]);
        string leftString = ArithmeticExpression::curr.substr(index[3]+1, ArithmeticExpression::curr.length()-index[3]-1);
        cout << rightString << " / " << leftString << endl;
        Divide R;
        Divide L;
        ArithmeticExpression::left = &L;
        ArithmeticExpression::right = &R;
        R.setExp(rightString);
        L.setExp(leftString);
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
