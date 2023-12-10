#include "Fixed.hpp"

// Default constructor that initializes the fixed-point value to 0.
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

// An overload of the constructor that takes an integer as a parameter.
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	float scaleFactor = 1 << this->_fractionalBits;
	float value_scaled = value * scaleFactor;
	this->_fixedPointValue = value_scaled;
	{
		std::cout << std::endl;
		std::cout << "🐳 _fixedPointValue with various base 🐳" << std::endl;
		std::cout << std::dec << "in decimal: " << _fixedPointValue << std::endl;
		std::bitset<32> binary = _fixedPointValue;
		std::cout << "in binary: " << binary << std::endl;
		int value_hex = _fixedPointValue;
		std::cout << "in hexadecimal: " << std::setfill('0') << std::setw(8) << std::hex << value_hex << std::endl;
	}
}

// An overload of the constructor that takes a floating point number as parameter.
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

// A copy constructor.
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// (*this).operator=(src);
	*this = src;
}

// A destructor.
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
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

// An overload of the insertion («) operator 
// that inserts a floating-point representation of the fixed-point number 
// into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
    lhs << std::dec << rhs.toFloat();
    return lhs;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
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

Fixed Fixed::operator+(const Fixed &rhs) const
{
	std::cout << "🐳 operator+ called 🐳" << std::endl;
	std::cout << rhs << std::endl;
	std::cout << *this << std::endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	std::cout << "🐳 operator* called 🐳" << std::endl;
	std::cout << rhs << std::endl;
	std::cout << *this << std::endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// prefix increment operator
Fixed &Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

// postfix increment operator
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

