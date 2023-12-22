#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cin.get();
		Bureaucrat b("b", 42);
		std::cout << b << std::endl;
		Form f("f", 42, 42);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}

	{
		std::cin.get();
		Bureaucrat b("b", 99);
		std::cout << b << std::endl;
		Form f("f", 50, 30);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	return (0);
}