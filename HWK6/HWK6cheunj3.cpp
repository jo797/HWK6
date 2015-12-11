/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer
*/

#include <iostream>
#include <vector>
#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Multiply.h"
#include "Divide.h"
#include "Add.h"
#include "Subtract.h"
#include <iomanip>

#define PRECISION 2

using namespace std;

void parseBrackets(ArithmeticExpression **);
void parseExpression(ArithmeticExpression **, char);
bool checkCharIs(char, string);

bool invalidSpace (ArithmeticExpression **expr){
    string check = "1234567890";//string used to check if the char is a number
	for (unsigned int i = 1; i < (*expr)->exp.length()-1;i++){//checking for spaces between numbers
		if ((*expr)->exp[i] == ' '){//finding spaces in expression
			bool left = true , right = true;
			for (int j = i-1; j > -1; j--){//check to the left until it's not a space
				if ((*expr)->exp[j] != ' '){//if there's not a space to the left of space(s)
					if (checkCharIs((*expr)->exp[j], check)){//if it's a number
						left = true;
						break;
					} else { //anything else (ex.operation)
						left = false;
						break;
					}
				}
			}

			for (unsigned int k = i+1; k < (*expr)->exp.length(); k++){//check to the left until it's not a space
				if ((*expr)->exp[k]!=' '){//if there's not a space to the right of space(s)
				    cout << (*expr)->exp[k] << endl;
					if (checkCharIs((*expr)->exp[k], check)){//if it's a number
						right = true;
						break;
					} else { //anything else (ex.operation)
						right = false;
						break;
					}
				}
			}
			if (left && right){//seeing if both sides of the space(s) are numbers
				return true;
			}
		}
	}
	return false;
}

bool checkCharIs(char chr, string s){
    for (unsigned int C = 0;C < s.length();C++)
        if (s[C] == chr)
            return true;
    return false;
}

void removeUnessessary (ArithmeticExpression **expr){
    if (invalidSpace(expr)){
       	throw invalid_argument("Invalid Space error!");
    }
    for (unsigned int C = 0;C < (*expr)->exp.length();C++)
        if ((*expr)->exp[C] == ' ')
            (*expr)->exp.erase(C, 1);
}

void parse(ArithmeticExpression **expr){ //BEDMAS reversed
    removeUnessessary(expr);
    parseExpression(expr, '-');
    parseExpression(expr, '+');
    parseExpression(expr, '*');
    parseExpression(expr, '/');
    parseBrackets(&(*expr));
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
        cout << "No brackets -> " << (*expr)->exp << endl;
        return;
    } else if (leftBracket == 0 && (unsigned)rightBracket == (*expr)->exp.length()-1){  //Brackets around entire expression
        cout << "Unnecessary brackets -> " << (*expr)->exp.substr(leftBracket+1, rightBracket-1) << endl;
        (*expr)->left = new ArithmeticExpression((*expr)->exp.substr(leftBracket+1, rightBracket-1));
        (*expr)->right = NULL;
        parse(&(*expr)->left);
    } else if (leftBracket != -1 && rightBracket != -1){   //Inline brackets
        cout << "Inline brackets" << endl;
        string inside = (*expr)->exp.substr(leftBracket+1, rightBracket-1);
        string outside = (*expr)->exp.substr(rightBracket+2, (*expr)->exp.length()-1);
        ArithmeticExpression *AE = new ArithmeticExpression(inside);
        parse(&AE);
    }
}

int stringContains(string s, char c){
    int count = 0;
    for (unsigned int C = 0;C < s.length();C++)
        if (s[C] == c)
            count++;
    return count;
}

