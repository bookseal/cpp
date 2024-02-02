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
    std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    if (!std::regex_match(date, datePattern)) {
        throw std::invalid_argument("Invalid date format. Required format: YYYY-MM-DD.");
    }
    std::tm time = {};
    std::istringstream ss(date);
    ss >> std::get_time(&time, "%Y-%m-%d");
    if (!ss.fail()) {
        int year = time.tm_year + 1900; // tm_year is years since 1900
        int month = time.tm_mon + 1; // tm_mon is months since January [0-11]
        if (month == 2) {
            bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
            int maxDays = isLeapYear ? 29 : 28;
            if (time.tm_mday > maxDays) {
                throw std::invalid_argument("Invalid date: February in this year only has " + std::to_string(maxDays) + " days.");
            }
        }
    } else {
        throw std::invalid_argument("Failed to parse date.");
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