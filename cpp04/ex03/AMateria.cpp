#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "🧪AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "🧪AMateria type constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "🧪AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& op)
{
	std::cout << "🧪AMateria assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_type = op._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "🧪AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "🧪AMateria use called" << std::endl;
	(void)target;
}