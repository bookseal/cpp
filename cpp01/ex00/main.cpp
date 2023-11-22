#include "Zombie.hpp"

void	leaks(void)
{
	system("leaks brainz");
}

int main()
{
	atexit(leaks);

	Zombie* zombie = newZombie("Zombie 00");
	zombie->announce();
	delete zombie;

	randomChump("Zombie 01");
	
	return (0);
}