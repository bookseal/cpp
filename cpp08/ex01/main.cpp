#include "Span.hpp"

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int main(void)
{
	pause("Testing with a vector of ints");
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) { std::cout << "Not found" << std::endl;}
	}

	pause("Testing with a vector of 10000 ints");
	{
		Span sp = Span(10000);
		for (int i = 0; i < 10000; i++)
			sp.addNumber(i);
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) { std::cout << "Not found" << std::endl;}
	}

	return (0);
}