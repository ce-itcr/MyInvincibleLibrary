#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "binarytreenode.h"
#include "json/jsonserializable.h"
#include "json/jsonserializer.h"
#include "listnode.h"
#include <iostream>

using namespace std;

class BinaryTree : public JsonSerializable{
public:
    BinaryTreeNode *root;
    bool containsElement(BinaryTreeNode* node,string name);
    bool isEmpty();
    void addNode(int frecuency, string name, ListNode *node);
    void traverseInOrder(BinaryTreeNode* node);
    void deleteAll(BinaryTreeNode *currentNode);
    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);
    BinaryTreeNode *getRoot() const;
    void setRoot(BinaryTreeNode *value);

private:
    BinaryTreeNode* addNode(BinaryTreeNode *currentNode,int frecuency, string name, ListNode *node);
};

#endif // BINARYTREE_H
