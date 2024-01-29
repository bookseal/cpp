#include <iostream>
#include <string>
#include <vector>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	BitcoinExchange bitcoinExchange;
	bitcoinExchange.run(filename);
	return (0);
}