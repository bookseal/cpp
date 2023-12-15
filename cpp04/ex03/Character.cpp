#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	std::cout << "🧑Character default constructor called" << std::endl;
	this->name = "default";
	this->count = 0;
	this->on_the_floor_count = 0;
	for (int i = 0; i < MAX_MATERIA; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "🧑Character constructor called" << std::endl;
	this->name = name;
	this->count = 0;
	this->on_the_floor_count = 0;
}

Character::Character(const Character& copy)
{
	std::cout << "🧑Character copy constructor called" << std::endl;
	
	this->name = copy.getName();
	deep_inventory_copy(copy, this);
	deep_on_the_floor_copy(copy, this);
}

Character::~Character()
{
	std::cout << "🧑Character destructor called" << std::endl;
	for (int i = 0; i < this->count; i++)
		delete this->inventory[i];
	for (int i = 0; i < this->on_the_floor_count; i++)
	{
		if (this->on_the_floor[i] != NULL)
			delete this->on_the_floor[i];
	}
}

Character& Character::operator=(const Character& op)
{
	std::cout << "🧑Character assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->name = op.name;
	
	deep_inventory_copy(op, this);
	deep_on_the_floor_copy(op, this);
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::deep_inventory_copy(const Character& from, Character* to)
{
	for (int i = 0; i < to->count; i++)
		delete to->inventory[i];
	to->count = from.count;
	for (int i = 0; i < to->count; i++)
		to->inventory[i] = from.inventory[i]->clone();
}

void Character::deep_on_the_floor_copy(const Character& from, Character* to)
{
	for (int i = 0; i < to->on_the_floor_count; i++)
		delete to->on_the_floor[i];
	to->on_the_floor_count = from.on_the_floor_count;
	for (int i = 0; i < to->on_the_floor_count; i++)
		to->on_the_floor[i] = from.on_the_floor[i]->clone();
}

void Character::equip(AMateria* m)
{
	// full inventory || unexisting Materia
	if (this->count == 4 || m == NULL)
		std::cout << "🧑Character 🚫 full inventory" << std::endl;
	if (m == NULL)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		// already equipped
		if (this->inventory[i] == m)
		{
			std::cout << "🧑Character 🚫failed to equip" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[this->count] = m;
			this->count++;
			std::cout << "🧑Character 🎒equipped" << std::endl;
			break ;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->count)
		return ;
	this->on_the_floor[on_the_floor_count] = this->inventory[idx];
	on_the_floor_count++;
	this->inventory[idx] = NULL;
	std::cout << "🧑Character ⏏️unequipped" << std::endl;
	this->count--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->count)
		return ;
	this->inventory[idx]->use(target);
}

