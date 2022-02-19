#include <iostream>
#include <vector>
#include "MenuAVL.h"
#include "Shared.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

LL::MenuAVL::~MenuAVL() {

}

void LL::MenuAVL::menu() {
	CLEARSCREEN;
	bool isDone = false;
	char menuOption;
	manager = new ManagerAVL();

	while (isDone == false) {
		std::cout << "<<<<<<<<BINRARY SEARCH TREE>>>>>>>>>" << std::endl;
		std::cout << "[1] Load premade list" << std::endl;
		std::cout << "[2] Input values" << std::endl;
		std::cout << "[3] Show list" << std::endl;
		std::cout << "[4] Get size of list" << std::endl;
		std::cout << "[5] Find value" << std::endl;
		std::cout << "[6] Delete value" << std::endl;
		std::cout << "[7] Clear list" << std::endl;
		std::cout << "[0] Exit BST list" << std::endl;
		std::cin >> menuOption;

		menuSwitch(menuOption, isDone);
	}
}

void LL::MenuAVL::menuSwitch(char menuOption, bool& isDone) {
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
	//case '5':
	//	findValue();
	//	break;
	//case '6':
	//	deleteValue();
	//	break;
	//case '7':
	//	clearList();
		//break;
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

void LL::MenuAVL::loadPremadeList() {
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

void LL::MenuAVL::inputValue() {
	CLEARSCREEN;
}

void LL::MenuAVL::showList() {
	CLEARSCREEN;
	manager->printList();
}

void LL::MenuAVL::getSizeOfList() {
	CLEARSCREEN;
	manager->sizeOfList();
}

void LL::MenuAVL::findValue() {
	CLEARSCREEN;
}

void LL::MenuAVL::deleteValue() {
	CLEARSCREEN;
}

void LL::MenuAVL::clearList() {
	CLEARSCREEN;
}
