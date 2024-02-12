#include "PmergeMe.hpp"
#include <string>

std::string argvTostring(int argc, char **argv) {
    std::string s;
    for (int i = 1; i < argc; i++) {
        s += argv[i];
        s += " ";
    }
    return s;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [string]" << std::endl;
        return 1;
    }
    std::string s = argvTostring(argc, argv);
    PmergeMe p;

    p.strToVec(s);
    p.printBefore();
    p.mergeInsertSort();

    p.strToDeq(s);
    p.mergeInsertSortD();

    p.printAfter();
    p.printTime();

    return 0;
}