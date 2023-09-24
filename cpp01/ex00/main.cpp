#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(){
	Zombie* zombie = newZombie("hi");
	zombie->announce();
	delete zombie;

	randomChump("hello");
	
	return (0);
}