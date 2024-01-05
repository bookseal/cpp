#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(std::string str);
		static void showChar(std::string str, double str_d);
		static void showInt(double str_d);
		static void showFloat(double str_d);
		static void showDouble(double str_d);
		class ImpossibleException: public std::exception
		{
			public:
				virtual const char* what();
		};
};


#endif