#ifndef FragTrap_HPP
# define FragTrap_HPP
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &rhs);
		~FragTrap(void);
		void attack(std::string const & target);
		void displayDead(void);
		void displayAttributes(void);
		void highFivesGuys(void);
};

#endif