#include "Harl.hpp"

void	leaks(void)
{
	system("leaks harl");
}

int main(int argc, char *argv[])
{
	atexit(leaks);
	
	if (argc != 2)
	{
		std::cout << "Usage: <program> <level>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	Harl harl;

	harl.complain(level);
	return 0;
}