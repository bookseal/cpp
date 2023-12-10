#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	std::cout << std::endl << "📝 testing 📝" << std::endl;

	std::cout << std::endl << "Test 0️⃣ 0️⃣";
	std::cin.get();
	Fixed a;

	std::cout << std::endl << "Test 0️⃣ 1️⃣";
	std::cin.get();
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::endl << "Test 0️⃣ 2️⃣";
	std::cin.get();
	Fixed oldA = a;
	std::cout << "Before prefix increment: " << a << std::endl;
    std::cout << "After prefix increment: " << ++a << std::endl;
    oldA = a++;
    std::cout << "After postfix increment, old value: " << oldA << std::endl;
    std::cout << "After postfix increment, new value: " << a << std::endl;

	std::cout << std::endl << "Test 0️⃣ 3️⃣";
	std::cin.get();
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << std::endl << "Test 0️⃣ 4️⃣";
	std::cin.get();
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl << "Test 0️⃣ 5️⃣";
	std::cin.get();
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0; 
}