#include "Shared.h"

int LL::Shared::isNewStringGreater(std::string newNodeValue, std::string currentNodeValue) {
	return newNodeValue.compare(currentNodeValue);
}

bool LL::Shared::isNumberCheck(std::string inputString) {
	for (char const& ch : inputString) {
		if (std::isdigit(ch) == 0) {
			return false;
		}
	}
	return true;
}

std::vector<std::string> LL::Shared::testLists(int option) {
	std::vector<std::string> testList1 = { "123", "12", "321", "66", "1", "3", "66", "12" };
	std::vector<std::string> testList2 = { "alex", "cat", "zoo", "aba", "hello", "cat", "dog", "moon" };
	std::vector<std::string> testList3 = { "dog", "123", "alex", "44", "65", "hello", "cat" };
	std::vector<std::string> testList4 = { "2", "dog", "123", "alex", "44", "65", "hello", "cat" };
	std::vector<std::string> testList5 = { "dog", "123", "ajax", "44", "65", "hello", "cat","123", "hat", "12", "321", "66",
		"1", "french bread", "3", "66", "12", "ajax", "cat", "zoo", "aba", "hello", "746352","cat", "dog", "moon" };
	switch (option) {
	case 1: return testList1;
	case 2: return testList2;
	case 3: return testList3;
	case 4: return testList4;
	case 5: return testList5;
	default: return {};
	}
}

int LL::Shared::getTestOption() {
	char testOption;
	while (true) {
		std::cout << "Select number (1-5): ";
		std::cin >> testOption;
		switch (testOption) {
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		//case '6': return 6;
		default: 
			std::cout << std::endl; 
			break;
		}
	}
	return testOption;
}
