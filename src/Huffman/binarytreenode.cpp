#include "binarytreenode.h"

BinaryTreeNode *BinaryTreeNode::getLeft() const {
    return left;
}

void BinaryTreeNode::setLeft(BinaryTreeNode *left) {
    BinaryTreeNode::left = left;
}

BinaryTreeNode *BinaryTreeNode::getRight() const {
    return right;
}

void BinaryTreeNode::setRight(BinaryTreeNode *right) {
    BinaryTreeNode::right = right;
}

const string &BinaryTreeNode::getName() const {
    return name;
}

void BinaryTreeNode::setName(const string &name) {
    BinaryTreeNode::name = name;
}

int BinaryTreeNode::getFrecuency() const {
    return frecuency;
}

void BinaryTreeNode::setFrecuency(int frecuency) {
    BinaryTreeNode::frecuency = frecuency;
}

BinaryTreeNode::BinaryTreeNode(string name, int frecuency) {
    this->name = name;
    this->frecuency = frecuency;
    this->right = nullptr;
    this->left = nullptr;
}

void BinaryTreeNode::write(QJsonObject &jsonObj) const
{
    jsonObj["name"] = QString::fromStdString(name);
    jsonObj["frecuency"] = frecuency;
    jsonObj["right"] = JsonSerializer::serialize(*right);
    jsonObj["left"] = JsonSerializer::serialize(*left);
}

void BinaryTreeNode::read(const QJsonObject &jsonObj)
{
    name = jsonObj["name"].toString().toStdString();
    frecuency = jsonObj["frecuency"].toInt();
    JsonSerializer::parse(jsonObj["right"].toString(),*right);
    JsonSerializer::parse(jsonObj["left"].toString(),*left);
}
