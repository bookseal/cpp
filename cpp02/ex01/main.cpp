#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	std::cout << std::endl << "✅00✅ Fixed a;" << std::endl;
	Fixed a(42.25f);

	// std::cout << std::endl << "✅01✅ Fixed b(a);" << std::endl;
	// Fixed b( a );

	// std::cout << std::endl << "✅02✅ Fixed c;" << std::endl;	
	// Fixed c;

	// std::cout << std::endl << "✅03✅ c = b;" << std::endl;
	// c = b;

	// std::cout << std::endl << "✅04✅ getRawBits();" << std::endl;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	// std::cout << std::endl << "✅05✅: return 0" << std::endl;
	return 0; 
}