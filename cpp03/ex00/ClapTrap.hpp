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

		void displayDead(void);
		int getAttackDamage(void) const;
		void displayAttributes(void);
		void typeLikeHuman(const std::string& sentence, unsigned int microseconds);
		std::string intToString(int value);

	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif