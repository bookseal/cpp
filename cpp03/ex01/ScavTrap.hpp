#ifndef ScavTrap_HPP
# define ScavTrap_HPP
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &rhs);
		~ScavTrap(void);
		void attack(std::string const & target);
		void guardGate(void);
		void displayDead(void);
		void displayAttributes(void);
};

#endif