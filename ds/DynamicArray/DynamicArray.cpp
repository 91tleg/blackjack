
#include "DynamicArray.hpp"

template <class T>
DynamicArray<T>::DynamicArray(int size) : m_data(new T[size])
{
    m_size = size;
    m_firstEmptyElement = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template <class T>
void DynamicArray<T>::add(T data)
{
    try
    {
        if (m_firstEmptyElement < m_size)
        {
            m_data[m_firstEmptyElement] = data;
            m_firstEmptyElement++;
        }
        else
        {
            throw m_firstEmptyElement;
        }
    }
    catch (int m_firstEmptyElement)
    {
        std::cout << "Index " << m_firstEmptyElement << " is out of bounds." << std::endl;
    }
}

template <class T>
void DynamicArray<T>::removeByElement(int index)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "Index " << index << " is out of bounds." << std::endl;
    }

    for (int i = index; i < m_firstEmptyElement - 1; i++)
    {
        m_data[i] = m_data[i + 1]; // Shift elements to the left to close the gap
    }
    m_firstEmptyElement--;
}

template <class T>
T DynamicArray<T>::getByElement(int index)
{
    try
    {
        if (index < m_size)
        {
            return m_data[index];
        }
        else
        {
            throw index;
        }
    }
    catch (int index)
    {
        std::cout << "Index " << index << " is out of bounds." << std::endl;
    }
}

template <class T>
void DynamicArray<T>::increaseArraySize()
{
    int newSize = m_size * 2; // Double the size of array
    T *newData = new T[newSize];

    for (int i = 0; i < m_size; i++)
    {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_size = newSize;
}

template <class T>
void DynamicArray<T>::decreaseArraySize()
{
    int newSize = m_size / 2; // Make the size half
    T *newData = new T[newSize];

    for (int i = 0; i < newSize; i++)
    {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_size = newSize;
}
