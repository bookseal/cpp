#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int main(void)
{
	pause("Testing with a vector of ints");
	{
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);

		try {
			std::cout << "Found " << *(easyfind(v, 5)) << std::endl;
		}
		catch (std::exception &e) { std::cout << "Error: Not found" << std::endl;}
		try {
			std::cout << "Found " << *(easyfind(v, 10)) << std::endl;
		}
		catch (std::exception &e) { std::cout << "Error: Not found" << std::endl;
		}
	}

	pause("Testing with a list of ints");
	{
		std::list<int> l;
		for (int i = 0; i < 10; i++)
			l.push_back(i);

		try {
			std::cout << "Found " << *(easyfind(l, 5)) << std::endl;
		}
		catch (std::exception &e) { std::cout << "Error: Not found" << std::endl;}
		try {
			std::cout << "Found " << *(easyfind(l, 10)) << std::endl;
		}
		catch (std::exception &e) { std::cout << "Error: Not found" << std::endl;
		}
	}

	pause("Tesing with a const vector of ints");
	{
		const std::vector<int> v;
		try {
			std::cout << "Found " << *(easyfind(v, 5)) << std::endl;
		}
		catch (std::exception &e) { std::cout << "Error: Not found" << std::endl;}
	}
	return (0);
}