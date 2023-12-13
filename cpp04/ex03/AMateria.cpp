#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "🧪AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "🧪AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "🧪AMateria type constructor called" << std::endl;
	this->_type = type;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}