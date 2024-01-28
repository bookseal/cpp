#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*		_array;
		size_t	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const & src);
		~Array(void);
		Array & operator=(Array const & rhs);

		int size(T const &array);
};

#endif