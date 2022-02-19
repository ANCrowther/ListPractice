#include <iostream>
#include "ListMenuType.h"
#include "MenuDLL.h"
#include "MenuSLL.h"
#include "MenuBST.h"
#include "MenuAVL.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

void LL::ListMenuType::menu() {
	bool isDone = false;
	char menuOption;
	CLEARSCREEN;
	while (isDone == false) {
		std::cout << "<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>" << std::endl;
		std::cout << "[1] Single Linked-List" << std::endl;
		std::cout << "[2] Double Linked-List" << std::endl;
		std::cout << "[3] Binary Search Tree" << std::endl;
		//std::cout << "[4] AVL Tree" << std::endl;
		std::cout << "[0] Exit Program" << std::endl;
		std::cin >> menuOption;

		menuSwitch(menuOption, isDone);
	}
}

void LL::ListMenuType::menuSwitch(char menuOption, bool& isDone) {
	switch (menuOption) {
	case '1':
		loadSLL();
		break;
	case '2':
		loadDLL();
		break;
	case '3':
		loadBST();
		break;
	//case '4':
	//	loadAVL();
	//	break;
	case '0':
		isDone = true;
		break;
	default:
		CLEARSCREEN;
		std::cout << "Invalid option." << std::endl << std::endl;
	}
}

void LL::ListMenuType::loadSLL() {
	CLEARSCREEN;
	MenuSLL menu;
	menu.menu();
}

void LL::ListMenuType::loadDLL() {
	CLEARSCREEN;
	MenuDLL menu;
	menu.menu();
}

void LL::ListMenuType::loadBST() {
	MenuBST menu;
	menu.menu();
	CLEARSCREEN;
}

void LL::ListMenuType::loadAVL() {
	//MenuAVL menu;
	//menu.menu();
	//CLEARSCREEN;
}
