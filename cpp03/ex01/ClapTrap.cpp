#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "👏 Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	typeLikeHuman("👏 Name constructor called", 10000);
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "👏 Copy constructor called" << std::endl;
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
	std::cout << "👏 Destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		displayDead();
		return ;
	}
	if (this->_energyPoints == 0)
	{
		typeLikeHuman("👏 ClapTrap " + this->_name + " has no energy left to attack!", 10000);
		return ;
	}
	typeLikeHuman("👏 ClapTrap " + this->_name + " 🏹 attacks " + target + ", cuasing " + std::to_string(this->_attackDamage) + " points of damage!", 10000);
	this->_energyPoints -= 1;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		displayDead();
		return ;
	}
	typeLikeHuman("🤖 ****Trap " + this->_name + " 🤕 takes " + std::to_string(amount) + " points of damage!", 10000);
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		typeLikeHuman("🤖 ****Trap " + this->_name + " has no energy left to be repaired!", 10000);
		return ;
	}
	if (this->_hitPoints == 0)
	{
		displayDead();
		std::cout << "🤖 ****Trap " << this->_name << " ☠️  is dead!" << std::endl;
		return ;
	}
	typeLikeHuman("🤖 ****Trap " + this->_name + " 🛠️ is repaired for " + std::to_string(amount) + " points!", 10000);
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void ClapTrap::displayDead(void)
{
	typeLikeHuman("👏 ClapTrap " + this->_name + " ☠️  is dead!", 10000);
}

void ClapTrap::displayAttributes(void)
{
	typeLikeHuman("║ 👏 ClapTrap " + this->_name + " has " + std::to_string(this->_hitPoints) + " hit points, " + std::to_string(this->_energyPoints) + " energy points and " + std::to_string(this->_attackDamage) + " attack damage. ║ ", 10000);
}

void ClapTrap::typeLikeHuman(const std::string& sentence, unsigned int microseconds) {
	for (size_t i = 0; i < sentence.length(); ++i) {
		std::cout << sentence[i] << std::flush; // Print character without newline and flush the stream
		usleep(microseconds); // Pause for the specified microseconds
	}
	std::cout << std::endl; // Move to the next line after the sentence is complete
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}