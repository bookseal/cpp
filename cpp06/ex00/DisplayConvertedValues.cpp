#include "DisplayConvertedValues.hpp"

void	DisplayConvertedValues::printImpossible()
{
	std::cout << "impossible" << std::endl;
}

void	DisplayConvertedValues::showDouble(double str_d)
{
	std::cout << std::fixed << std::setprecision(1) << str_d << std::endl;
}

void	DisplayConvertedValues::showFloat(float str_f)
{
	std::cout << std::fixed << std::setprecision(1) << str_f;
	std::cout << "f" << std::endl;
}

void	DisplayConvertedValues::showInt(int str_i, std::string str)
{
	if (std::strtod(str.c_str(), NULL) < INT_MIN || std::strtod(str.c_str(), NULL) > INT_MAX)
		printImpossible();
	else if (str_i < INT_MIN || str_i > INT_MAX)
		printImpossible();
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
	std::cout << "char   : ";
	if (isImpossible[CHAR])
		printImpossible();
	else
		showChar(str_c); 
	
	std::cout << "int    : ";
	if (isImpossible[INT])
		printImpossible();
	else
		showInt(str_i, str);	
	
	std::cout << "float  : ";
	if (isImpossible[FLOAT])
		printImpossible();
	else
		showFloat(str_f);
	
	std::cout << "double : ";
	if (isImpossible[DOUBLE])
		printImpossible();
	else
		showDouble(str_d);

	std::cout << std::endl;
}
