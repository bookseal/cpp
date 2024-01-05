#include "ScalarConverter.hpp"

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

bool	ScalarConverter::isnan(double str_d)
{
	return (str_d != str_d);
}

bool ScalarConverter::isinf(double str_d) 
{
	std::uint64_t bits;
	std::memcpy(&bits, &str_d, sizeof(str_d));

	// Mask to extract exponent bits (11 bits) and check if they are all 1's
	// and mantissa (fraction part) bits are all 0's
	return (bits & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL && (bits & 0x000FFFFFFFFFFFFFULL) == 0;
}

bool ScalarConverter::isinf(float str_f) {
	std::uint32_t bits;
	std::memcpy(&bits, &str_f, sizeof(str_f));

	// Mask to extract exponent bits (8 bits) and check if they are all 1's
	// and mantissa (fraction part) bits are all 0's
	return (bits & 0x7F800000U) == 0x7F800000U && (bits & 0x007FFFFFU) == 0;
}

void	ScalarConverter::showDouble(double str_d)
{
	std::cout << "double: ";
	if (isnan(str_d))
		std::cout << "nan" << std::endl;
	else if (isinf(str_d))
		std::cout << ((str_d < 0) ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str_d) << std::endl;
}

void	ScalarConverter::showFloat(double str_d)
{
	std::cout << "float: ";
	if (isnan(str_d))
		std::cout << "nanf" << std::endl;
	else if (isinf(static_cast<float>(str_d)))
		std::cout << ((str_d < 0) ? "-inff" : "+inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(str_d) << "f" << std::endl;
}

void	ScalarConverter::showInt(double str_d)
{
	std::cout << "int: ";

	if (isnan(str_d) || isinf(str_d))
		throw ScalarConverter::ImpossibleException();
	else if (str_d < INT_MIN || str_d > INT_MAX)
		throw ScalarConverter::ImpossibleException();
	else
		std::cout << static_cast<int>(str_d) << std::endl;
}

void	ScalarConverter::showChar(std::string str, double str_d)
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

		if (isnan(str_d) || isinf(str_d))
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

	try { showChar(str, str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	
	try { showInt(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { showFloat(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { showDouble(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

};