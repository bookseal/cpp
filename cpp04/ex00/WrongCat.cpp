#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "🐱WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "🐱WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "🐱WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& op)
{
	std::cout << "🐱WrongCat assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "🐱WrongCat makeSound called" << std::endl;
}
