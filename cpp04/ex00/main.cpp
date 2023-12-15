#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void leaks(void)
{
	system("leaks a.out");
}

void print(std::string str)
{
	std::cout << std::endl << std::endl;
	std::cout << "Testing: " << str;
	std::cin.get();
}

int main() {
	{
		print("Animal constructors");
		const Animal* meta = new Animal(); 
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		print("Animal getType()");
		std::cout << j->getType() << " " << std::endl; 
		std::cout << i->getType() << " " << std::endl; 
		
		print("Animal makeSound()");
		j->makeSound();
		i->makeSound();
		meta->makeSound();

		print("delete");
		delete meta;
		delete j;
		delete i;
	}
	{
		print("WrongAnimal");
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongJ = new WrongCat();

		std::cout << std::endl;

		std::cout << wrongJ->getType() << " " << std::endl;	
		wrongJ->makeSound();
		wrongMeta->makeSound();

		std::cout << std::endl;

		delete wrongMeta;
		delete wrongJ;
	}

	leaks();
	return 0; 
}