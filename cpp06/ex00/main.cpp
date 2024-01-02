#include "ScalarConverter.hpp"

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
		pause("Test 1: PDF");
		std::string str[] = {"0", "nan", "42.0f"};
		for (int i = 0; i < 3; i++)
			ScalarConverter::convert(str[i]);
	}
	
	{
		pause("Test 2: char");
		std::string str[] = {"48", "65", "42.0f"};
		for (int i = 0; i < 3; i++)
			ScalarConverter::convert(str[i]);
	}

	{
		pause("Test 3: int");
		std::string str[] = {"2147483647", "-2147483648", "2147483648", "-2147483649", "2147483648.0f" };
		for (int i = 0; i < 5; i++)
			ScalarConverter::convert(str[i]);
	}

	return (0);
}