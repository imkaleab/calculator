#include "Stack.h"
#include <iostream>
using namespace std;

Node* Stack::Pop()
{
    Node* temp = top;
    if (top != NULL)
    {
        top = temp->next;
        temp->next = NULL;
    }
    else cout << "Stack is empty." << endl;
    return temp;
}
void Stack::Push(string str, int ty)
{
    if (IsEmpty())
    {
        top = new Node;
        top->Data = str;
        top->Type = ty;
    }
    else
    {
        Node* temp = new Node;
        temp->next = top;
        temp->Data = str;
        temp->Type = ty;
        top = temp;
    }
}
void Stack::Delete()
{
    Node* curr = top;
    Node* temp;
    top = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = NULL;
        delete curr;
        curr = temp;
    }
}
void Stack::Display()
{
    Node* curr = top;
    while (curr != NULL)
    {
        std::cout << "From Stack: " << curr->Data << std::endl;
        curr = curr->next;
    }

}