#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* zombie = new Zombie;
//    int *iPtr = new int;
//    *iPtr = 42;
//    int *iPtr2 = malloc(sizeof(int));
//    *iPtr2 = 0;
//
//    delete iPtr;
	zombie->setName(name);
	return (zombie);
}