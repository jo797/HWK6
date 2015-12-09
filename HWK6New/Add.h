#include "ArithmeticExpression.h"
#include <string>

#ifndef ADD_H_
#define ADD_H_

using namespace std;

class Add : public ArithmeticExpression {
    public:
        string evaluate();
        void print();
    private:
};
#endif
