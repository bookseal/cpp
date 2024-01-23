#ifndef DISPLAYCONVERTEDVALUES_HPP
#define DISPLAYCONVERTEDVALUES_HPP

#include "DetectAndConvert.hpp"
#include <string>
#include <iostream>

class DisplayConvertedValues
{
	private:
		DisplayConvertedValues();
		DisplayConvertedValues(const DisplayConvertedValues& other);
		DisplayConvertedValues& operator=(const DisplayConvertedValues& other);
		~DisplayConvertedValues();
	public:
		static void		displayConvertedValues(std::string &str, char str_c, int str_i, float str_f, double str_d, bool isImpossible[4]);
		
		static void		showChar(char str_c);
		static void		showInt(int str_i, std::string str);
		static void		showFloat(float str_f);
		static void		showDouble(double str_d);		
};
#endif