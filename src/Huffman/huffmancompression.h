#ifndef HUFFMANCOMPRESSION_H
#define HUFFMANCOMPRESSION_H

#include <iostream>
#include "list.h"
#include "binarytree.h"

using namespace std;

class HuffmanCompression{
public:
    List *compress(string word);
    BinaryTree* order(List *list);
    BinaryTree* listToBinaryTree(List *list);
    string decompress(BinaryTree* binaryTree, string data);

    string compressedWord;
private:
    string word;
};

#endif // HUFFMANCOMPRESSION_H
