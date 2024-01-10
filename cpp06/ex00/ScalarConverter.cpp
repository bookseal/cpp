#include "ScalarConverter.hpp"

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *ScalarConverter::OverflowException::what() const throw()
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
	memcpy(bits, &str_d, sizeof(str_d));

	bool exponentAllOnes = isExponentAllOnes(bits, 7, 0, 11);
	bool mantissaAllZeros = isMantissaAllZeros(bits, 52);

	return exponentAllOnes && mantissaAllZeros;
}

bool ScalarConverter::isinf(float str_f) {
	char bits[sizeof(str_f)];
	memcpy(bits, &str_f, sizeof(str_f));

	bool exponentAllOnes = isExponentAllOnes(bits, 3, 1, 8);
	bool mantissaAllZeros = isMantissaAllZeros(bits, 23);

	return exponentAllOnes && mantissaAllZeros;
}

void	ScalarConverter::showDouble(double str_d)
{
	std::cout << "double : ";
	if (ScalarConverter::isnan(str_d))
		std::cout << "nan" << std::endl;
	else if (ScalarConverter::isinf(str_d))
		std::cout << ((str_d < 0) ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str_d) << std::endl;
}

void	ScalarConverter::showFloat(float str_f, bool isImpossible)
{
	std::cout << "float  : ";
	if (isImpossible)
		std::cout << "impossible" << std::endl;
	else if (ScalarConverter::isnan(str_f))
		std::cout << "nanf" << std::endl;
	else if (ScalarConverter::isinf(str_f))
		std::cout << ((str_f < 0) ? "-inff" : "+inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << str_f << "f" << std::endl;
}

void	ScalarConverter::showInt(int str_i, std::string str, bool isImpossible)
{
	std::cout << "int    : ";

	if (isImpossible)
		std::cout << "impossible" << std::endl;
	else if (std::strtod(str.c_str(), NULL) < INT_MIN || std::strtod(str.c_str(), NULL) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else if (str_i < INT_MIN || str_i > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << str_i << std::endl;
}

void	ScalarConverter::showChar(Datatype type, char str_c, double str_d, bool isImpossible)
{
	std::cout << "char   : ";

	if (isImpossible)
		std::cout << "impossible" << std::endl;
	else if (type == DOUBLE && (isnan(str_d) || isinf(str_d)))
		std::cout << "impossible" << std::endl;
	else if (type == FLOAT && (isnan(static_cast<float>(str_d)) || isinf(static_cast<float>(str_d))))
		std::cout << "impossible" << std::endl;
	else if ((str_c < 32 || str_c > 126))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << str_c << "'" << std::endl;
}

void ScalarConverter::displayConvertedValues(const Datatype type, const std::string& str, char str_c, int str_i, float str_f, double str_d, bool isImpossible[4]) {
	try { showChar(type, str_c, str_d, isImpossible[CHAR]); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
		
	try { showInt(str_i, str, isImpossible[INT]); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { showFloat(str_f, isImpossible[FLOAT]); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { showDouble(str_d); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
}

bool ScalarConverter::isIntToFloatPrecisionLoss(int originalInt) {
	const int maxPreciseIntInFloat = 16777216;
	if (originalInt == 0 || (std::abs(originalInt) <= maxPreciseIntInFloat)) {
		return false;
	}

	return true;
}

bool ScalarConverter::isFloatToIntPrecisionLoss(float originalFloat) {
	int convertedInt = static_cast<int>(originalFloat);

	if (convertedInt != originalFloat) {
		return true;
	}

	return false;
}

bool ScalarConverter::isDoubleToIntPrecisionLoss(double originalDouble) {
	int convertedInt = static_cast<int>(originalDouble);

	if (convertedInt != originalDouble) {
		return true;
	}

	return false;
}

bool ScalarConverter::isDoubleToFloatPrecisionLoss(double originalDouble) {
	float convertedFloat = static_cast<float>(originalDouble);

	if (convertedFloat != originalDouble) {
		return true;
	}

	return false;
}

bool ScalarConverter::isIntOverflow(const std::string& str) {
	std::stringstream ss(str);
	long long value;
	ss >> value;

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		return true;
	}
	return false;
}

bool ScalarConverter::isFloatOverflow(const std::string& str) {
	std::stringstream ss(str);
	float value;
	ss >> value;

	if (value > FLT_MAX || value < FLT_MIN) {
		return true;
	}
	return false;
}

bool ScalarConverter::isDoubleOverflow(const std::string& str) {
	std::stringstream ss(str);
	double value;
	ss >> value;

	if (value > DBL_MAX || value < DBL_MIN) {
		return true;
	}
	return false;
}

Datatype	ScalarConverter::detectTypeOfStr(const std::string &str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return FLOAT;
	if (str == "nan" || str == "-inf" || str == "+inf")
		return DOUBLE;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;
	if (str.find('.') == std::string::npos)
		return INT;
	if (str.find('.') != std::string::npos && str.find('f', str.length() - 1 ) != std::string::npos)
		return FLOAT;
	if (str.find('.') != std::string::npos && str.find('f', str.length() - 1) == std::string::npos)
		return DOUBLE;
	return IMPOSSIBLE;
}

Datatype ScalarConverter::detectAndConvert(const std::string& str, char& str_c, int& str_i, float& str_f, double& str_d, bool isImpossible[4]) {
	Datatype type = ScalarConverter::detectTypeOfStr(str);
	switch (type) {
		case CHAR:
			str_c = str[1];
			str_i = static_cast<int>(str_c);
			str_f = static_cast<float>(str_c);
			str_d = static_cast<double>(str_c);
			break;
		case INT:
		{
			if (isIntOverflow(str))
				throw ScalarConverter::OverflowException();
			std::stringstream ss(str);
			ss >> str_i;
			if (ss.fail())
				throw ScalarConverter::ImpossibleException();
			str_c = static_cast<char>(str_i);
			if (isIntToFloatPrecisionLoss(str_i))
				isImpossible[FLOAT] = true;
			else
				str_f = static_cast<float>(str_i);
			str_d = static_cast<double>(str_i);
			break;
		}
		case FLOAT:
		{
			if (isFloatOverflow(str))
				throw ScalarConverter::OverflowException();
			str_f = strtof(str.c_str(), NULL);
			str_c = static_cast<char>(str_f);
			if (isFloatToIntPrecisionLoss(str_f))
				isImpossible[INT] = true;
			else
				str_i = static_cast<int>(str_f);
			str_d = static_cast<double>(str_f);
			break;
		}
		case DOUBLE:
		{
			if (isDoubleOverflow(str))
				throw ScalarConverter::OverflowException();
			str_d = strtod(str.c_str(), NULL);
			str_c = static_cast<char>(str_d);
			if (isDoubleToIntPrecisionLoss(str_d))
				isImpossible[INT] = true;
			else
				str_i = static_cast<int>(str_d);
			if (!isnan(str_d) && isDoubleToFloatPrecisionLoss(str_d))
				isImpossible[FLOAT] = true;
			else
				str_f = static_cast<float>(str_d);
			break;
		}
		case IMPOSSIBLE:
			throw ScalarConverter::ImpossibleException();
	}
	return type;
}

void	ScalarConverter::convert(std::string str)
{
	bool	isImpossible[4] = {false, false, false, false};
	char	str_c;
	int		str_i;
	float	str_f;
	double	str_d;

	try
	{
		Datatype type = detectAndConvert(str, str_c, str_i, str_f, str_d, isImpossible);
		displayConvertedValues(type, str, str_c, str_i, str_f, str_d, isImpossible);
	}
	catch(const ScalarConverter::OverflowException& e)
	{
		std::cout << "cha    : impossible" << std::endl;
		std::cout << "int    : impossible" << std::endl;
		std::cout << "float  : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		std::cout << std::endl;
	}
	catch(const ScalarConverter::ImpossibleException& e)
	{
		std::cerr << e.what() << '\n';
	}
};