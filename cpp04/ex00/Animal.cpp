#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "👶Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "👶Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "👶Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& op)
{
	std::cout << "👶Animal assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "👶Animal makeSound called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
