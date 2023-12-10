#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h>

void typeLikeHuman(const std::string& sentence, unsigned int microseconds) {
	for (size_t i = 0; i < sentence.length(); ++i) {
		std::cout << sentence[i] << std::flush; // Print character without newline and flush the stream
		usleep(microseconds); // Pause for the specified microseconds
	}
	std::cout << std::endl; // Move to the next line after the sentence is complete
}

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
	int idx = 0;

	typeLikeHuman("🎯🎯🎯🎯🎯 STARTING EX02 🎯🎯🎯🎯🎯", 10000);
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	FragTrap e("E");
	FragTrap f("F");
	displayBothAttributes(e, f);

	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.attack("F");
	f.takeDamage(e.getAttackDamage());
	displayBothAttributes(e, f);
	
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	f.attack("E");
	e.takeDamage(f.getAttackDamage());
	displayBothAttributes(e, f);
	
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.beRepaired(2);
	f.beRepaired(2);
	displayBothAttributes(e, f);

	for (int i = 0; i < 3; i++)
	{
		typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
		std::cin.get();
		e.attack("F");
		f.takeDamage(e.getAttackDamage());
		displayBothAttributes(e, f);
	}

	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	e.attack("F");
	displayBothAttributes(e, f);

	typeLikeHuman("👀👀👀👀👀 SAME AS EX01 👀👀👀👀👀", 10000);
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ScavTrap a("A");
	ScavTrap b("B");
	displayBothAttributes(a, b);

	typeLikeHuman("👏🏻👏🏼👏🏽👏🏾👏🏿 SAME AS EX00 👏🏿👏🏾👏🏽👏🏼👏🏻", 10000);
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ClapTrap c("A");
	ClapTrap d("B");
	displayBothAttributes(c, d);

	typeLikeHuman("Case " + std::to_string(idx++), 10000);
	return 0; 
}