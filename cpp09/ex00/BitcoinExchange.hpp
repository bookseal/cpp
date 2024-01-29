#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <utility>

class BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        
        void run(std::string inputFile);
        std::map<std::string, double> convertCSVtoPriceList(std::string filename);
        void printPriceList(const std::map<std::string, double> &priceList);
        void calculateInput(std::string inputFile, std::map<std::string, double> priceList);
        void checkValidDate(std::string date);
        void checkValidAmount(double amount);
        void printResult(std::string date, double amount, double total);

};

#endif