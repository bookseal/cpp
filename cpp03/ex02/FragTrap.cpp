#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "🎯 Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	typeLikeHuman("🎯 Name constructor called", 10000);
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "🎯 Copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "🎯 Destructor called" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		displayDead();
		return ;
	}
	if (this->_energyPoints == 0)
	{
		typeLikeHuman("🎯 FragTrap " + this->_name + " has no energy left to attack!", 10000);
		return ;
	}
	typeLikeHuman("🎯 FragTrap " + this->_name + " 🏹 attacks " + target + ", cuasing " + intToString(this->_attackDamage) + " points of damage!", 10000);
	this->_energyPoints -= 1;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

void FragTrap::displayDead(void)
{
	typeLikeHuman("🎯 FragTrap " + this->_name + " ☠️  is dead!", 10000);
}

void FragTrap::displayAttributes(void)
{
	typeLikeHuman("║ 🎯 FragTrap " + this->_name + " has " + intToString(this->_hitPoints) + " hit points, " + intToString(this->_energyPoints) + " energy points and " + intToString(this->_attackDamage) + " attack damage. ║ ", 10000);
} 

void FragTrap::highFivesGuys(void)
{
	typeLikeHuman("🎯 FragTrap " + this->_name + " 🙌  wants to high five you!", 10000);
}