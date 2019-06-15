#include "HuffmanCompression.h"

List *HuffmanCompression::compress(string word) {
    this->word = word;
    List *newList = new List();
    for(int i = 0; i < word.length() ; i++){
        string temp;
        temp.push_back(word[i]);
        if(!newList->search(temp)){
            newList->add_head(1,temp);
        }else{
            ListNode* tempNode = newList->m_head;
            while(tempNode) {
                if(tempNode->name == temp){
                    tempNode->frecuency++;
                }
                tempNode = tempNode->next;
            }
        }
    }
    return newList;
};

BinaryTree *HuffmanCompression::order(List *list){
    List *tempList = new List();
    ListNode *tempNode = list->m_head;
    while(tempNode){
        tempList->add_head(tempNode->frecuency,tempNode->name);
        tempNode = tempNode->next;
    }
    while(list->getM_num_nodes() != 1) {
        ListNode *tempNode1 = list->m_head;
        ListNode *tempNode2 = list->m_head->next;
        int newFrecuency = tempNode1->frecuency + tempNode2->frecuency;
        string newName = tempNode1->name + tempNode2->name;
        tempList->add_head(newFrecuency, newName);
        ListNode *newNode = new ListNode(newFrecuency,newName);
//        list->print();
        list->del_first_two(newNode);
        list->sort();
        newNode = nullptr;
        delete newNode;
    }
//    tempList->print();
    BinaryTree *bt = new BinaryTree();
    tempNode = tempList->m_head;
    while(tempNode){
        bt->addNode(tempNode->frecuency,tempNode->name,tempNode);
        tempNode = tempNode->next;
    }
    for(int i = 0; i < this->word.length() ; i++) {
        string temp;
        temp.push_back(this->word[i]);
        this->compressedWord += tempList->find(temp);
    }
    cout << compressedWord << endl;
    tempList = nullptr;
    tempNode = nullptr;
    delete tempList, tempNode;
    return bt;
};

string HuffmanCompression::decompress(BinaryTree* binaryTree, string data){
  BinaryTreeNode* tempNode = binaryTree->root;
  string decompressedData;
  for(int i = 0; i < data.length(); i++) {
      string temp;
      temp.push_back(data[i]);
      if(temp == "0"){
          tempNode = tempNode->getLeft();
      }else{
          tempNode = tempNode->getRight();
      }
      if (tempNode->getName().size() == 1){
          decompressedData += tempNode->getName();
          tempNode = binaryTree->root;
      }
  }
  return decompressedData;
};


