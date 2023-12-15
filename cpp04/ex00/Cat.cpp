#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "😻Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "😻Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "😻Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& op)
{
	std::cout << "😻Cat assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "😻Cat makeSound called" << std::endl;
}
