#include "ScalarConverter.hpp"

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

bool	ScalarConverter::isnan(double str_d)
{
	return (str_d != str_d);
}

bool	ScalarConverter::isnan(float str_f)
{
	return (str_f != str_f);
}

bool ScalarConverter::isExponentAllOnes(const char* bits, int startByte, int startBit, int numBits) {
	bool allOnes = true;
	int bitCount = 0;

	for (int byteIndex = startByte; byteIndex >= 0 && bitCount < numBits; byteIndex--) {
		int startBitInByte = (byteIndex == startByte) ? startBit : 7;
		for (int bitIndex = startBitInByte; bitIndex >= 0 && bitCount < numBits; bitIndex--) {
			if ((bits[byteIndex] & (1 << bitIndex)) == 0) {
				allOnes = false;
				break;
			}
			bitCount++;
		}
		if (!allOnes) break;
	}

	return allOnes;
}

bool ScalarConverter::isMantissaAllZeros(const char* bits, int numBits) {
	bool allZeros = true;

	for (int i = 0; i < numBits; ++i) {
		int byteIndex = i / 8;
		int bitIndex = i % 8;
		if ((bits[byteIndex] & (1 << bitIndex)) != 0) {
			allZeros = false;
			break;
		}
	}

	return allZeros;
}

bool ScalarConverter::isinf(double str_d) {
	char bits[sizeof(str_d)];
	std::memcpy(bits, &str_d, sizeof(str_d));

	bool exponentAllOnes = isExponentAllOnes(bits, 7, 0, 11);
	bool mantissaAllZeros = isMantissaAllZeros(bits, 52);

	return exponentAllOnes && mantissaAllZeros;
}

bool ScalarConverter::isinf(float str_f) {
	char bits[sizeof(str_f)];
	std::memcpy(bits, &str_f, sizeof(str_f));

	bool exponentAllOnes = isExponentAllOnes(bits, 3, 1, 8);
	bool mantissaAllZeros = isMantissaAllZeros(bits, 23);

	return exponentAllOnes && mantissaAllZeros;
}


void	ScalarConverter::showDouble(double str_d)
{
	std::cout << "double: ";
	if (ScalarConverter::isnan(str_d))
		std::cout << "nan" << std::endl;
	else if (ScalarConverter::isinf(str_d))
		std::cout << ((str_d < 0) ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str_d) << std::endl;
}

void	ScalarConverter::showFloat(float str_f)
{
	std::cout << "float: ";
	if (ScalarConverter::isnan(str_f))
		std::cout << "nanf" << std::endl;
	else if (ScalarConverter::isinf(str_f))
		std::cout << ((str_f < 0) ? "-inff" : "+inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << str_f << "f" << std::endl;
}

void	ScalarConverter::showInt(int str_i)
{
	std::cout << "int: ";

	if (str_i < INT_MIN || str_i > INT_MAX)
		throw ScalarConverter::ImpossibleException();
	else
		std::cout << str_i << std::endl;
}

void	ScalarConverter::showChar(Datatype type, char str_c, std::string str, double str_d)
{
	std::cout << "char: ";

	if (type == DOUBLE && (isnan(str_d) || isinf(str_d)))
		throw ScalarConverter::ImpossibleException();
	else if (type == FLOAT && (isnan(static_cast<float>(str_d)) || isinf(static_cast<float>(str_d))))
		throw ScalarConverter::ImpossibleException();
	else if (str_c < 0 || str_c > 127)
		throw ScalarConverter::ImpossibleException();
	else if (type != CHAR && (str_c < 32 || str_c > 126))
		throw ScalarConverter::ImpossibleException();
	else if ((str_c < 32 || str_c > 126))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << str_c << "'" << std::endl;
}

Datatype	ScalarConverter::detectTypeOfStr(const std::string &str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return FLOAT;
	if (str == "nan" || str == "-inf" || str == "+inf")
		return DOUBLE;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;
	if (str.find('.') == std::string::npos && str.find('f') == std::string::npos)
		return INT;
	if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
		return FLOAT;
	if (str.find('.') != std::string::npos && str.find('f') == std::string::npos)
		return DOUBLE;
	return IMPOSSIBLE;
}

Datatype ScalarConverter::detectAndConvert(const std::string& str, char& str_c, int& str_i, float& str_f, double& str_d) {
    Datatype type = ScalarConverter::detectTypeOfStr(str);
    if (type == IMPOSSIBLE) {
        throw ScalarConverter::ImpossibleException();
    }

    switch (type) {
        case CHAR:
            str_c = str[1];
            str_i = static_cast<int>(str_c);
            str_f = static_cast<float>(str_c);
            str_d = static_cast<double>(str_c);
            break;
        case INT:
            str_i = static_cast<int>(std::strtod(str.c_str(), NULL));
            str_c = static_cast<char>(str_i);
            str_f = static_cast<float>(str_i);
            str_d = static_cast<double>(str_i);
            break;
        case FLOAT:
            str_f = static_cast<float>(std::strtod(str.c_str(), NULL));
            str_c = static_cast<char>(str_f);
            str_i = static_cast<int>(str_f);
            str_d = static_cast<double>(str_f);
            break;
        case DOUBLE:
            str_d = std::strtod(str.c_str(), NULL);
            str_c = static_cast<char>(str_d);
            str_i = static_cast<int>(str_d);
            str_f = static_cast<float>(str_d);
            break;
		case IMPOSSIBLE:
			throw ScalarConverter::ImpossibleException();
    }
	return type;
}

void ScalarConverter::displayConvertedValues(const Datatype type, const std::string& str, char str_c, int str_i, float str_f, double str_d) {
    try { showChar(type, str_c, str, str_d); }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
    
    // try { showInt(str_i); }
    // catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // try { showFloat(str_f); }
    // catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // try { showDouble(str_d); }
    // catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	char str_c;
    int str_i;
    float str_f;
    double str_d;

    Datatype type = detectAndConvert(str, str_c, str_i, str_f, str_d);
    displayConvertedValues(type, str, str_c, str_i, str_f, str_d);
};