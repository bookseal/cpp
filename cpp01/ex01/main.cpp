#include "Zombie.hpp"

void	leaks(void)
{
	system("leaks moar_brainz");
}

int main(){
	atexit(leaks);

	int n = 5;
	Zombie* zombies = zombieHorde(n, "ZOMBIE");
	Zombie* temp = zombies;
	
	for (int i = 0; i < n; i++){
		temp->announce();
		temp++;
	}
	std::cout << std::endl;
	
	delete[] zombies;
	return (0);
}