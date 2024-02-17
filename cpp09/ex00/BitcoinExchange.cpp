#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
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
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}
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
	std::ifstream iInput(inputFile);
	std::string line, date;
	double amount, price = 0;

	handle_fist_line(iInput);
	while (std::getline(iInput, line)) {
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

void BitcoinExchange::handle_fist_line(std::ifstream &iInput) {
	std::string line;
	std::getline(iInput, line);
	if (line != "date | value") {
		std::cout << "Error: Invalid file format." << std::endl;
		exit(1);
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

void BitcoinExchange::isFormatValid(std::string date) {
	if (date.length() != 11) {
		throw std::invalid_argument("bad input => " + date);
	}
	for (size_t i = 0; i < date.length() - 1; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') {
				throw std::invalid_argument("bad input => " + date);
			}
		}
		else if (!isdigit(date[i])) {
			throw std::invalid_argument("bad input => " + date);
		}
	}
}

void BitcoinExchange::checkValidDate(std::string date) {
	isFormatValid(date);

	std::istringstream ss(date);
	int year, month, day;
	ss >> year;
	if (ss.peek() != '-') {
		throw std::invalid_argument("bad input => " + date);
	}
	ss.ignore(); // skip '-'
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
	if (amount < 0)
		throw std::invalid_argument("not a positive number.");
	if (amount > 1000)
		throw std::invalid_argument("too large a number.");
}

void BitcoinExchange::printResult(std::string date, double amount, double price) {
	std::cout << date << "=> " << amount << " = " << amount * price << std::endl;
}