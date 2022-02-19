#include <iostream>
#include <vector>
#include "MenuDLL.h"
#include "Shared.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

LL::MenuDLL::~MenuDLL() {

}

void LL::MenuDLL::menu() {
	bool isDone = false;
	char menuOption;
	manager = new ManagerDLL();

	while (isDone == false) {
		std::cout << "<<<<<<<<<DOUBLE LINKED LIST>>>>>>>>>" << std::endl;
		std::cout << "[1] Load premade list" << std::endl;
		std::cout << "[2] Input values" << std::endl;
		std::cout << "[3] Show list" << std::endl;
		std::cout << "[4] Get size of list" << std::endl;
		std::cout << "[5] Find value" << std::endl;
		std::cout << "[6] Delete value" << std::endl;
		std::cout << "[7] Clear list" << std::endl;
		std::cout << "[0] exit DLL" << std::endl;
		std::cin >> menuOption;

		menuSwitch(menuOption, isDone);
	}
}

void LL::MenuDLL::menuSwitch(char menuOption, bool& isDone) {
	switch (menuOption) {
	case '1':
		loadPremadeList();
		break;
	case '2':
		inputValue();
		break;
	case '3':
		showList();
		break;
	case '4':
		getSizeOfList();
		break;
	case '5':
		findValue();
		break;
	case '6':
		deleteValue();
		break;
	case '7':
		clearList();
		break;
		//case '8':
		//	
		//	break;
			//case '9':

			//	break;
	case '0':
		isDone = true;
		clearList();
		break;
	default:
		CLEARSCREEN;
		std::cout << "Invalid option." << std::endl << std::endl;
	}
}

void LL::MenuDLL::loadPremadeList() {
	CLEARSCREEN;
	int testOption = LL::Shared::getTestOption();
	CLEARSCREEN;
	std::vector<std::string> testList = LL::Shared::testLists(testOption);
	std::cout << "Unordered test list:" << std::endl;

	for (const auto& text : testList) {
		std::cout << text << " | ";
	}
	std::cout << std::endl;
	for (std::string word : testList) {
		manager->insertNode(word);
	}
}

void LL::MenuDLL::inputValue() {
	CLEARSCREEN;
	std::cout << "What value: ";
	std::string input;
	std::cin >> input;

	bool isAdded = manager->insertNode(input);
	if (isAdded) {
		std::cout << input << " was successfully added." << std::endl << std::endl;
	}
	else {
		std::cout << input << " is already in the list." << std::endl << std::endl;
	}
}

void LL::MenuDLL::showList() {
	CLEARSCREEN;
	manager->printList();
}

void LL::MenuDLL::getSizeOfList() {
	CLEARSCREEN;
	manager->sizeOfList();
}

void LL::MenuDLL::findValue() {
	CLEARSCREEN;
	std::string input;
	bool isBadSelection = false;
	do {
		char answer = findValueMenu();
		switch (answer) {
		case '1':
			std::cout << "what value: ";
			std::cin >> input;
			manager->findValue(input, 1);
			isBadSelection = false;
			break;
		case '2':
			std::cout << "what index: ";
			std::cin >> input;
			manager->findValue(input, 2);
			isBadSelection = false;
			break;
		default:
			isBadSelection = true;
			break;
		}
	} while (isBadSelection == true);
}

char LL::MenuDLL::findValueMenu() {
	std::cout << "Do you want to..." << std::endl;
	std::cout << "[1] find by value." << std::endl;
	std::cout << "[2] find by index." << std::endl;
	char input;
	std::cin >> input;
	return input;
}

void LL::MenuDLL::deleteValue() {
	CLEARSCREEN;
	std::string input;
	bool isBadSelection = false;
	do {
		char answer = deleteValueMenu();
		switch (answer) {
		case '1':
			std::cout << "what value: ";
			std::cin >> input;
			manager->deleteValue(input, 1);
			isBadSelection = false;
			break;
		case '2':
			std::cout << "what index: ";
			std::cin >> input;
			manager->deleteValue(input, 2);
			isBadSelection = false;
			break;
		default:
			isBadSelection = true;
			break;
		}
	} while (isBadSelection == true);
}

char LL::MenuDLL::deleteValueMenu() {
	std::cout << "Do you want to..." << std::endl;
	std::cout << "[1] delete by value." << std::endl;
	std::cout << "[2] delete by index." << std::endl;
	char input;
	std::cin >> input;
	return input;
}
void LL::MenuDLL::clearList() {
	CLEARSCREEN;
	manager->clearList();
}
