#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "🧠Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "🧠Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "🧠Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& op)
{
	std::cout << "🧠Brain assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = op.ideas[i];
	return (*this);
}
