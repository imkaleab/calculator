#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "Node.h"
#include <string>
using std::string;
class Queue
{
    Node* front;
public:
    Queue() { front = NULL; }
    ~Queue();
    void Enqueue(string, int);
    void Dequeue();
    void Display();
    void Delete();
    bool IsEmpty() { return front == NULL; }
    friend class Calculator;
};
#endif
