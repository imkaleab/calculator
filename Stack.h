#ifndef STACK_H
#define STACK_H
#include <string>
#include "Node.h"

using std::string;
class Stack
{
    Node* top;
public:
    Stack() { top = NULL; }
    ~Stack() { Delete(); }
    Node* Pop();
    void Push(string, int);
    bool IsEmpty() { return top == NULL; }
    void Delete();
    void Display();
    friend class Calculator;
};
#endif
