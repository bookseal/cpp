#include "Cure.hpp"

Cure::Cure(): AMateria("Cure")
{
	std::cout << "✨Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy)
{
	std::cout << "✨Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure& op)
{
	std::cout << "✨Cure assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_type = op._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "✨Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}