#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;
class Node
{
public:
    string  Data;
    int     Type;
    Node* next;
};
#endif
