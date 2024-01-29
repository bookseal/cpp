#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _array(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {}

template <typename T>
Array<T>::Array(Array const & src) : _size(src._size), _array(new T[src._size])
{
    for (size_t i = 0; i < src._size; i++)
        _array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs)
{
    if (this != &rhs)
    {
        delete [] _array;
        _size = rhs._size;
        _array = new T[rhs._size];
        for (size_t i = 0; i < rhs._size; i++)
            _array[i] = rhs._array[i];
    }
    return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::exception();
    return (_array[i]);
}

template <typename T>
T const & Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (_array[i]);
}

template <typename T>
size_t Array<T>::size(void) const
{
    return (_size);
}
