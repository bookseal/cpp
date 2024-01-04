#include "comparison.hpp"
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
	{
		pause("Test int swap");
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	{
		pause("Test float swap");
		float a = 2;
		float b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}

	{
		pause("Test double min");
		double a = 2;
		double b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min = " << min(a, b) << std::endl;
	}

	{
		pause("Test int max");
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max = " << max(a, b) << std::endl;
	}
	return (0);
}