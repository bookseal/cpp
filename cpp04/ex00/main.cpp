#include "Animal.hpp"
#include "Dog.hpp"
// #include "Cat.hpp"
#include <iostream>

int main()
{
	const Dog* j = new Dog();

	std::cout << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;

	std::cout << std::endl;
	j->makeSound();

	delete j;
	return 0;
}