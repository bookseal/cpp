#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "🐶Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
	std::cout << "🐶Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "🐶Dog destructor called" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=(const Dog& op)
{
	std::cout << "🐶Dog assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "🐶Dog makeSound called" << std::endl;
}
