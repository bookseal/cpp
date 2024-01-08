#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cmath>

void pause(std::string msg)
{
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int main(void)
{
	try {
		// {
			// pause("Test 1: PDF");
		// 	std::string str[] = {"0", "nan", "42.0f"};
		// 	for (int i = 0; i < 3; i++)
		// 		ScalarConverter::convert(str[i]);
		// }
		
		// {
		// 	pause("Test 2: char");
		// 	std::string str[] = {"'a'", "48", "65", "42.0f"};
		// 	for (int i = 0; i < 4; i++)
		// 		ScalarConverter::convert(str[i]);
		// }

		{
			// pause("Test 3: int");
			std::string str[] = {"2147483647", "-2147483648", "2147483648", "-2147483649", "2147483648.0f" };
			for (int i = 0; i < 5; i++)
			{
				// if (i == 3)
				// 	std::cout << "This should throw an exception:" << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}

		{
			pause("Test 4: float and double");
			std::string str[] = {"-4.2f", "4.2f", ""};
			for (int i = 0; i < 2; i++)
				ScalarConverter::convert(str[i]);
		}

		{
			pause("Test 5: infinity");
			std::string str[] = {"-inff", "+inff", "-inf", "+inf"};
			for (int i = 0; i < 4; i++)
				ScalarConverter::convert(str[i]);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}