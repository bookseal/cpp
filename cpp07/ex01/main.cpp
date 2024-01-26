#include "iter.hpp"

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

template <typename T>
void print(T const &i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	pause("Test with int");
	int int_array[] = { 1, 2, 3, 4, 5 };
	::iter(int_array, 5, print);

	pause("Test with std::string");
	std::string string_array[] = { "Hello", "World", "!" };
	::iter(string_array, 3, print);

	pause("Test with double");
	double double_array[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	iter(double_array, 5, print);

	pause("Test with char");
	char char_array[] = { 'a', 'b', 'c', 'd', 'e' };
	iter(char_array, 5, print);

	return (0);
}