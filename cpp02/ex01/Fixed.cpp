#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	{
		std::cout << "💬 print value with various base 💬" << std::endl;
		std::cout << "value represented in decimal: " << value << std::endl;
		std::bitset<32> binary = value;
		std::cout << "value represented in binary: " << binary << std::endl;
		int value_hex = value;
		std::cout << "value represented in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
	int scaleFactor = 1 << this->_fractionalBits;
	
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// (*this).operator=(src);
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}