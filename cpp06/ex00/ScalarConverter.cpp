#include "ScalarConverter.hpp"

class ScalarConverter::ImpossibleException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("impossible");
		}
};

void	checkFloat(std::string str)
{
	(void)str;
}

void	checkDouble(std::string str)
{
	(void)str;

}

void	checkInt(std::string str)
{
	(void)str;

}

void	checkChar(std::string str)
{
	std::cout << "char: ";

	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "'" << str[0] << "'" << std::endl;
	else if (str.length() == 1 && isdigit(str[0]))
		std::cout << "Non displayable" << std::endl;
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		std::cout << "'" << str[1] << "'" << std::endl;
	else
		throw ScalarConverter::ImpossibleException();
}

void	ScalarConverter::convert(std::string str)
{
	checkChar(str);
	checkInt(str);
	checkFloat(str);
	checkDouble(str);
};