/*
* Name: Joletta Cheung, Cameron Swinoga, Aleksander  Mercik
* MacID: cheunj3, swinogca, mercikaz
* Student Number: 1406622, 1404603, 1413714
* Description: This program takes a mathematical expression and outputs the answer. As of last use, this program was fully working, and could handle inputs such as (3*4) + ((3*4) + (7* (3*4)))
*/

#include <iostream>
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

bool invalidSpace (ArithmeticExpression **expr){ // Check if there are invalid spaces
    string check = "1234567890";//string used to check if the char is a number
	for (unsigned int i = 1; i < (*expr)->exp.length()-1;i++){//checking for spaces between numbers
		if ((*expr)->exp[i] == ' '){//finding spaces in expression
			bool left = true , right = true; // variables
			for (int j = i-1; j > -1; j--){//check to the left until it's not a space
				if ((*expr)->exp[j] != ' '){//if there's not a space to the left of space(s)
					if (checkCharIs((*expr)->exp[j], check)){//if it's a number
                        cout << (*expr)->exp[j] << " is a number" << endl;
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
                        cout << (*expr)->exp[k] << " is a number" << endl;
						right = true;
						break;
					} else { //anything else (ex.operation)
						right = false;
						break;
					}
				}
			}
			if (left && right){//seeing if both sides of the space(s) are numbers
				return true; //return true
			}
		}
	}
	return false; // otherwise return false when finished
}

bool checkCharIs(char chr, string s){ // checks if character is contained within a string
    for (unsigned int C = 0;C < s.length();C++) //for every character in the string
        if (s[C] == chr) // if the characters are equal
            return true; // return true, which ends the function
    return false; // otherwise return false
}

void removeUnessessary (ArithmeticExpression **expr){ // Error checking and space removal from final
    if (invalidSpace(expr)){ // if there are invalid spaces
       	throw invalid_argument("Invalid Space error!"); //throw an exception
       	return;
    }
    for (unsigned int C = 0;C < (*expr)->exp.length();C++) // otherwise
        if ((*expr)->exp[C] == ' ') // if there is a space
            (*expr)->exp.erase(C, 1); //erase the character at that index
}

void parse(ArithmeticExpression **expr){ //BEDMAS reversed
    removeUnessessary(expr); // Error checking and some formatting
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

int stringContains(string s, char c){ // Checking if a character is in a string
    int count = 0; // Returns a count of the number of times the character appears in the string
    for (unsigned int C = 0;C < s.length();C++) //For the length of the input string
        if (s[C] == c) // if the characters are equal
            count++; // increase the count
    return count; // return
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

int main (){
    string input = ""; //Empty input string to store the user input
    cout << fixed << setprecision(PRECISION); //Set the precision of outputted numbers

    while (input != "#"){ //Loop until the output is a #
        cout << "Please enter an expression: ";
        getline(cin, input); //Get the user input
        try{
            ArithmeticExpression *inputExp = new ArithmeticExpression(input); //Create a new ArithmeticExpression object based on the user input
            parse(&inputExp); //Parse the top level of the inputed expression
            cout << endl << endl;
            inputExp->print(); //Print out the expression tree
            cout << " = " << inputExp->convert(inputExp->evaluate()) << endl;
        } catch (const invalid_argument& e) {
            cerr << "Error parsing input: " << e.what() << endl; //If there's an error, print out an error message
        }
    }

	return 0; //Exit success
}

