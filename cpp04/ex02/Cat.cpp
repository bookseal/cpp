#include "Cat.hpp"

Cat::Cat(): AAnimal()
{
	std::cout << "🐱Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy): AAnimal()
{
	std::cout << "🐱Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "🐱Cat destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& op)
{
	std::cout << "🐱Cat assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->type = op.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, op.brain->getIdea(i));
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "🐱Cat makeSound called" << std::endl;
}
