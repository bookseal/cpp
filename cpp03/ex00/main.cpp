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
	int idx = 0;

	typeLikeHuman("👏🏻👏🏼👏🏽👏🏾👏🏿 STARTING EX00 👏🏿👏🏾👏🏽👏🏼👏🏻", 10000);
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	ClapTrap a("A");
	ClapTrap b("B");
	displayBothAttributes(a, b);

	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	displayBothAttributes(a, b);
	
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	displayBothAttributes(a, b);
	
	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.beRepaired(2);
	b.beRepaired(2);
	displayBothAttributes(a, b);

	for (int i = 0; i < 3; i++)
	{
		typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
		std::cin.get();
		a.takeDamage(6);
		displayBothAttributes(a, b);
	}

	typeLikeHuman("Case " + std::to_string(idx++) + " (Press enter...)", 10000);
	std::cin.get();
	a.attack("A");
	displayBothAttributes(a, b);

	typeLikeHuman("Case " + std::to_string(idx++), 10000);
	return 0; 
}