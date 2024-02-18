#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

class PmergeMe {
	private:
		std::vector<int> vOrigin;
		std::vector<std::pair<int, size_t> > pMain;
		std::vector<std::pair<int, size_t> > pSub;
		double startTimeVec;
		double endTimeVec;

		std::deque<int> dOrigin;
		std::deque<std::pair<int, size_t> > dMain;
		std::deque<std::pair<int, size_t> > dSub;
		double startTimeDeque;
		double endTimeDeque;

		int numLeft;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);

		std::string printBefore(int argc, char **argv);
		void printAfter();
		void printTime();

		void recordStartTime();
		void recordEndTime();
		void strToVec(const std::string &s);
		void mergeInsertSort();
		void devideAndCreateMainAndSub(std::vector<int> &vOrigin);
		std::vector<int> getInsertionOrder();
		void binarySearchInsertion(size_t i);
		void binarySearchInsertionForLeft();
		size_t binarySearchForLeft();
		size_t binarySearch(size_t i);
		void merge(std::vector<std::pair<int, size_t> > &p, int left, int med, int right);
		void pMainSort(std::vector<std::pair<int, size_t> > &p, int left, int right);
		void syncMainSub();
		void updateIdxOfMainAndSub();
		void printMainSub();
		void insertToMainAndSub(int mainNum, int subNum);
		void sortMainRecursive();
		void insertToMain();
		void insertFirstOfsortMain();
		size_t  getElementSameIdxAsNum(size_t i);

		void recordStartTimeD();
		void recordEndTimeD();
		void strToDeq(const std::string &s);
		void mergeInsertSortD();
		void devideAndCreateMainAndSubD(std::deque<int> &vOrigin);
		std::deque<int> getInsertionOrderD();
		void binarySearchInsertionD(size_t i);
		void binarySearchInsertionForLeftD();
		size_t binarySearchForLeftD();
		size_t binarySearchD(size_t i);
		void mergeD(std::deque<std::pair<int, size_t> > &p, int left, int med, int right);
		void pMainSortD(std::deque<std::pair<int, size_t> > &p, int left, int right);
		void syncMainSubD();
		void updateIdxOfMainAndSubD();
		void printMainSubD();
		void insertToMainAndSubD(int mainNum, int subNum);
		void sortMainRecursiveD();
		void insertToMainD();
		void insertFirstOfsortMainD();
		size_t  getElementSameIdxAsNumD(size_t i);
		bool isNumber(const char* str);
};
#endif