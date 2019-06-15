#include "BinaryTree.h"


bool BinaryTree::isEmpty() {
    return root == nullptr;
}

void BinaryTree::addNode(int frecuency, string name,ListNode *node) {
    if(containsElement(root,name)) {
        cout << "Nodo " + name + " ya existe" << endl;
    }
    else {
        root = addNode(root,frecuency,name,node);
//        cout << "Nodo " + name + " agregado" << endl;
    }
}

BinaryTreeNode* BinaryTree::addNode(BinaryTreeNode *currentNode,int frecuency, string name,ListNode *node) {
    cout << "w" << endl;
    bool goRight = false;
    cout << "ww" << endl;
    if (isEmpty()) {

        return new BinaryTreeNode(name, frecuency);

    }else{
            cout << "www" << endl;
        if (currentNode == nullptr) {

            return new BinaryTreeNode(name, frecuency);

        }else if (currentNode->getRight() == nullptr && currentNode->getLeft() == nullptr){
            node->numberRepresentation += "0";
            currentNode->setLeft(addNode(currentNode->getLeft(), frecuency, name,node));

        }else if (currentNode->getRight() == nullptr && name.size() == 1) {
            for (int i = 0; i < currentNode->getLeft()->getName().size(); i++) {
                string temp;
                temp.push_back(currentNode->getLeft()->getName()[i]);
                if(name == temp){
                    node->numberRepresentation += "0";
                    currentNode->setLeft(addNode(currentNode->getLeft(),frecuency,name,node));
                }else if(i == (currentNode->getLeft()->getName().size() - 1)){
                    node->numberRepresentation += "1";
                    currentNode->setRight(addNode(currentNode->getRight(), frecuency, name,node));
                }
            }
        }else if (currentNode->getLeft() == nullptr && name.size() == 1) {
            for (int i = 0; i < currentNode->getRight()->getName().size(); i++) {
                string temp;
                temp.push_back(currentNode->getRight()->getName()[i]);
                if (name == temp) {
                    node->numberRepresentation += "1";
                    currentNode->setRight(addNode(currentNode->getRight(), frecuency, name,node));
                } else if (i == (currentNode->getRight()->getName().size() - 1)) {
                    node->numberRepresentation += "0";
                    currentNode->setLeft(addNode(currentNode->getLeft(), frecuency, name,node));
                }
            }
        }else{
            if (currentNode->getRight()) {
                for (int i = 0; i < currentNode->getRight()->getName().size(); i++) {
                    if (name[0] == currentNode->getRight()->getName()[i]) {
                        goRight = true;
                    }
                }
                if (goRight) {
                    node->numberRepresentation += "1";
                    currentNode->setRight(addNode(currentNode->getRight(), frecuency, name,node));
                } else {
                    node->numberRepresentation += "0";
                    currentNode->setLeft(addNode(currentNode->getLeft(), frecuency, name,node));
                }
            }else{
                goRight = true;
                for (int i = 0; i < currentNode->getLeft()->getName().size(); i++) {
                    if (name[0] == currentNode->getLeft()->getName()[i]) {
                        goRight = false;
                    }
                }
                if (goRight) {
                    node->numberRepresentation += "1";
                    currentNode->setRight(addNode(currentNode->getRight(), frecuency, name,node));
                } else {
                    node->numberRepresentation += "0";
                    currentNode->setLeft(addNode(currentNode->getLeft(), frecuency, name,node));
                }
            }
        }

        return currentNode;
    }
}

bool BinaryTree::containsElement(BinaryTreeNode* node,string name) {
    bool exist;
    if (node != nullptr) {
        if(node->getName() == name){
            return true;
        }
        exist = containsElement(node->getLeft(),name);
        exist += containsElement(node->getRight(),name);
    }
    return exist;
}

void BinaryTree::traverseInOrder(BinaryTreeNode* node) {
    if (node != nullptr) {
        traverseInOrder(node->getLeft());
        string hsdak = node->getName();
        cout << node->getName() << endl;
        traverseInOrder(node->getRight());
    }
}
