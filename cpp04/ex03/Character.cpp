#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	std::cout << "🧑Character default constructor called" << std::endl;
	this->name = "default";
	this->count = 0;
}

Character::Character(std::string name)
{
	std::cout << "🧑Character constructor called" << std::endl;
	this->name = name;
	this->count = 0;
}

Character::Character(const Character& copy)
{
	std::cout << "🧑Character copy constructor called" << std::endl;
	*this = copy;
}

Character::~Character()
{
	std::cout << "🧑Character destructor called" << std::endl;
	for (int i = 0; i < this->count; i++)
		delete this->inventory[i];
}

Character& Character::operator=(const Character& op)
{
	std::cout << "🧑Character assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->name = op.name;
	for (int i = 0; i < this->count; i++)
		delete this->inventory[i];
	this->count = op.count;
	for (int i = 0; i < this->count; i++)
		this->inventory[i] = op.inventory[i]->clone();
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (this->count == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->count; i++)
		if (this->inventory[i] == m)
			return ;
	this->inventory[this->count] = m;
	this->count++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->count)
		return ;
	for (int i = idx; i < this->count - 1; i++)
		this->inventory[i] = this->inventory[i + 1];
	this->inventory[this->count - 1] = NULL;
	this->count--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->count)
		return ;
	this->inventory[idx]->use(target);
}

