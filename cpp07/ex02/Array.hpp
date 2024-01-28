#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		size_t	_size;
		T*		_array;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const & src);
		~Array(void);
		Array & operator=(Array const & rhs);

		T & operator[](unsigned int i);

		size_t	size(void) const;

		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif