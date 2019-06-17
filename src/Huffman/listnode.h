#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

class ListNode{
public:

    ListNode(int frecuency, string name);

    ListNode* next = nullptr;
    string name;
    int frecuency;
    string numberRepresentation;

    void delete_all();
    void print();
};

#endif // LISTNODE_H
