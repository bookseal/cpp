#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name);

int main(){
	int n = 5;
	
	Zombie* zombies = zombieHorde(n, "ZOMBIE");
	Zombie* temp = zombies;
	
	for (int i = 0; i < n; i++){
		temp->announce();
		temp++;
	}
	
	delete[] zombies;

	return (0);
}