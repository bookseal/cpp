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
    HarlFunction functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "debug", "info", "warning", "error" };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[UNKNOWN] This is an unknown message." << std::endl;
}
