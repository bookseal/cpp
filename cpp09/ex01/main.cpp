#include <sstream>
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    RPN rpn;
    std::istringstream iss;

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " [RPN expression]" << std::endl;
        return 1;
    }

    try {
        iss.str(argv[1]);
        std::string token;

        while (iss >> token) {
            if (token == "+") {
                rpn.add();
            } else if (token == "-") {
                rpn.sub();
            } else if (token == "*") {
                rpn.mul();
            } else if (token == "/") {
                rpn.div();
            } else if (rpn.hasTokenBracket(token) || rpn.hasTokenDicimalNumbers(token)) {
                throw std::runtime_error("Error");
            } else {
                rpn.push(std::stoi(token));
            }
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    rpn.print();

    return 0;
}