#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <iostream>

using namespace std;

class BinaryTreeNode{
private:
    string name;
    int frecuency;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
public:

    const string &getName() const;

    void setName(const string &name);

    BinaryTreeNode *getLeft() const;

    void setLeft(BinaryTreeNode *left);

    BinaryTreeNode *getRight() const;

    void setRight(BinaryTreeNode *right);

    int getFrecuency() const;

    void setFrecuency(int frecuency);

    BinaryTreeNode(string name, int frecuency);
};

#endif // BINARYTREENODE_H
