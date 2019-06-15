#ifndef HUFFMAN2_HUFFMANCOMPRESSION_H
#define HUFFMAN2_HUFFMANCOMPRESSION_H

#include <iostream>
#include "List.h"
#include "BinaryTree.h"

using namespace std;

class HuffmanCompression {
public:
    List *compress(string word);
    BinaryTree* order(List *list);
    BinaryTree* listToBinaryTree(List *list);
    string decompress(BinaryTree* binaryTree, string data);

    string compressedWord;
private:
    string word;
};


#endif //HUFFMAN2_HUFFMANCOMPRESSION_H
