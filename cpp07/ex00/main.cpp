#include "template.hpp"
#include <iostream>
#include <string>

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int main(void)
{
	{
		pause("Test 1: int");
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 2: float");
		float a = 2.5f;
		float b = 3.5f;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 3: char");
		char a = 'a';
		char b = 'b';
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 4: string");
		std::string a = "chaine1";
		std::string b = "chaine2";
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 5: double");
		double a = 2.5;
		double b = 3.5;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 6: int const");
		int const a = 2;
		int const b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		// swap(a, b); // error: assignment of read-only reference 'a'
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	{
		pause("Test 7: float const");
		float const a = 2.5f;
		float const b = 3.5f;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		// swap(a, b); // error: assignment of read-only reference 'a'
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	return (0);
}