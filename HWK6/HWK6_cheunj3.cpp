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
#include "Multiplication.h"
#include "Division.h"
#include "Addition.h"
#include "Subtraction.h"
#include <iomanip>

#define PRECISION 2

using namespace std;

void parseBrackets(ArithmeticExpression **); //Prototyping the functions and methods for use all over this file
void parseExpression(ArithmeticExpression **, char);
bool checkCharIs(char, string);

bool invalidSpace (ArithmeticExpression **expr){
    string validNumbers = "1234567890";//string used to check if the char is a number
	for (unsigned int i = 1; i < (*expr)->exp.length()-1;i++){//checking for spaces between numbers
		if ((*expr)->exp[i] == ' '){//finding spaces in expression
			bool left = false , right = false; //Reset the boolean values both to true
			for (int j = i-1; j > -1; j--){//check to the left until it's not a space
				if ((*expr)->exp[j] != ' '){//if there's not a space to the left of space(s)
                    left = checkCharIs((*expr)->exp[j], validNumbers); //Store if the left character is a number or not
                    break; //Exit the loop
				}
			}

			for (unsigned int k = i+1; k < (*expr)->exp.length(); k++){//check to the right until it's not a space
				if ((*expr)->exp[k]!=' '){//if there's not a space to the right of space(s)
				    right = checkCharIs((*expr)->exp[k], validNumbers); //Store if the right character is a number or not
                    break; //Exit the loop
				}
			}
			if (left && right){//seeing if both sides of the space(s) are numbers
				return true; //There is spaces found
			}
		}
	}
	return false;//no spaces found
}

bool checkCharIs(char chr, string s){//checking if a character matches any of the characters in a string
    for (unsigned int C = 0;C < s.length();C++)//goes through the each character in the string
        if (s[C] == chr) //checking if the characters match
            return true;//match
    return false;//not found
}

void removeUnnecessary (ArithmeticExpression **expr){
    if (invalidSpace(expr))//checking for invalid space
       	throw invalid_argument("Invalid Space error!");//error found
    for (unsigned int C = 0;C < (*expr)->exp.length();C++)//getting rid of all spaces in expression
        if ((*expr)->exp[C] == ' ') // if there is a space
            (*expr)->exp.erase(C, 1);//erasing the spaces
}

void parse(ArithmeticExpression **expr){ //BEDMAS reversed
    removeUnnecessary(expr); //Remove unnecessary stuff
    parseExpression(expr, '+'); //Try to parse all of the addition operators
    parseExpression(expr, '-'); //Try to parse all of the subtraction operators
    parseExpression(expr, '*'); //Try to parse all of the multiplication operators
    parseExpression(expr, '/'); //Try to parse all of the division operators
    parseBrackets(&(*expr)); //Try to parse all of the brackets in the expression
}

void parseBrackets(ArithmeticExpression **expr){
    int leftBracket = -1, rightBracket = -1;//initial values to indicate no brackets

    for (unsigned int i = 0; i < (*expr)->exp.length(); i++){ //Finding first open bracket
        if ((*expr)->exp[i] == '('){ //if '(' is in the inputed expression
            leftBracket = i; //sets to index of the '(' location
            break;
        }
    }

    for (unsigned int i =0; i < (*expr)->exp.length(); i++) //Finding last close bracket
        if ((*expr)->exp[i] == ')')//if ')' is in the inputed expression
            rightBracket = i;//sets to index of the ')' location

    if ((leftBracket == -1 && rightBracket != -1) || (leftBracket != -1 && rightBracket == -1))//One bracket is defined and the other is not
        throw invalid_argument("Bracket Mismatch error!");//throw error

    if (leftBracket == -1 && rightBracket == -1){  //No brackets in expression
        return;
    } else if (leftBracket == 0 && (unsigned)rightBracket == (*expr)->exp.length()-1){  //Brackets around entire expression
        (*expr)->left = new ArithmeticExpression((*expr)->exp.substr(leftBracket+1, rightBracket-1));//new expression in places to the left
        (*expr)->right = NULL;//nothing on the right
        parse(&(*expr)->left);//evaluates new expression
    } else if (leftBracket != -1 && rightBracket != -1){   //Inline brackets
        string inside = (*expr)->exp.substr(leftBracket+1, rightBracket-1);//substring of expression inside brackets
        string outside = (*expr)->exp.substr(rightBracket+2, (*expr)->exp.length()-1);//substring of expression outside brackets
        ArithmeticExpression *AE = new ArithmeticExpression(inside);//creates new object type ArithmeticExpression of inside expression
        parse(&AE);//evaluates inside expression
    }
}

