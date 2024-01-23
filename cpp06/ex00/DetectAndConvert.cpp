#include "DetectAndConvert.hpp"

DetectAndConvert::DetectAndConvert() {}
DetectAndConvert::DetectAndConvert(const DetectAndConvert& other) { (void)other; }
DetectAndConvert& DetectAndConvert::operator=(const DetectAndConvert& other) { (void)other; return *this; }
DetectAndConvert::~DetectAndConvert() {}

const char* DetectAndConvert::OverflowException::what() const throw()
{
	return "OverflowException";
}

const char* DetectAndConvert::ImpossibleException::what() const throw()
{
	return "Impossible";
}

void	DetectAndConvert::convertChar(const std::string& str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		converted_char = str[1];
	else if (str.length() == 1 && !isdigit(str[0]))
		converted_char = str[0];
	else
		throw ImpossibleException();
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

void	DetectAndConvert::convertInt(const std::string& str)
{
	std::istringstream ss(str);

	ss >> converted_int;
	if (isIntOverflow(str) || ss.fail())
		throw OverflowException();
	else
	{
		converted_char = static_cast<char>(converted_int);
		converted_float = static_cast<float>(converted_int);
		converted_double = static_cast<double>(converted_int);
	}
}

bool	DetectAndConvert::isnan(float nb)
{
	return nb != nb;
}

void	DetectAndConvert::convertFloat(const std::string& str)
{
	errno = 0;
	converted_float = strtof(str.c_str(), NULL);
	if (errno == ERANGE)
		throw OverflowException();
	if (str == "nanf" || isnan(converted_float))
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
		converted_char = static_cast<char>(converted_float);
		converted_int = static_cast<int>(converted_float);
		converted_double = static_cast<double>(converted_float);
	}
}

bool DetectAndConvert::isnan(double number)
{
	return number != number;
}

void	DetectAndConvert::convertDouble(const std::string& str)
{
	errno = 0;
	converted_double = strtod(str.c_str(), NULL);
	if (errno == ERANGE)
		throw OverflowException();
	if (str == "nan")
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
	}
}

void DetectAndConvert::detectAndConvert(const std::string& str)
{	
	isImpossible[CHAR] = false;
	isImpossible[INT] = false;
	isImpossible[FLOAT] = false;
	isImpossible[DOUBLE] = false;
	
	if ((str.length() == 1 && !isdigit(str[0])) || (str.length() == 3 && str[0] == '\'' && str[2] == '\''))
		convertChar(str);
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		convertFloat(str);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		convertDouble(str);
	else if (str.length() > 1 && str.find('.', 0) != std::string::npos && str[str.length() - 1] != 'f')
		convertDouble(str);
	else if (str.length() > 1 && str.find('.', 0) != std::string::npos && str[str.length() - 1] == 'f')
		convertFloat(str);
	else if ((str.length() == 1 && isdigit(str[0])) || \
	(str.length() > 1 && str[0] == '-' && isdigit(str[1])) || \
	(str.length() > 1 && isdigit(str[0])))
		convertInt(str);
	else
		throw ImpossibleException();
}


// bool DetectAndConvert::isExponentAllOnes(const char* bits, int startByte, int startBit, int numBits)
// {
// 	bool allOnes = true;
// 	int bitCount = 0;

// 	for (int byteIndex = startByte; byteIndex >= 0 && bitCount < numBits; byteIndex--) {
// 		int startBitInByte = (byteIndex == startByte) ? startBit : 7;
// 		for (int bitIndex = startBitInByte; bitIndex >= 0 && bitCount < numBits; bitIndex--) {
// 			if ((bits[byteIndex] & (1 << bitIndex)) == 0) {
// 				allOnes = false;
// 				break;
// 			}
// 			bitCount++;
// 		}
// 		if (!allOnes) break;
// 	}

// 	return allOnes;
// }

// bool DetectAndConvert::isMantissaAllZeros(const char* bits, int numBits)
// {
// 	bool allZeros = true;

// 	for (int i = 0; i < numBits; ++i) {
// 		int byteIndex = i / 8;
// 		int bitIndex = i % 8;
// 		if ((bits[byteIndex] & (1 << bitIndex)) != 0) {
// 			allZeros = false;
// 			break;
// 		}
// 	}

// 	return allZeros;
// }