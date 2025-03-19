
#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
    rootNode = nullptr;
    treeSize = 0;
}

BinaryTree::~BinaryTree()
{
    deleteTree(rootNode);
}

void BinaryTree::insertNode(int value)
{
    if (!rootNode)
    {
        rootNode = new Node(value);
        return;
    }

    Node *currentNode = rootNode;
    while (true)
    {
        if (value < currentNode->data)
        {
            // Left subtree
            if (!currentNode->leftChild)
            {
                currentNode->leftChild = new Node(value);
                ++treeSize;
                return;
            }
            currentNode = currentNode->leftChild;
        }
        else
        {
            // Right subtree
            if (!currentNode->rightChild)
            {
                currentNode->rightChild = new Node(value);
                ++treeSize;
                return;
            }
            currentNode = currentNode->rightChild;
        }
    }
}

// Delete nodes in the tree using post order traversal
void BinaryTree::deleteTree(Node* currentNode)
{
    if (!currentNode)
    {
        return;
    }
    deleteTree(currentNode->leftChild);
    deleteTree(currentNode->rightChild);
    delete currentNode;
}

