#ifndef HUFFMAN2_BINARYTREE_H
#define HUFFMAN2_BINARYTREE_H

#include "BinaryTreeNode.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

class BinaryTree {
public:
    BinaryTreeNode *root;
    bool containsElement(BinaryTreeNode* node,string name);
    bool isEmpty();
    void addNode(int frecuency, string name, ListNode *node);
    void traverseInOrder(BinaryTreeNode* node);
private:
    BinaryTreeNode* addNode(BinaryTreeNode *currentNode,int frecuency, string name, ListNode *node);

};


#endif //HUFFMAN2_BINARYTREE_H
