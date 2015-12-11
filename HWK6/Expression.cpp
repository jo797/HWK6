#include "Expression.h"

using namespace std;

Expression::Expression() {
    (*this).exp = "";
}

Expression::Expression(string s) {
    (*this).exp = s;
}

string Expression::evaluate(){
    cout << "Expression Evaluate" << (*this).exp << endl;
    return "";
}

void Expression::print(){
    cout << "Expression print" << exp << endl;
}

Expression::~Expression() {

}
