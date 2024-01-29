#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    if (this != &rhs) {
        // Do whatever
    }
    return *this;
}

void BitcoinExchange::run(std::string inputFile) {
    std::string data = "data.csv";
    std::map<std::string, double> priceList = convertCSVtoPriceList(data);

    printPriceList(priceList);

    calculateInput(inputFile, priceList);
};

std::map<std::string, double> BitcoinExchange::convertCSVtoPriceList(std::string filename) {
    std::map<std::string, double> priceList;
    std::ifstream file(filename);
    std::string line, date;
    double price;

    std::getline(file, line); // Ignore the first line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> price;
        priceList[date] = price;
    }
    return priceList;
}

void BitcoinExchange::printPriceList(const std::map<std::string, double> &priceList) {
    for (const auto &pair : priceList) {
        std::cout << "Date: " << pair.first << ", Price: " << pair.second << std::endl;
    }
};

void BitcoinExchange::calculateInput(std::string inputFile, std::map<std::string, double> priceList) {
    std::ifstream file(inputFile);
    std::string line, date;
    double amount, price, total = 0;

    std::getline(file, line); // Ignore the first line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> amount;
        
        if (checkValidDate(date) && checkValidAmount(amount);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            return;
        }
        price = priceList[date];
        total += amount * price;
        printResult(date, amount, total);
    }
}


void BitcoinExchange::checkValidDate(std::string date) {
    if (date.length() != 10) {
        throw std::invalid_argument("Invalid date format");
    }
    if (date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("Invalid date format");
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            throw std::invalid_argument("Invalid date format");
        }
    }
}

void BitcoinExchange::checkValidAmount(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Not a positive number.");
    }
    if (amout > INT_MAX) {
        throw std::invalid_argument("too large a number.");
}

void BitcoinExchange::printResult(std::string date, double amount, double total) {
    std::cout << date << "=> " << amount << " = " << total << std::endl;
}