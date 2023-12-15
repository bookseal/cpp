#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void leak(void) {
	system("leaks a.out");
}

void print(std::string str)
{
	std::cout << std::endl << std::endl;
	std::cout << "Testing: " << str;
	std::cin.get();
}

int main() {
	atexit(leak);
	print("Declare pointer array");
	Animal *animals[10];

	print("new Dog() and new Cat()");
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	{
		print("makeSound()");
		std::cout << std::endl;
		Animal *tmp;
		for (int i = 0; i < 5; i++)
		{
			tmp = animals[i];	
			tmp->makeSound();
		}
		std::cout << std::endl;
	}

	print("delete");
	for (int i = 0; i < 5; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	{
		print("copy Dog");
		Dog *originDog = new Dog();
		std::cout << std::endl;
		Dog copyDog = *originDog;
		copyDog.makeSound();

		print("delete originDog");
		delete originDog;

		print("check deep copy");
		std::cout << copyDog.getIdeaFromBrain(42) << std::endl;
		copyDog.makeSound();
	}

	print("leak check");
	return 0; 
}