#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
using std::string;
class Calculator
{
    string     PostFix;
    string     InFix;


    enum InputType {
        Input0,             // 0
        Input1,             // 1
        Input2,             // 2
        Input3,             // 3
        Input4,             // 4
        Input5,             // 5
        Input6,             // 6
        Input7,             // 7
        Input8,             // 8
        Input9,             // 9
        InputPlus,          // +
        InputMinus,         // -
        InputMultiply,      // *
        InputDivide,        // /
        InputModulo,        // %
        InputExponent,      // ^
        InputLeftPar,       // (
        InputRightPar,      // )
        InputDecimal,       // .
        InputSpace,         // 
        InputUnknown,
        NumInputs
    };

    enum Precedence {
        LeftParentheses,    //0
        AddSubtract,        //1
        MultiplyDivide,     //2
        Exponent,           //3
        RightParenthesis    //4
    };

    enum ReadState {
        StartReading,
        AfterNumber,
        AfterOperator,
        AfterLeftPar,
        AfterRightPar,
        AfterExponent,
        NumStates
    };

    typedef     ReadState(*CalcFunc)   (string&);
    typedef     unsigned        char    UChar;

    static      CalcFunc        StateFunction[];
    static      UChar           StateTable[NumInputs][NumStates];
    static      InputType       InputTable[];
    static      ReadState       GotANumber(string&);
    static      ReadState       GotMDOperator(string&);
    static      ReadState       GotASOperator(string&);
    static      ReadState       GotExponent(string&);
    static      ReadState       GotLPar(string&);
    static      ReadState       GotRPar(string&);
    static      ReadState       GotDecimal(string&);
    static      ReadState       NotYetDone(string&);
    
    static      Stack           ST;
    static      Queue           Q;
    static      int             NumPar;
    static      bool            Evaluate;
    static      double          Result;


public:
    Calculator() { }
    ~Calculator() { Delete();}
    void Delete();
    void ReadInput(string);
    void Convert();
    void Display();
    void Eval();

}; 
#endif
