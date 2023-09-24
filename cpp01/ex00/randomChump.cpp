#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name){
	Zombie* zombie = newZombie(name);

	zombie->announce();
	delete zombie;
}