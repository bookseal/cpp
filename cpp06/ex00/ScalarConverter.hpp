#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define FLT_MAX 3.402823466e+38F
#define FLT_MIN 1.175494351e-38F
#define DBL_MAX 1.7976931348623158e+308
#define DBL_MIN 2.2250738585072014e-308

class ScalarConverter
{
	public:
		static void convert(std::string str);
		class ImpossibleException;
		static void checkChar(double str_d);
		static void checkInt(double str_d);
		static void checkFloat(double str_d);
		static void checkDouble(double str_d);
};


#endif