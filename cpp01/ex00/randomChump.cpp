#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name){
//	Zombie* zombie = newZombie(name);

    Zombie* zombie = new Zombie;
    zombie->setName(name);


	zombie->announce();

	delete zombie;
}