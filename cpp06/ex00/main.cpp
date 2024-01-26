#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cmath>

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

void test_default()
{
	try {
		{
			pause("Test 1: PDF");
			std::string str[] = {"0", "nan", "42.0f"};
			for (int i = 0; i < 3; i++)
			{
				std::cout << "str[" << i << "] = " << str[i] << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}
		
		{
			pause("Test 2: char");
			std::string str[] = {"'a'", "48", "65", "42.5f"};
			for (int i = 0; i < 4; i++)
			{
				std::cout << "str[" << i << "] = " << str[i] << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}

		{
			pause("Test 3: int");
			std::string str[] = {"25", "2147483646", "2147483647", "-2147483648", "2147483648", "-2147483649", "2147483647.0f", "2147483648.0f"};
			for (int i = 0; i < 8; i++) {
				std::cout << "str[" << i << "] = " << str[i] << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}

		{
			pause("Test 4: float and double");
			std::string str[] = {"-4.2f", "4.2f", "42f", "42.f", "42."};
			for (int i = 0; i < 5; i++)
			{
				std::cout << "str[" << i << "] = " << str[i] << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}

		{
			pause("Test 5: infinity");
			std::string str[] = {"-inff", "+inff", "-inf", "+inf"};
			for (int i = 0; i < 4; i++)
			{
				std::cout << "str[" << i << "] = " << str[i] << std::endl;
				ScalarConverter::convert(str[i]);
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

int main(int argc, char **argv)
{
	if (argc == 1)
		test_default();
	else
		ScalarConverter::convert(argv[1]);
	return (0);
}