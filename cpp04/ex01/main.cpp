#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void leak(void) {
	system("leaks a.out");
}

int main() {
	atexit(leak);
	Animal *animals[10];

	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	
	return 0; 
}