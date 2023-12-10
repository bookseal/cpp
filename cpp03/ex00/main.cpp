#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

void displayBothAttributes(ClapTrap &a, ClapTrap &b)
{
	std::cout << "╔════════════════════════════════REPORT═══════════════════════════════════╗" << std::endl;
	a.displayAttributes();
	b.displayAttributes();
	std::cout << "╚═════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
}

int main( void ) 
{
	ClapTrap out;
	int idx = 0;

	out.typeLikeHuman("👏🏻👏🏼👏🏽👏🏾👏🏿 STARTING EX00 👏🏿👏🏾👏🏽👏🏼👏🏻", 10000);
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ClapTrap a("A");
	ClapTrap b("B");
	displayBothAttributes(a, b);

	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	displayBothAttributes(a, b);
	
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	displayBothAttributes(a, b);
	
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.beRepaired(2);
	b.beRepaired(2);
	displayBothAttributes(a, b);

	for (int i = 0; i < 3; i++)
	{
		out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
		std::cin.get();
		a.takeDamage(6);
		displayBothAttributes(a, b);
	}

	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.attack("A");
	displayBothAttributes(a, b);

	out.typeLikeHuman("Case " + out.intToString(idx++), 10000);
	return 0; 
}