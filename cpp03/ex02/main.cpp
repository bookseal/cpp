#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

void displayBothAttributes(FragTrap &a, FragTrap &b)
{
	std::cout << "╔════════════════════════════════REPORT══════════════════════════════════╗" << std::endl;
	a.displayAttributes();
	b.displayAttributes();
	std::cout << "╚═════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
}

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

	out.typeLikeHuman("🎯🎯🎯🎯🎯 STARTING EX02 🎯🎯🎯🎯🎯", 10000);
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	FragTrap e("E");
	FragTrap f("F");
	displayBothAttributes(e, f);

	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.attack("F");
	f.takeDamage(e.getAttackDamage());
	displayBothAttributes(e, f);
	
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	f.attack("E");
	e.takeDamage(f.getAttackDamage());
	displayBothAttributes(e, f);
	
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.beRepaired(2);
	f.beRepaired(2);
	displayBothAttributes(e, f);

	for (int i = 0; i < 3; i++)
	{
		out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
		std::cin.get();
		e.attack("F");
		f.takeDamage(e.getAttackDamage());
		displayBothAttributes(e, f);
	}

	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.attack("F");
	displayBothAttributes(e, f);

	out.typeLikeHuman("👀👀👀👀👀 SAME AS EX01 👀👀👀👀👀", 10000);
	out.typeLikeHuman("Case " + out.intToString(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ScavTrap a("A");
	ScavTrap b("B");
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