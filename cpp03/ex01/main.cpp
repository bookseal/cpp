#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

void displayBothAttributes(ScavTrap &a, ScavTrap &b)
{
	std::cout << "╔════════════════════════════════REPORT══════════════════════════════════╗" << std::endl;
	a.displayAttributes();
	b.displayAttributes();
	std::cout << "╚═════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
}

void displayBothAttributes(ClapTrap &a, ClapTrap &b)
{
	std::cout << "╔════════════════════════════════REPORT══════════════════════════════════╗" << std::endl;
	a.displayAttributes();
	b.displayAttributes();
	std::cout << "╚════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
}

int main( void ) 
{
	ClapTrap out;
	int idx = 0;

	out.typeLikeHuman("👀👀👀👀👀 STARTING EX01 👀👀👀👀👀", 10000);
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ScavTrap a("A");
	ScavTrap b("B");
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
		a.attack("B");
		b.takeDamage(a.getAttackDamage());
		displayBothAttributes(a, b);
	}

	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.attack("A");
	displayBothAttributes(a, b);

	out.typeLikeHuman("👏🏻👏🏼👏🏽👏🏾👏🏿 SAME AS EX00 👏🏿👏🏾👏🏽👏🏼👏🏻", 10000);
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ClapTrap c("A");
	ClapTrap d("B");
	displayBothAttributes(c, d);

	out.typeLikeHuman("Case " + out.intToString(idx++), 10000);
	return 0; 
}