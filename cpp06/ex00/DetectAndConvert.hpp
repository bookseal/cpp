#ifndef DETECTANDCONVERT_HPP
#define DETECTANDCONVERT_HPP

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cfloat>


#define	CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class DetectAndConvert
{
	private:
		DetectAndConvert();
		DetectAndConvert(const DetectAndConvert& other);
		DetectAndConvert& operator=(const DetectAndConvert& other);
		~DetectAndConvert();
	public:
		static char		converted_char;
		static int		converted_int;
		static float	converted_float;
		static double	converted_double;
		static bool		isImpossible[4];

		static void		 detectAndConvert(const std::string& str);
		
		static void		convertChar(const std::string& str);
		static void		convertInt(const std::string& str);
		static void		convertFloat(const std::string& str);
		static void		convertDouble(const std::string& str);

		static bool		isnan(float str_f);
		static bool		isnan(double str_d);
		
		// static bool		isinf(float str_f);
		// static bool		isinf(double str_d);
		
		// static bool		isExponentAllOnes(const char* bits, int startByte, int startBit, int numBits);
		// static bool		isMantissaAllZeros(const char* bits, int numBits);

		static bool		isIntOverflow(const std::string& str);
		
		static bool		isFloatToIntPrecisionLoss(float originalFloat);
		static bool		isDoubleToIntPrecisionLoss(double originalDouble);
		static bool		isDoubleToFloatPrecisionLoss(double originalDouble);

		static class	OverflowException : public std::exception {
			public:
				virtual const char* what() const throw();
		} overflowException;
		static class  ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		} impossibleException;		
};

#endif

