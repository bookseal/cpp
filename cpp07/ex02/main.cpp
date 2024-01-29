#include "Array.hpp"
#include <iostream>
#include <string>

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int	main(void)
{
	{
		pause("Testing: Empty Array<int>");
		Array<int> a;
		std::cout << "a.size(): " << a.size() << std::endl;

	}
	{
		pause("Testing: const Array<int>");
		Array<int> const a(5);
		std::cout << "a.size(): " << a.size() << std::endl;

		try
		{
			std::cout << "a[5]: " << a[5] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "a[5]: " << e.what() << std::endl;
		}
	}
	{
		pause("Testing: Array<int>");
		Array<int> a(5);
		Array<int> b(5);

		for (size_t i = 0; i < a.size(); i++)
			a[i] = i;
		for (size_t i = 0; i < b.size(); i++)
			b[i] = i + 5;
		
		std::cout << "a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "b: ";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;
	}

	{
		pause("Testing: Array<std::string>");
		Array<std::string> a(5);
		Array<std::string> b(5);

		a[0] = "Hello";
		a[1] = "World";
		a[2] = "!";
		a[3] = "I";
		a[4] = "am";

		b[0] = "a";
		b[1] = "string";
		b[2] = "array";
		b[3] = "of";
		b[4] = "5";

		std::cout << "a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "b: ";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;

		try
		{
			std::cout << "a[5]: " << a[5] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "a[5]: " << e.what() << std::endl;
		}

		try
		{
			std::cout << "b[5]: " << b[5] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "b[5]: " << e.what() << std::endl;
		}
	}

	{
		pause("Testing: Array<int> copy constructor");
		Array<int> a(5);

		for (size_t i = 0; i < a.size(); i++)
			a[i] = i;
		std::cout << "a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		Array<int> b(a);
		std::cout << "b: ";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl << std::endl;

		b[0] = 42;

		std::cout << "a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "b: ";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;
	}

	return (0);
}