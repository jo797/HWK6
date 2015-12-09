#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <iostream>

using namespace std;

class Expression {
    public:
        bool isValue = false;
        string curr = "";
        virtual string evaluate();
        virtual void print();
        string getExp(){return curr;};
};
#endif
