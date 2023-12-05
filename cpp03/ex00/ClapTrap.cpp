#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", cuasing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left to take damage!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to be repaired!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void ClapTrap::displayAttributes(void)
{
	// TODO: with various emoticons of the test based on the value of the attribute
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage." << std::endl;
}