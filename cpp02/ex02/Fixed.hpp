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
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed &operator=(const Fixed &rhs);
		
		// 6 comparison operators
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		// 4 arithmetic operators
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;
		// 4 increment/decrement operators
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		// min function with two parameters
		static Fixed &min(Fixed &a, Fixed &b);
		// A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	
	private:
		// An integer to store the fixed-point number value.
		int _fixedPointValue;
		// A static constant integer to store the number of fractional bits. 
		// Its value will always be the integer literal 8
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif