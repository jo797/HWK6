#include "Expression.h"

using namespace std;

Expression::Expression(string s) {
    exp = s;
}

string Expression::evaluate(){
}

void Expression::print(){
    cout << exp << endl;
}

Expression::~Expression() {

}
