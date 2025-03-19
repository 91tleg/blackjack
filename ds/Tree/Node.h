
#ifndef Node_h
#define Node_h

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;

    Node()
    {
        data = 0;
        leftChild = rightChild = nullptr;
    }
    Node(int value)
    {
        data = value;
        leftChild = rightChild = nullptr;
    }
};

#endif /* Node_h */
