#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	numLeft = -1;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		pMain = other.pMain;
		pSub = other.pSub;
		vOrigin = other.vOrigin;
		dOrigin = other.dOrigin;
		numLeft = other.numLeft;
		startTimeVec = other.startTimeVec;
		endTimeVec = other.endTimeVec;
		startTimeDeque = other.startTimeDeque;
		endTimeDeque = other.endTimeDeque;
	}
	return *this;
}

bool PmergeMe::isNumber(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

std::string PmergeMe::printBefore(int argc, char **argv) {
	std::string s;
	std::vector <int> v;

	for (int i = 1; i < argc; i++) {
		if (!isNumber(argv[i])){
			std::cerr << "Error: " << argv[i] << " is not a integer number" << std::endl;
			exit(1);
		}
		if (atoi(argv[i]) <= 0) {
			std::cerr << "Error: " << argv[i] << " must be a positive integer" << std::endl;
			exit(1);
		}
		v.push_back(atoi(argv[i]));
		s += argv[i];
		s += " ";
	}
	std::cout << "Before:  ";
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << std::setw(5) << v[i] << " ";
	}
	return s;
}

void PmergeMe::printMainSub() {
	std::cout << "Main First  : ";
	for (size_t i = 0; i < pMain.size(); i++) {
		std::cout << pMain[i].first << " ";
	}
	std::cout << std::endl;

	std::cout << "Main Second :";
	for (size_t i = 0; i < pMain.size(); i++) {
		std::cout << pMain[i].second << " ";
	}
	std::cout << std::endl;

	std::cout << "Sub First   : ";
	for (size_t i = 0; i < pSub.size(); i++) {
		std::cout << pSub[i].first << " ";
	}
	std::cout << std::endl;

	std::cout << "Sub Second  :";
	for (size_t i = 0; i < pSub.size(); i++) {
		std::cout << pSub[i].second << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

// Vector
void PmergeMe::strToVec(const std::string &s) {
	std::istringstream iss(s);
	int n = 0;

	while (iss >> n) {
		if (iss.fail()) {
			std::cerr << "Error: " << n << " is not a number" << std::endl;
			exit(1);
		}
		else if (n < 0) {
			std::cerr << "Error: " << n << " is a negative number" << std::endl;
			exit(1);
		}
		vOrigin.push_back(n);
	}
	std::cout << std::endl;
}

void PmergeMe::mergeInsertSort() {
	devideAndCreateMainAndSub(vOrigin);
	sortMainRecursive();
	insertToMain();
	if (numLeft != -1) {
		binarySearchInsertionForLeft();
	}
}

void PmergeMe::binarySearchInsertionForLeft() {
	size_t idx = binarySearchForLeft();
	pMain.insert(pMain.begin() + idx, std::make_pair(numLeft, 0));
}

size_t  PmergeMe::binarySearchForLeft() {
	size_t left = 0;
	size_t right = pMain.size();
	size_t mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (pMain[mid].first < numLeft) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

void PmergeMe::insertToMain() {
	insertFirstOfsortMain();
	std::vector<int> vInsertionOrder = getInsertionOrder();
	for (size_t i = 0; i < vInsertionOrder.size(); i++) {
		for (int j = vInsertionOrder[i]; j > 0; j--) {
			if (j > static_cast<int>(pSub.size())) {
				continue;
			}
			binarySearchInsertion(j - 1);
		}
	}
}

void PmergeMe::insertFirstOfsortMain() {
	if (pSub.empty()) {
		return;
	}
	pMain.insert(pMain.begin(), pSub[0]);
	pSub.erase(pSub.begin());
}

void PmergeMe::sortMainRecursive() {
	for (size_t i = 0; i < pMain.size(); i++) {
		pMain[i].second = i;
		pSub[i].second = i;
	}
	pMainSort(pMain, 0, pMain.size() - 1);
	syncMainSub();
	updateIdxOfMainAndSub();
}

void PmergeMe::updateIdxOfMainAndSub() {
	for (size_t i = 0; i < pMain.size(); i++) {
		pMain[i].second = i;
	}
	for (size_t i = 0; i < pSub.size(); i++) {
		pSub[i].second = i;
	}
}

void PmergeMe::syncMainSub() {
	std::vector<std::pair<int, size_t> > newPSub;
	size_t  targetIdx;

	for (size_t i = 0; i < pMain.size(); i++) {
		targetIdx = pMain[i].second;
		for (size_t second = 0; second < pMain.size(); second++) {
			if (pSub[second].second == targetIdx) {
				newPSub.push_back(pSub[second]);
				break;
			}
		}
	}
	pSub = newPSub;
}

void PmergeMe::merge(std::vector<std::pair<int, size_t> > &p, int left, int mid, int right)
{
	std::vector<std::pair<int, size_t> > temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (p[i].first < p[j].first) {
			temp[k++] = p[i++];
		} else {
			temp[k++] = p[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = p[i++];
	}
	while (j <= right) {
		temp[k++] = p[j++];
	}
	for (i = left; i <= right; i++) {
		p[i] = temp[i - left];
	}
}

void PmergeMe::pMainSort(std::vector<std::pair<int, size_t> > &p, int left, int right) {
	int mid = 0;

	if (left < right) {
		mid = left + (right - left) / 2;
		pMainSort(p, left, mid);
		pMainSort(p, mid + 1, right);
		merge(p, left, mid, right);
	}
}

void PmergeMe::binarySearchInsertion(size_t i) {
	size_t idx = binarySearch(i);
	pMain.insert(pMain.begin() + idx, pSub[i]);
	pSub.erase(pSub.begin() + i);
}

size_t PmergeMe::binarySearch(size_t i) {
	size_t left = 0;
	size_t right = getElementSameIdxAsNum(i);
	size_t mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (pMain[mid].first < pSub[i].first) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

size_t PmergeMe::getElementSameIdxAsNum(size_t i) {
	size_t right = 0;
	for (size_t j = 0; j < pMain.size(); j++) {
		if (pMain[j].second == pSub[i].second) {
			right = j;
			break;
		}
	}
	return (right);
}

std::vector<int> PmergeMe::getInsertionOrder() {
	std::vector<int> vInsertionOrder;
	vInsertionOrder.push_back(2);
	vInsertionOrder.push_back(2);

	int nbOfElements = static_cast<int>(pSub.size());
	int powerOfTwo = 2 * 2 * 2;
	int sizeOfGroup = powerOfTwo - 2;
	int sumSizeOfGroup = sizeOfGroup;

	while (sumSizeOfGroup <= nbOfElements) {
		vInsertionOrder.push_back(sizeOfGroup);
		powerOfTwo *= 2;
		sizeOfGroup = powerOfTwo - sizeOfGroup;
		sumSizeOfGroup += sizeOfGroup;
	}
	vInsertionOrder.push_back(sizeOfGroup);
	return vInsertionOrder;
}

void PmergeMe::insertToMainAndSub(int mainNum, int subNum) {
	pMain.insert(pMain.begin(), std::make_pair(mainNum, 0));
	pSub.insert(pSub.begin(), std::make_pair(subNum, 0));
}

void PmergeMe::devideAndCreateMainAndSub(std::vector<int> &v) {
	while (v.size() > 1) {
		int a = v[0];
		int b = v[v.size() - 1];

		if (a > b) {
			insertToMainAndSub(a, b);
		} else {
			insertToMainAndSub(b, a);
		}
		v.erase(v.begin());
		v.erase(v.end() - 1);
	}
	if (v.size() == 1)
		numLeft = v[0];
}

void PmergeMe::printAfter() {
	std::cout << "After:   ";
	for (size_t i = 0; i < pMain.size(); i++) {
		std::cout << std::setw(5) << pMain[i].first << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTime() {
	std::cout << "Time to process a range of " << pMain.size() << " elements: ";
	std::cout << "with std::vector : ";
	std::cout << endTimeVec - startTimeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << dMain.size() << " elements: ";
	std::cout << "with std::deque  : ";
	std::cout << endTimeDeque - startTimeDeque << " us" << std::endl;
}


void PmergeMe::recordStartTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long seconds = tv.tv_sec;
	long microSeconds = tv.tv_usec;
	startTimeVec = seconds * 1e6 + microSeconds;
}

void PmergeMe::recordEndTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long seconds = tv.tv_sec;
	long microSeconds = tv.tv_usec;
	endTimeVec = seconds * 1e6 + microSeconds;
}

// Deque
void PmergeMe::strToDeq(const std::string &s) {
	std::istringstream iss(s);
	int n = 0;

	while (iss >> n) {
		if (iss.fail()) {
			std::cerr << "Error: " << n << " is not a number" << std::endl;
			exit(1);
		}
		else if (n < 0) {
			std::cerr << "Error: " << n << " is a negative number" << std::endl;
			exit(1);
		}
		dOrigin.push_back(n);
	}
	std::cout << std::endl;
}


void PmergeMe::mergeInsertSortD() {
	devideAndCreateMainAndSubD(dOrigin);
	sortMainRecursiveD();
	insertToMainD();
	if (numLeft != -1) {
		binarySearchInsertionForLeftD();
	}
}

void PmergeMe::binarySearchInsertionForLeftD() {
	size_t idx = binarySearchForLeft();
	dMain.insert(dMain.begin() + idx, std::make_pair(numLeft, 0));
}

size_t  PmergeMe::binarySearchForLeftD() {
	size_t left = 0;
	size_t right = dMain.size();
	size_t mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (dMain[mid].first < numLeft) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

void PmergeMe::insertToMainD() {
	insertFirstOfsortMainD();
	std::deque<int> dInsertionOrder = getInsertionOrderD();
	for (size_t i = 0; i < dInsertionOrder.size(); i++) {
		for (int j = dInsertionOrder[i]; j > 0; j--) {
			if (j > static_cast<int>(dSub.size())) {
				continue;
			}
			binarySearchInsertionD(j - 1);
		}
	}
}

void PmergeMe::insertFirstOfsortMainD() {
	if (dSub.empty()) {
		return;
	}
	dMain.insert(dMain.begin(), dSub[0]);
	dSub.erase(dSub.begin());
}

void PmergeMe::sortMainRecursiveD() {
	for (size_t i = 0; i < dMain.size(); i++) {
		dMain[i].second = i;
		dSub[i].second = i;
	}
	pMainSortD(dMain, 0, dMain.size() - 1);
	syncMainSubD();
	updateIdxOfMainAndSubD();
}

void PmergeMe::updateIdxOfMainAndSubD() {
	for (size_t i = 0; i < dMain.size(); i++) {
		dMain[i].second = i;
	}
	for (size_t i = 0; i < dSub.size(); i++) {
		dSub[i].second = i;
	}
}

void PmergeMe::syncMainSubD() {
	std::deque<std::pair<int, size_t> > newDSub;
	size_t  targetIdx;

	for (size_t i = 0; i < dMain.size(); i++) {
		targetIdx = dMain[i].second;
		for (size_t second = 0; second < dMain.size(); second++) {
			if (dSub[second].second == targetIdx) {
				newDSub.push_back(dSub[second]);
				break;
			}
		}
	}
	dSub = newDSub;
}

void PmergeMe::mergeD(std::deque<std::pair<int, size_t> > &p, int left, int mid, int right)
{
	std::deque<std::pair<int, size_t> > temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (p[i].first < p[j].first) {
			temp[k++] = p[i++];
		} else {
			temp[k++] = p[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = p[i++];
	}
	while (j <= right) {
		temp[k++] = p[j++];
	}
	for (i = left; i <= right; i++) {
		p[i] = temp[i - left];
	}
}

void PmergeMe::pMainSortD(std::deque<std::pair<int, size_t> > &p, int left, int right) {
	int mid = 0;

	if (left < right) {
		mid = left + (right - left) / 2;
		pMainSortD(p, left, mid);
		pMainSortD(p, mid + 1, right);
		mergeD(p, left, mid, right);
	}
}

void PmergeMe::binarySearchInsertionD(size_t i) {
	size_t idx = binarySearchD(i);
	dMain.insert(dMain.begin() + idx, dSub[i]);
	dSub.erase(dSub.begin() + i);
}

size_t PmergeMe::binarySearchD(size_t i) {
	size_t left = 0;
	size_t right = getElementSameIdxAsNumD(i);
	size_t mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (dMain[mid].first < dSub[i].first) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

size_t PmergeMe::getElementSameIdxAsNumD(size_t i) {
	size_t right = 0;
	for (size_t j = 0; j < dMain.size(); j++) {
		if (dMain[j].second == dSub[i].second) {
			right = j;
			break;
		}
	}
	return (right);
}

std::deque<int> PmergeMe::getInsertionOrderD() {
	std::deque<int> dInsertionOrder;
	dInsertionOrder.push_back(2);
	dInsertionOrder.push_back(2);

	int nbOfElements = static_cast<int>(dSub.size());
	int powerOfTwo = 2 * 2 * 2;
	int sizeOfGroup = powerOfTwo - 2;
	int sumSizeOfGroup = sizeOfGroup;

	while (sumSizeOfGroup <= nbOfElements) {
		dInsertionOrder.push_back(sizeOfGroup);
		powerOfTwo *= 2;
		sizeOfGroup = powerOfTwo - sizeOfGroup;
		sumSizeOfGroup += sizeOfGroup;
	}
	dInsertionOrder.push_back(sizeOfGroup);
	return dInsertionOrder;
}

void PmergeMe::insertToMainAndSubD(int mainNum, int subNum) {
	dMain.insert(dMain.begin(), std::make_pair(mainNum, 0));
	dSub.insert(dSub.begin(), std::make_pair(subNum, 0));
}

void PmergeMe::devideAndCreateMainAndSubD(std::deque<int> &v) {
	while (v.size() > 1) {
		int a = v[0];
		int b = v[v.size() - 1];

		if (a > b) {
			insertToMainAndSubD(a, b);
		} else {
			insertToMainAndSubD(b, a);
		}
		v.erase(v.begin());
		v.erase(v.end() - 1);
	}
	if (v.size() == 1)
		numLeft = v[0];
}

void PmergeMe::recordStartTimeD() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long seconds = tv.tv_sec;
	long microSeconds = tv.tv_usec;
	startTimeDeque = seconds * 1e6 + microSeconds;
}

void PmergeMe::recordEndTimeD() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long seconds = tv.tv_sec;
	long microSeconds = tv.tv_usec;
	endTimeDeque = seconds * 1e6 + microSeconds;
}