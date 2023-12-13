#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "👶AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "👶AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "👶AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& op)
{
	std::cout << "👶AAnimal assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}
