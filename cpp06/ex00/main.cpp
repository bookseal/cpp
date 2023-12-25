#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int main(void)
{
	std::string str;

	str = "a";
	try {
		ScalarConverter::convert(str);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}