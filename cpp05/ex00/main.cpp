#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat b("b", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}

	{
		std::cin.get();
		Bureaucrat b("b", 150);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}

	{
		std::cin.get();
		Bureaucrat b("b", 151);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}

	{
		std::cin.get();
		Bureaucrat b("b", 0);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}

	{
		std::cin.get();
		Bureaucrat b("b", 42);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	
	return (0);
}