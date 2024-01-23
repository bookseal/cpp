#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "DetectAndConvert.hpp"
#include "DisplayConvertedValues.hpp"
#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void		convert(std::string str);
};

#endif