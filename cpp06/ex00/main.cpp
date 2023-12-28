#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int main(void)
{
	std::string str[] = {"0", "nan", "42.0f"};

	for (int i = 0; i < 3; i++)
		ScalarConverter::convert(str[i]);
	return (0);
}