#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed 
{
	public:
		Fixed(void);
        // Copy constructor
		Fixed(const Fixed &src);
        // Assignment operator
        // an operator is like a function, but it is not called like a function
        // a = b
        // a.operator=(b)
        // operator overloading
        // return type: Fixed &
        // function name: operator=
        // parameter: const Fixed &rhs
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);


		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
        // '_' means that it is a private variable
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

#endif