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
    parseBrackets(); //BEDMAS
    parseExpression('/');
    parseExpression('*');
    parseExpression('+');
    parseExpression('-');
    /*parseDivision();
    parseMultiplication();
    parseAddition();
    parseSubtraction();*/
    return true;
}

/*string ArithmeticExpression::evaluate (){//evaluate left expression and right expression
    return "";
}*/

void ArithmeticExpression::parseBrackets(){
    int leftBracket = -1, rightBracket = -1; int leftCount=0; int rightCount=0;
    for (unsigned int i = 0;i < exp.length();i++){//counting number of open brackets
        if (exp[i] == '('){
            leftCount++;
        }
    }
    if ((leftBracket == -1 && rightBracket != -1) || (rightBracket == -1 && leftBracket != -1)){
	    for (unsigned int i =0;i < exp.length();i++){//counting number of close brackets
	        if (exp[i] == ')'){
	            rightCount++;
	        }
	    }
	}
    if (leftCount !=rightCount)
        throw invalid_argument("Bracket mismatch error!");
    if ((unsigned) rightBracket == exp.length()-1 && leftBracket != -1){ //Brackets around entire expression

    if (leftCount == 0 && rightCount == 0){ //No brackets in expression
            cout << "No brackets L-> " << exp<< endl;
            left = new ArithmeticExpression(exp);
            right = NULL;
    }

   for (unsigned int C = 0;C < exp.length();C++){
       if (exp[C] == '('){
           leftBracket=C;
           for (unsigned int i =C;i < exp.length()-C;i++){
                   if (exp[i] == ')'){
                       rightBracket=i+C;
                       break;
                   }
           }
       }
   }

   if ( (unsigned)rightBracket == exp.length()-1 && leftBracket == 0){ //Brackets around entire expression
        cout << "Unnecessary brackets L-> " << exp.substr(leftBracket+1, rightBracket-1) << endl;
        left = new ArithmeticExpression(exp.substr(leftBracket+1, rightBracket-1));
        right = NULL;
        left->parseBrackets();
    } else if (leftBracket != -1 && rightBracket != -1) { //Inline brackets
    }
    else if (leftBracket != -1 && rightBracket != -1) { //Inline brackets
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

void ArithmeticExpression::parseExpression(string obj){    string lef = "", rig = "";
    size_t findPlace = exp.find(obj);
    if (findPlace != string::npos){
        cout << "Find place: " << findPlace << endl;
        for (unsigned int i = findPlace+1;i < exp.length();i++){
            if (!checkCharIs(exp[i], "()/*+-")){
                rig += exp[i];
            } else {
                break;
            }
        }
        for (int i = (int)(findPlace-1);i > -1;i--){
            if (!checkCharIs(exp[i], "()/*+-")){
                lef += exp[i];
            } else {
                break;
            }
        }
    }
    if (lef == "" && rig == ""){
        cout << "Could not find any " << obj << endl;
    } else {
        cout << lef << obj << rig << endl;
    }

    switch (obj){
        case '*':
            left = new Expression();
            break;
        case '/':
            left = new Divide();
            break;
        case '+':
            left = new Add();
            break;
        case '-':
            left = new Subtract();
            break;
        default:
            left = NULL;
            right = NULL;
            throw invalid_argument("Arithmetic Expression error!");
            break;
    }
    right = NULL;
    left->parse();
}
/*
void ArithmeticExpression::parseDivision(){
    string lef = "", rig = "";
    if (exp.find("/") != string::npos){

    }
}

void ArithmeticExpression::parseMultiplication(){
    string lef = "", rig = "";
    if (exp.find("*") != string::npos){

    }
}

void ArithmeticExpression::parseAddition(){
    string lef = "", rig = "";
    if (exp.find("+") != string::npos){

    }
}

void ArithmeticExpression::parseSubtraction(){
    string lef = "", rig = "";
    if (exp.find("-") != string::npos){

    }
}*/

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

bool ArithmeticExpression::checkCharIs(char chr, string s){
    for (unsigned int C = 0;C < s.length();C++)
        if (s[C] == chr)
            return true;
    return false;
}

ArithmeticExpression::~ArithmeticExpression(){
    //delete left;
    //delete right;
}
