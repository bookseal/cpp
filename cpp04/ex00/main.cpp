#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	
	std::cout << std::endl;

	j->makeSound();
	i->makeSound();
    meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongCat();

	std::cout << std::endl;

	std::cout << wrongJ->getType() << " " << std::endl;	
	wrongJ->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl;

	delete wrongMeta;
	delete wrongJ;
	
	return 0; 
}