int stringContains(string s, char c){
    int count = 0; //Initialize a integer to store how many times the character occurs
    for (unsigned int C = 0;C < s.length();C++) //Loop through the string
        if (s[C] == c) //If the part of the string is equal to the given character
            count++; //Increment the count
    return count; //Return the total count
}

void parseExpression(ArithmeticExpression **expr, char obj){ //Method for adding left and right operators of the type given
    string lef = "", rig = ""; //Create variables to store the left and right strings either side of the operator
    if ((*expr)->exp == "") //If the expression string is nothing
        return; //Something went wrong, exit
    size_t  findPlace = (*expr)->exp.length()-1; //Initial creation of the index of where the character is at
    while (findPlace > 0){ //Loop while the index is greater than zero
        lef = (*expr)->exp.substr(0, findPlace); //Split the left side of the expression
        rig = (*expr)->exp.substr(findPlace+1, (*expr)->exp.length()); //Split the right side of the expression

        if (stringContains(rig, ')') != stringContains(rig, '(') || (*expr)->exp[findPlace] != obj) //If the operator is inside brackets and the current index isn't the operator
            findPlace--; //Decrement the index
        else if ((*expr)->exp[findPlace] == obj) //If the current index is equal to the operator
            break; //Exit the while loop
    }
    if (findPlace == 0 && (*expr)->exp[findPlace] != obj) //If the expression cannot be found
        return; //Exit the method

    lef = (*expr)->exp.substr(0, findPlace); //Left is assigned to the part of the string to the left of the operator
    rig = (*expr)->exp.substr(findPlace+1, (*expr)->exp.length()); //Right is assigned to the part of the string to the right of the operator

    if (stringContains(lef, '(') != stringContains(lef, ')') || (lef == "" && rig == "")) //If the left and right string are nothing, or there's a bracket mismatch
        return; //Something's wrong, exit

    if (lef == "" && obj == '-') //Specifically for dealing with minus's
        lef = "0";

    if ((lef == "" && rig != "") || (lef != "" && rig == "")) //If one side is filled and the other is not
        throw invalid_argument("Operator parsing error!"); //Throw an error

    switch (obj){ //Switch based on what type of expression we want
        case '*':
            *expr = new Multiplication(); //Change this to an appropriate object
            break;
        case '/':
            *expr = new Division(); //Change this to an appropriate object
            break;
        case '+':
            *expr = new Addition(); //Change this to an appropriate object
            break;
        case '-':
            *expr = new Subtraction(); //Change this to an appropriate object
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

string getLastInput(vector<string> values){ //Function for getting the last valid input expression
    for (int C = values.size()-1;C > 0;C--) //Start at the end and decrement
        if (values.at(C) != "@" && values.at(C) != "#" && values.at(C) != "") //If the current string isn't the repeat operator or the exit operator or empty
            return values.at(C); //Return the valid string
    return ""; //Return an empty string
}

int main (){ //Main method
    vector<string> inputs; //Vector array to store the history of the input values
    inputs.push_back(""); //Push back an initial string
    cout << fixed << setprecision(PRECISION); //Set the precision of outputted numbers
    ArithmeticExpression *inputExp = new ArithmeticExpression(); //Create a new empty ArithmeticExpression object

    while (true){ //Infinite loop
        printAndGet("Please enter an expression: ", &inputs); //Push back the inputted expression to the expression vector

        if (inputs.back() == "#") //If the user wants to exit
            return 0; //Exit success
        if (inputs.back() == "@" && getLastInput(inputs) == ""){ //If the user wants to increment, and the last input isn't empty (uninitialized)
            cout << "You haven't inputted an expression yet!" << endl;
            continue; //Restart the loop
        }
        if (inputs.back() == "@") //If the user wants to increment
            try{
                inputExp->increment(); //Increment the current expression
            } catch (const invalid_argument &e) { //Catch an error that is given
                cerr << endl << "Expression is not well formed (" << e.what() << ")" << endl; //If there's an error, print out an appropriate error message
                continue; // Restart the loop
            }
        else
            inputExp = new ArithmeticExpression(getLastInput(inputs)); //Create a new ArithmeticExpression object based on the user input
        try{
			if (inputs.back() != "@") //Don't parse if we're just incrementing
                    parse(&inputExp); //Parse the top level of the inputed expression

            inputExp->print(); //Print out the expression tree
            cout << " = " << inputExp->convert(inputExp->evaluate()) << endl;
        } catch (const invalid_argument &e) { //Catch an error that is given
            cerr << endl << "Expression is not well formed (" << e.what() << ")" << endl; //If there's an error, print out an appropriate error message
        }
    }
}
