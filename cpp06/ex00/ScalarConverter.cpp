#include "ScalarConverter.hpp"

class ScalarConverter::ImpossibleException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("impossible");
		}
};


void	ScalarConverter::checkDouble(double str_d)
{
	std::cout << "double: ";

	if (std::isnan(str_d))
		std::cout << "nan";
	else if (std::isinf(str_d))
		std::cout << ((str_d < 0) ? "-inf" : "+inf");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str_d);

	std::cout << std::endl;
}

void	ScalarConverter::checkFloat(double str_d)
{
	std::cout << "float: ";

	if (std::isnan(str_d))
		std::cout << "nanf";
	else if (std::isinf(str_d))
		std::cout << ((str_d < 0) ? "-inff" : "+inff");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(str_d) << "f";
	std::cout << std::endl;
}

void	ScalarConverter::checkInt(double str_d)
{
	std::cout << "int: ";

	if (std::isnan(str_d) || std::isinf(str_d))
		throw ScalarConverter::ImpossibleException();
	else if (str_d < INT_MIN || str_d > INT_MAX)
		throw ScalarConverter::ImpossibleException();
	else
		std::cout << static_cast<int>(str_d) << std::endl;
}

void	ScalarConverter::checkChar(std::string str, double str_d)
{
	std::cout << "char: ";

	if (str.length() == 1)
	{
		char c = str[0];

		if (c < 0 || c > 127)
			throw ScalarConverter::ImpossibleException();
		else if (c < 32 || c > 126)
			std::cout << "Non displayable" << std::endl;
		else if (48 <= c && c <= 57)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << str[0] << "'" << std::endl;
	}
	else
	{
		char c = static_cast<char>(str_d);

		if (std::isnan(str_d) || std::isinf(str_d))
			throw ScalarConverter::ImpossibleException();
		else if (str_d < 0 || str_d > 127)
			throw ScalarConverter::ImpossibleException();
		else if (str_d < 32 || str_d > 126)
			std::cout << "Non displayable" << std::endl;\
		else
			std::cout << "'" << c << "'" << std::endl;
	}
}

void	ScalarConverter::convert(std::string str)
{
	double str_d = std::strtod(str.c_str(), NULL);

	try { checkChar(str, str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	
	try { checkInt(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { checkFloat(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { checkDouble(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

};