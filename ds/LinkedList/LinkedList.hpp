
#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "Node.h"

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(T data);
    Node<T> *findNodeByIndex(int index);
    Node<T> *findNodeByValue(T value);
    T getByIndex(int index);
    void deleteByIndex(int index);
    void deleteByValue(T value);
    int getSize();

private:
    Node<T> *m_head;
    Node<T> *m_tail;
    int m_size;
};
#endif /* LinkedList_hpp */
