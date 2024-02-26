#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG] This is a debug message." << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] This is an info message." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] This is a warning message." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is an error message." << std::endl;
}


void Harl::complain(std::string level)
{
    // variable name: functions
    // Data type: HarlFunction
    // Value: { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }
    // Address of the functions
	void (Harl::*functions[4])() = \
	{ &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };



    // Strings
	std::string levels[] = { "debug", "info", "warning", "error" };

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
            // call the function
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[UNKNOWN]" << std::endl;
}
