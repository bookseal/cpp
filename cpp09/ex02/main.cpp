#include "PmergeMe.hpp"
#include <string>



int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe [string]" << std::endl;
		return 1;
	}
	PmergeMe p;
	std::string s = p.printBefore(argc, argv);

	p.recordStartTime();
	p.strToVec(s);
	p.mergeInsertSort();
	p.recordEndTime();

	p.recordStartTimeD();
	p.strToDeq(s);
	p.mergeInsertSortD();
	p.recordEndTimeD();

	p.printAfter();
	p.printTime();

	return 0;
}