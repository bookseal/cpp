#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

enum Datatype
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		IMPOSSIBLE
	};

class ScalarConverter
{
	public:
		static void		convert(std::string str);
		static Datatype detectTypeOfStr(const std::string &str);
		static Datatype detectAndConvert(const std::string& str, char& str_c, int& str_i, float& str_f, double& str_d, bool isImpossible[4]);
		static void		displayConvertedValues(const Datatype type, const std::string& str, char str_c, int str_i, float str_f, double str_d, bool isImpossible[4]);

		static void		showChar(const Datatype type, char str_c, std::string str, double str_d, bool isImpossible);
		static void		showInt(int str_i, std::string str, bool isImpossible);
		static void		showFloat(float str_f, bool isImpossible);
		static void		showDouble(double str_d);
		
		static bool		isnan(float str_f);
		static bool		isnan(double str_d);
		
		static bool		isinf(float str_f);
		static bool		isinf(double str_d);
		
		static bool		isExponentAllOnes(const char* bits, int startByte, int startBit, int numBits);
		static bool		isMantissaAllZeros(const char* bits, int numBits);
		class 			ImpossibleException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class			OverflowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif