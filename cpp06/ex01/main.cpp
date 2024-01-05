
#include "Serializer.hpp"
#include <iostream>
#include <string>

void pause(std::string msg)
{
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int main(void)
{
	Data* data = new Data;

	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "Data:" << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	pause("Press ENTER to serialize...");
	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Data:" << std::endl;
	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;
	
	return (0);
}