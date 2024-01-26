#include "DetectAndConvert.hpp"

DetectAndConvert::DetectAndConvert() {}
DetectAndConvert::DetectAndConvert(const DetectAndConvert& other) { (void)other; }
DetectAndConvert& DetectAndConvert::operator=(const DetectAndConvert& other) { (void)other; return *this; }
DetectAndConvert::~DetectAndConvert() {}

void	DetectAndConvert::all_impossible()
{
	isImpossible[CHAR] = true;
	isImpossible[INT] = true;
	isImpossible[FLOAT] = true;
	isImpossible[DOUBLE] = true;
}

void	DetectAndConvert::convertChar(const std::string& str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		converted_char = str[1];
	else if (str.length() == 1 && !isdigit(str[0]))
		converted_char = str[0];
	else
	{
		all_impossible();
		return ;
	}
	converted_int = static_cast<int>(converted_char);
	converted_float = static_cast<float>(converted_char);
	converted_double = static_cast<double>(converted_char);
}

bool	DetectAndConvert::isIntOverflow(const std::string& str)
{
	if (str[0] != '-' && str.length() > 10)
		return true;
	else if (str.length() == 10 && str[0] != '-')
	{
		if (str > "2147483647")
			return true;
	}
	else if (str.length() >= 11 && str[0] == '-')
	{
		if (str > "-2147483648")
			return true;
	}
	return false;
}

bool	DetectAndConvert::isCharOverflow(int nb)
{
	if (nb < -128 || nb > 127)
		return true;
	return false;
}

void	DetectAndConvert::convertInt(const std::string& str)
{
	std::istringstream ss(str);

	ss >> converted_int;
	if (errno == ERANGE || isIntOverflow(str))
	{
		all_impossible();
		return ;
	}
	if (isCharOverflow(converted_int))
		isImpossible[CHAR] = true;
	else
		converted_char = static_cast<char>(converted_int);
	converted_float = static_cast<float>(converted_int);
	converted_double = static_cast<double>(converted_int);
}

bool	DetectAndConvert::isnan(float nb)
{
	return nb != nb;
}

bool	DetectAndConvert::isInteger(float nb)
{
	return nb == static_cast<int>(nb);
}

void	DetectAndConvert::convertFloat(const std::string& str)
{
	errno = 0;
	converted_float = strtof(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		all_impossible();
		return ;
	}
	else if (str == "nanf" || isnan(converted_float))
	{
		isImpossible[CHAR] = true;
		isImpossible[INT] = true;
		converted_float = NAN;
		converted_double = static_cast<double>(converted_float);
	}
	else if (str == "-inff" || str == "+inff" || str == "inff")
	{
		isImpossible[CHAR] = true;
		isImpossible[INT] = true;
		converted_float = converted_float < 0 ? -INFINITY : INFINITY;
		converted_double = static_cast<double>(converted_float);
	}
	else
	{
		converted_int = static_cast<int>(converted_float);
		converted_char = static_cast<char>(converted_float);
		converted_double = static_cast<double>(converted_float);
		if (isCharOverflow(converted_float) || !isInteger(converted_float))
			isImpossible[CHAR] = true;
		if (converted_int != converted_float)
			isImpossible[INT] = true;
	}
}

bool DetectAndConvert::isnan(double number)
{
	return number != number;
}

bool DetectAndConvert::isInteger(double number)
{
	return number == static_cast<int>(number);
}

bool DetectAndConvert::isFloatOverflow(double number)
{
	return number < -FLT_MAX || number > FLT_MAX;
}

void	DetectAndConvert::convertDouble(const std::string& str)
{
	errno = 0;
	converted_double = strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		all_impossible();
		return ;
	}
	else if (str == "nan")
	{
		isImpossible[CHAR] = true;
		isImpossible[INT] = true;
		converted_double = NAN;
		converted_float = static_cast<float>(converted_double);
	}
	else if (str == "-inf" || str == "+inf" || str == "inf")
	{
		isImpossible[CHAR] = true;
		isImpossible[INT] = true;
		converted_double = converted_double < 0 ? -INFINITY : INFINITY;
		converted_float = static_cast<float>(converted_double);
	}
	else
	{
		converted_char = static_cast<char>(converted_double);
		converted_int = static_cast<int>(converted_double);
		converted_float = static_cast<float>(converted_double);
		if (isCharOverflow(converted_int) || !isInteger(converted_double))
			isImpossible[CHAR] = true;
		if (converted_int != converted_double)
			isImpossible[INT] = true;
		if (isFloatOverflow(converted_double))
			isImpossible[FLOAT] = true;
	}
}

bool DetectAndConvert::isChar(const std::string& str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	else if (str.length() == 1 && !isdigit(str[0]))
		return true;
	return false;
}

bool DetectAndConvert::isDouble(const std::string& str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	else if (str.length() > 1 && str.find('.', 0) != std::string::npos && str[str.length() - 1] != 'f')
		return true;
	else if (str.length() > 1 && str.find('.', 0) != std::string::npos && str[str.length() - 1] == 'f')
		return false;
	return false;
}

bool DetectAndConvert::isFloat(const std::string& str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	else if (str.length() > 1 && str.find('.', 0) != std::string::npos && str[str.length() - 1] == 'f')
		return true;
	return false;
}

bool DetectAndConvert::isInt(const std::string& str)
{
	if ((str.length() == 1 && isdigit(str[0])) || \
	(str.length() > 1 && str[0] == '-' && isdigit(str[1])) || \
	(str.length() > 1 && isdigit(str[0])))
		return true;
	return false;
}

void DetectAndConvert::detectAndConvert(const std::string& str)
{	
	isImpossible[CHAR] = false;
	isImpossible[INT] = false;
	isImpossible[FLOAT] = false;
	isImpossible[DOUBLE] = false;
	
	if (isChar(str))
		convertChar(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else if (isInt(str))
		convertInt(str);
	else
		all_impossible();
}
