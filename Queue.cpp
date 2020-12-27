#include "Queue.h"
#include "Node.h"
#include <string>
#include <iostream>

void Queue::Enqueue(string info, int ty)
{
    if (IsEmpty())
    {
        front = new Node;
        front->Data = info;
        front->Type = ty;
    }
    else
    {
        Node* curr = front;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node* temp = new Node;        
        curr->next = temp;
        temp->next = NULL;
        temp->Type = ty;
        temp->Data = info;
    }
}
void Queue::Dequeue()
{
    Node* temp = front;
    if (front != NULL)
    {
        front = front->next;
        temp->next = NULL;
        delete temp;
    }
    else std::cout << "Queue is empty" << std::endl;
}
void Queue::Display()
{
    Node* curr = front;
    while (curr != NULL)
    {
        std::cout << "From Queue: " << curr->Data << std::endl;
        curr= curr->next;
    }
}
Queue::~Queue()
{
    Delete();
}
void Queue::Delete()
{
    Node* curr = front;
    Node* temp;
    front = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = NULL;
        delete curr;
        curr = temp;
    }

    
}