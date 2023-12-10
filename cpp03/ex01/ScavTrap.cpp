#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "👀 Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	typeLikeHuman("👀 Name constructor called", 10000);
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "👀 Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "👀 Destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		displayDead();
		return ;
	}
	if (this->_energyPoints == 0)
	{
		typeLikeHuman("👀 ScavTrap " + this->_name + " has no energy left to attack!", 10000);
		return ;
	}
	typeLikeHuman("👀 ScavTrap " + this->_name + " 🏹 attacks " + target + ", cuasing " + intToString(this->_attackDamage) + " points of damage!", 10000);
	this->_energyPoints -= 1;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

void ScavTrap::displayDead(void)
{
	typeLikeHuman("👀 ScavTrap " + this->_name + " ☠️  is dead!", 10000);
}

void ScavTrap::displayAttributes(void)
{
	typeLikeHuman("║ 👀 ScavTrap " + this->_name + " has " + intToString(this->_hitPoints) + " hit points, " + intToString(this->_energyPoints) + " energy points and " + intToString(this->_attackDamage) + " attack damage. ║ ", 10000);
} 

void ScavTrap::guardGate(void)
{
	typeLikeHuman("👀 ScavTrap " + this->_name + " has entered in Gate keeper mode.", 10000);
}