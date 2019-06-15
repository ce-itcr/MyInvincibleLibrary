#ifndef  HUFFMANCOMPRESSION_H
#define  HUFFMANCOMPRESSION_H

#include <iostream>
#include "ListBT.h"
#include "BinaryTree.h"

using namespace std;

class HuffmanCompression {
public:
    ListBT *compress(string word);
    BinaryTree* order( ListBT *list);
    BinaryTree* listToBinaryTree( ListBT *list);
    string decompress(BinaryTree* binaryTree, string data);

    string compressedWord;
private:
    string word;
};


#endif // HUFFMANCOMPRESSION_H
