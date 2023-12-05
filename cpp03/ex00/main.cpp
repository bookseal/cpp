#include "ClapTrap.hpp"
#include <iostream>

void displayBothAttributes(ClapTrap &a, ClapTrap &b)
{
	a.displayAttributes();
	b.displayAttributes();
	std::cout << std::endl;
}

int main( void ) 
{
	ClapTrap a("A");
	ClapTrap b("B");
	displayBothAttributes(a, b);

	a.attack("B");
	b.takeDamage(2);
	displayBothAttributes(a, b);
	
	b.attack("A");
	a.takeDamage(2);
	displayBothAttributes(a, b);
	
	a.beRepaired(2);
	b.beRepaired(2);
	displayBothAttributes(a, b);
	
	return 0; 
}