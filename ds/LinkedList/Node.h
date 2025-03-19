
#ifndef Node_h
#define Node_h

template <class T>
struct Node
{
    T m_data;
    Node<T> *m_next;
    Node()
    {
        m_data = m_next = nullptr;
    }
    Node(T data)
    {
        m_data = data;
        m_next = nullptr;
    }
};

#endif /* Node_h */
