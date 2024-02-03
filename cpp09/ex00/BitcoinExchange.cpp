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

void BitcoinExchange::calculateInput(std::string inputFile, std::map<std::string, double> priceList) {
	std::ifstream file(inputFile);
	std::string line, date;
	double amount, price = 0;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		try {
			checkValidDate(date);
			if (!(ss >> amount)) {
				throw std::invalid_argument("Invalid amount.");
			}
			checkValidAmount(amount);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
			continue ;
		}
		price = findPrice(date, priceList);
		printResult(date, amount, price);
	}
}

double BitcoinExchange::findPrice(std::string date, std::map<std::string, double> priceList) {
	std::map<std::string, double>::iterator it = priceList.upper_bound(date);
	if (it == priceList.begin()) {
		return it->second;
	}
	it--;
	return it->second;
}

void BitcoinExchange::checkValidDate(std::string date) {
	std::istringstream ss(date);
	int year, month, day;

	ss >> year;
	if (ss.peek() != '-') {
		throw std::invalid_argument("bad input => " + date);
	}
	ss.ignore();
	ss >> month;
	if (ss.peek() != '-') {
		throw std::invalid_argument("bad input => " + date);
	}
	ss.ignore();
	ss >> day;
	if (ss.fail()) {
		throw std::invalid_argument("bad input => " + date);
	}
	if (month < 1 || month > 12) {
		throw std::invalid_argument("bad input => " + date);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			throw std::invalid_argument("bad input => " + date);
		}
	}
	if (day < 1 || day > 31) {
		throw std::invalid_argument("bad input => " + date);
	}
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		int maxDays = isLeapYear ? 29 : 28;
		if (day > maxDays) {
			throw std::invalid_argument("bad input => " + date);
		}
	}
}

void BitcoinExchange::checkValidAmount(double amount)
{
	if (amount <= 0)
		throw std::invalid_argument("not a positive number.");
	if (amount > 1000)
		throw std::invalid_argument("too large a number.");
}

void BitcoinExchange::printResult(std::string date, double amount, double price) {
	std::cout << date << "=> " << amount << " = " << amount * price << std::endl;
}