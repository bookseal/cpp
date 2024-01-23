#include "DisplayConvertedValues.hpp"

void	DisplayConvertedValues::showDouble(double str_d)
{
	std::cout << std::fixed << std::setprecision(1) << str_d << std::endl;
}

void	DisplayConvertedValues::showFloat(float str_f, bool isImpossible)
{
	std::cout << std::fixed << std::setprecision(1) << str_f;
	if (isImpossible)
		std::cout << "f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void	DisplayConvertedValues::showInt(int str_i, std::string str, bool isImpossible)
{
	if (std::strtod(str.c_str(), NULL) < INT_MIN || std::strtod(str.c_str(), NULL) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else if (str_i < INT_MIN || str_i > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << str_i << std::endl;
}


void	DisplayConvertedValues::showChar(char str_c)
{
	if ((str_c < 32 || str_c > 126))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << str_c << "'" << std::endl;
}

void	DisplayConvertedValues::displayConvertedValues(std::string &str, char str_c, int str_i, float str_f, double str_d, bool isImpossible[4])
{
	try { 
		std::cout << "char   : ";
		if (isImpossible[CHAR])
			throw DetectAndConvert::ImpossibleException();
		else
			showChar(str_c); 
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
		
	try {
		std::cout << "int    : ";
		if (isImpossible[INT])
			throw DetectAndConvert::ImpossibleException();
		else
			showInt(str_i, str, isImpossible[INT]);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try {
		std::cout << "float  : ";
		if (isImpossible[FLOAT])
			throw DetectAndConvert::ImpossibleException();
		else
			showFloat(str_f, isImpossible[FLOAT]);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try {
		std::cout << "double : ";
		if (isImpossible[DOUBLE])
			throw DetectAndConvert::ImpossibleException();
		else
			showDouble(str_d);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
}
