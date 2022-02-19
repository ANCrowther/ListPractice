#include <iostream>
#include <vector>
#include "MenuBST.h"
#include "Shared.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

LL::MenuBST::~MenuBST() {

}

void LL::MenuBST::menu() {
	CLEARSCREEN;
	bool isDone = false;
	char menuOption;
	manager = new ManagerBST();

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

void LL::MenuBST::menuSwitch(char menuOption, bool& isDone) {
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

void LL::MenuBST::loadPremadeList() {
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

void LL::MenuBST::inputValue() {
	CLEARSCREEN;
	std::cout << "What value: ";
	std::string input;
	std::cin >> input;

	manager->insertNode(input);
	std::cout << input << " was successfully added." << std::endl << std::endl;
}

void LL::MenuBST::showList() {
	CLEARSCREEN;
	manager->printList();
}

void LL::MenuBST::getSizeOfList() {
	CLEARSCREEN;
	manager->sizeOfList();
}

void LL::MenuBST::findValue() {
	CLEARSCREEN;
	std::string input;
	std::cout << "What value do you want to look for: ";
	std::cin >> input;
	manager->findValue(input, 0);

}

void LL::MenuBST::deleteValue() {
	CLEARSCREEN;
	std::string input;
	std::cout << "What value do you want to delete: ";
	std::cin >> input;
	manager->deleteValue(input, 0);
}

void LL::MenuBST::clearList() {
	CLEARSCREEN;
	manager->clearList();
}
