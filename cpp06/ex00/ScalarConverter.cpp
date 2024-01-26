#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

char	DetectAndConvert::converted_char = 0;
int		DetectAndConvert::converted_int = 0;
float	DetectAndConvert::converted_float = 0;
double	DetectAndConvert::converted_double = 0;
bool	DetectAndConvert::isImpossible[4] = {false, false, false, false};

void	ScalarConverter::convert(std::string str)
{
	std::string str_trimmed = str.substr(str.find_first_not_of(" \t"), str.find_last_not_of(" \t") + 1);
	
	DetectAndConvert::detectAndConvert(str_trimmed);
	DisplayConvertedValues::displayConvertedValues(str_trimmed, DetectAndConvert::converted_char, DetectAndConvert::converted_int, DetectAndConvert::converted_float, DetectAndConvert::converted_double, DetectAndConvert::isImpossible);
};