
#ifndef DynamicArray_hpp
#define DynamicArray_hpp
#include <stdio.h>
#include <iostream>

template <class T>
class DynamicArray
{
public:
    DynamicArray(int size);
    ~DynamicArray();
    void add(T data);
    void removeByElement(int index);
    T getByElement(int index);
    void increaseArraySize();
    void decreaseArraySize();
    
private:
    T *m_data;
    int m_size;
    int m_firstEmptyElement;
};

#endif /* DynamicArray_hpp */
