#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// (*this).operator=(src);
    // '=' means that it is an assignment operator
    // 'operator=' means that it is an assignment operator
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    // 헷갈리는 게 정상
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