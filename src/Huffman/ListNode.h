#ifndef HUFFMAN2_LISTNODE_H
#define HUFFMAN2_LISTNODE_H

#include <iostream>

using namespace std;


class ListNode {
public:

    ListNode(int frecuency, string name);

    ListNode* next = nullptr;
    string name;
    int frecuency;
    string numberRepresentation;

    void delete_all();
    void print();
};


#endif //HUFFMAN2_LISTNODE_H
