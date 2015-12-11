#include "ArithmeticExpression.h"
#include <string>

#ifndef DIVIDE_H_
#define DIVIDE_H_

using namespace std;

class Divide: public ArithmeticExpression {
    public:
        string evaluate() override;
        void print() override;
    private:
};
#endif
