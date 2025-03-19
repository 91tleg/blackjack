
#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList()
{
    m_head = m_tail = nullptr;
    m_size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete m_head;
}

template <class T>
void LinkedList<T>::add(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (m_head == nullptr)
    {
        m_head = m_tail = newNode;
        m_size++;
    }
    else
    {
        m_tail->next = newNode;
        m_tail = m_tail->m_next;
        m_size++;
    }
}

template <class T>
Node<T>* LinkedList<T>::findNodeByIndex(int index)
{
    Node<T> *currentNode = m_head;
    for (int i = 0; i < index; ++i)
    {
        if (currentNode->m_next != nullptr)
        {
            currentNode = currentNode->m_next;
        }
    }
    return currentNode;
}

template <class T>
Node<T>* LinkedList<T>::findNodeByValue(T value)
{
    Node<T> *currentNode = m_head;
    while (currentNode)
    {
        if (currentNode->m_data == value)
        {
            return currentNode;
        }
        currentNode = currentNode->m_next;
    }
    return nullptr;
}

template <class T>
T LinkedList<T>::getByIndex(int index)
{
    return findNodeByIndex(index)->m_data;
}

template <class T>
void LinkedList<T>::deleteByIndex(int index)
{
    Node<T> *precedingNode = findNodeByIndex(index - 1);
    if (index == m_size)
    {
        precedingNode->m_next = nullptr;
        m_tail = precedingNode;
    }
    else if (index > 0)
    {
        precedingNode->m_next = precedingNode->m_next->m_next;
    }
    else
    {
        m_head = m_head->m_next;
    }
    m_size--;
}

template <class T>
void LinkedList<T>::deleteByValue(T value)
{
    if (m_head == nullptr)
    {
        return;
    }
    if (m_head->m_data == value)
    {
        m_head = m_head->m_next;
        m_size--;
    }

    Node<T> *precedingNode = m_head;
    Node<T> *currentNode = m_head->m_next;

    while (currentNode)
    {
        if (currentNode->getData() == value)
        {
            precedingNode->setNext(currentNode->m_next);  // Skip over value, point to next node

            if (currentNode == m_tail)
            {
                m_tail = precedingNode;
            }
            delete currentNode;
            m_size--;
        }
        precedingNode = currentNode;
        currentNode = currentNode->getNext();
    }
}

template <class T>
int LinkedList<T>::getSize()
{
    return m_size;
}
