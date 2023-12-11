#ifndef ClapTrap_HPP
# define ClapTrap_HPP
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <string>

class ClapTrap 
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &rhs);
		~ClapTrap(void);
		
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getAttackDamage(void) const;
		void typeLikeHuman(const std::string& sentence, unsigned int microseconds);
		std::string intToString(int value);

		void displayDead(void);
		void displayAttributes(void);
		
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif