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
		std::cout << "💬 input value with various base 💬" << std::endl;
		std::cout << std::dec << "in decimal: " << value << std::endl;
		std::bitset<32> binary(*reinterpret_cast<const unsigned int*>(&value));
		// std::bitset<32> binary = value;
		std::cout << "in binary: " << binary << std::endl;
		int value_hex = value;
		std::cout << "in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
	float scaleFactor = 1 << this->_fractionalBits;
	{
		std::cout << std::endl;
		std::cout << "*️⃣  scaleFactor with various base *️⃣" << std::endl;
		std::cout << std::dec << "in decimal: " << scaleFactor << std::endl;
		std::bitset<32> binary = scaleFactor;
		std::cout << "in binary: " << binary << std::endl;
		int value_hex = scaleFactor;
		std::cout << "in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
	float value_scaled = value * scaleFactor;
	{
		std::cout << std::endl;
		std::cout << "🦍 value_scaled with various base 🦍" << std::endl;
		std::cout << std::dec << "in decimal: " << value_scaled << std::endl;
		std::bitset<32> binary = value_scaled;
		std::cout << "in binary: " << binary << std::endl;
		int value_hex = value_scaled;
		std::cout << "in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
	this->_fixedPointValue = roundf(value_scaled);
	{
		std::cout << std::endl;
		std::cout << "🐳 _fixedPointValue with various base 🐳" << std::endl;
		std::cout << std::dec << "in decimal: " << _fixedPointValue << std::endl;
		std::bitset<32> binary = _fixedPointValue;
		std::cout << "in binary: " << binary << std::endl;
		int value_hex = _fixedPointValue;
		std::cout << "in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
	std::cout << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// (*this).operator=(src);
	*this = src;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
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

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// An overload of the insertion («) operator 
// that inserts a floating-point representation of the fixed-point number 
// into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
    lhs << std::dec << rhs.toFloat();
    return lhs;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPointValue == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixedPointValue != rhs.getRawBits());
}

