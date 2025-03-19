
#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include <stdio.h>
#include "Node.h"

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    void insertNode(int value);
    

private:
    Node *rootNode;
    int treeSize;
    void deleteTree(Node* node);
};

#endif /* BinaryTree_hpp */
