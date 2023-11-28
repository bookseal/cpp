#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <bitset>
#include <iomanip>

class Fixed 
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

#endif