#include "Expression.h"

using namespace std;

Expression::Expression() {
    (*this).exp = "";
}

Expression::Expression(string s) {
    (*this).exp = s;
}

string Expression::evaluate(){
    cout << "Evaluating " << (*this).exp << endl;
    return "";
}

void Expression::print(){
    cout << exp << endl;
}

Expression::~Expression() {

}