void parseExpression(ArithmeticExpression **expr, char obj){
    string lef = "", rig = "";
    if ((*expr)->exp == ""){
        cout << "Void expression" << endl;
        return;
    }
    size_t  findPlace = (*expr)->exp.length()-1;
    while (findPlace > 0){
        lef = (*expr)->exp.substr(0, findPlace);
        rig = (*expr)->exp.substr(findPlace+1, (*expr)->exp.length());

        if (stringContains(rig, ')') != stringContains(rig, '(') || (*expr)->exp[findPlace] != obj)
            findPlace--;
        else if ((*expr)->exp[findPlace] == obj)
            break;
    }
    if (findPlace == 0 && (*expr)->exp[findPlace] != obj){
        cout << "NO " << obj << " in " << (*expr)->exp << endl;
        return;
    }

    lef = (*expr)->exp.substr(0, findPlace);
    rig = (*expr)->exp.substr(findPlace+1, (*expr)->exp.length());

    if (findPlace == string::npos || (stringContains(lef, '(') != stringContains(lef, ')'))){
        cout << "AAAAAAAAAAA" << endl;
        cout << findPlace << endl;
        cout << "L: " << lef << endl;
        cout << "R: " << rig << endl;
        return;
    }

    if (lef == "" && rig == ""){
        cout << "Other void expression" << endl;
        return;
    }

    if (lef == "")
        lef = "0";
    if (rig == "")
        rig = "0";

    cout << "Converting " << (*expr)->exp << " to " << obj << " @ " << findPlace << endl;
    cout << "Left=" << lef << endl;
    cout << "Right=" << rig << endl;

    if ((lef == "" && rig != "") || (lef != "" && rig == ""))
        throw invalid_argument("Operator parsing error!");

    switch (obj){ //Switch based on what type of expression we want
        case '*':
            *expr = new Multiply(); //Change this to an appropriate object
            break;
        case '/':
            *expr = new Divide(); //Change this to an appropriate object
            break;
        case '+':
            *expr = new Add(); //Change this to an appropriate object
            break;
        case '-':
            *expr = new Subtract(); //Change this to an appropriate object
            break;
        default: //If nothing matches
            *expr = NULL; //This is an invalid expression
            throw invalid_argument("Operator parsing error! (cannot find operator)"); //Throw an error
            break;
    }

    if (expr != NULL){ //Don't evaluate anything if the expression is NULL
        (*expr)->setLR(lef, rig); //Make the left and right ArithmeticExpression objects  based on the left and right strings
        parse(&(*expr)->left); //Parse the left side
        parse(&(*expr)->right); //Parse the right size
    }
}

void printAndGet(string msg, vector<string> *values){ //Function for printing a message, and appending the value to a vector array
    string input; //Input variable
    cout << msg; //Output the message
    getline(cin, input); //Get the user input
    values -> push_back(input); //Append the input to the array
}

string getLastInput(vector<string> values){
    for (int C = values.size()-1;C > 0;C--)
        if (values.at(C) != "@" && values.at(C) != "#")
            return values.at(C);
    return "";
}

int main (){
    vector<string> inputs;
    inputs.push_back("");
    cout << fixed << setprecision(PRECISION); //Set the precision of outputted numbers
    ArithmeticExpression *inputExp = new ArithmeticExpression();

    while (true){ //Loop until the output is a #
        printAndGet("Please enter an expression: ", &inputs);
        if (inputs.back() == "#")
            return 0; //Exit success
        if (inputs.back() == "@" && getLastInput(inputs) == ""){
            cout << "You haven't inputted an expression yet!" << endl;
            continue;
        }
        if (inputs.back() == "@")
            inputExp->increment();
        else
            inputExp->exp = getLastInput(inputs); //Create a new ArithmeticExpression object based on the user input
        try{
            if (inputs.back() != "@")
                parse(&inputExp); //Parse the top level of the inputed expression
            cout << endl << endl;

            inputExp->print(); //Print out the expression tree
            cout << " = " << inputExp->convert(inputExp->evaluate()) << endl;
        } catch (const invalid_argument& e) {
            cerr << "Error parsing input: " << e.what() << endl; //If there's an error, print out an error message
        }
    }
}

