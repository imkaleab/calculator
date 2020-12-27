#include <iostream>
#include "Calculator.h"
#include <string>

using namespace std;

int main()
{
    string x ;
    cout << "Please enter an expression: ";
    getline(cin, x);
    Calculator CT;
    CT.ReadInput(x);
    CT.Convert();
    CT.Eval();
    CT.Display();
    return 0;
}