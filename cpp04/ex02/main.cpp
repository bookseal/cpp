#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void leaks(void) {
	system("leaks a.out");
}

int main() {
	atexit(leaks);
	const Dog* j = new Dog();
	const Cat* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	
	std::cout << std::endl;

	j->makeSound();
	i->makeSound();
	
	std::cout << std::endl;

	delete j;
	delete i;
	
	return 0; 
}