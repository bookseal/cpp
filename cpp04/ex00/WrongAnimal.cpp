#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong👶Animal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Wrong👶Animal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong👶Animal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& op)
{
	std::cout << "Wrong👶Animal assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong👶Animal makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}