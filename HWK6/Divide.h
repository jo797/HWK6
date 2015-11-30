#include "ArithmeticExpression.h"
#include <string>

#ifndef DIVIDE_H_
#define DIVIDE_H_

using namespace std;

class Divide: public ArithmeticExpression {
    public:
        Divide();
        string evaluate();
        void print();
        virtual ~Divide();
    private:
};
#endif
