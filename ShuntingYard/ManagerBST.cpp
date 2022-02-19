#include <iostream>
#include <iomanip>
#include "ManagerBST.h"
#include "Node.h"
#include "Shared.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

LL::ManagerBST::ManagerBST() {
	head = nullptr;
}

LL::ManagerBST::~ManagerBST() {
	clearList();
}

bool LL::ManagerBST::clearList() {

	bool isListCleared = clearFullList();
	if (isListCleared == true) {
		std::cout << "List is cleared." << std::endl << std::endl;
	}
	else {
		std::cout << "Something went wrong." << std::endl << std::endl;
	}
	return isListCleared;
}

void LL::ManagerBST::deleteValue(std::string inputString, int choice) {
	 head = deleteNode(head, inputString);
}

LL::Node* LL::ManagerBST::deleteNode(Node* currentNode, std::string inputString) {
	if (currentNode == nullptr) {
		std::cout << "\'" << inputString << "\' is not in the list." << std::endl;
		return currentNode;
	}

	if (LL::Shared::isNumberCheck(inputString) == true && currentNode->isNumber() == true) {
		int input = std::stoi(inputString);
		if (input == currentNode->getIntValue()) {
			if (currentNode->getPrevious() == nullptr && currentNode->getNext() == nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return nullptr;
			}
			else if (currentNode->getPrevious() == nullptr && currentNode->getNext() != nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return currentNode->getNext();
			}
			else if (currentNode->getPrevious() != nullptr && currentNode->getNext() == nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return currentNode->getPrevious();
			}
			else {
				std::string minValueString = findMinimum(currentNode->getNext());
				currentNode->setStringValue(minValueString);
				currentNode->setNext(deleteNode(currentNode->getNext(), minValueString));
				std::cout << "Deleting " << inputString << std::endl;
			}
		}
		else if (input < currentNode->getIntValue()) {
			currentNode->setPrevious(deleteNode(currentNode->getPrevious(), inputString));
		}
		else {
			currentNode->setNext(deleteNode(currentNode->getNext(), inputString));
		}
	}
	else if (LL::Shared::isNumberCheck(inputString) == true && currentNode->isNumber() == false) {
		currentNode->setPrevious(deleteNode(currentNode->getPrevious(), inputString));
	}
	else if (LL::Shared::isNumberCheck(inputString) == false && currentNode->isNumber() == true) {
		currentNode->setNext(deleteNode(currentNode->getNext(), inputString));
	}
	else {
		int result = LL::Shared::isNewStringGreater(inputString, currentNode->getStringValue());
		if (result == 0) {
			if (currentNode->getPrevious() == nullptr && currentNode->getNext() == nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return nullptr;
			}
			else if (currentNode->getPrevious() == nullptr && currentNode->getNext() != nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return currentNode->getNext();
			}
			else if (currentNode->getPrevious() != nullptr && currentNode->getNext() == nullptr) {
				std::cout << "Deleting " << inputString << std::endl;
				return currentNode->getPrevious();
			}
			else {
				std::string minValueString = findMinimum(currentNode->getNext());
				currentNode->setStringValue(minValueString);
				currentNode->setNext(deleteNode(currentNode->getNext(), minValueString));
				std::cout << "Deleting " << inputString << std::endl;
			}
		}
		else if (result < 0) {
			currentNode->setPrevious(deleteNode(currentNode->getPrevious(), inputString));
		}
		else {
			currentNode->setNext(deleteNode(currentNode->getNext(), inputString));
		}
	}
	return currentNode;
}

std::string LL::ManagerBST::findMinimum(Node* currentNode) {
	if (currentNode->getPrevious() != nullptr) {
		return findMinimum(currentNode->getPrevious());
	}
	return currentNode->getStringValue();
}

bool::LL::ManagerBST::insertInOrder(std::string inputString) {
	bool isInserted = false;
	Node* newNode = factory.createNode(NodeTypeFactory::BSTtype, inputString);
	if (head == nullptr) {
		isInserted = insertHeadNode(newNode);
	}
	else {
		isInserted = insertInOrder(head, newNode);
	}
	return isInserted;
}

void LL::ManagerBST::findValue(std::string inputString, int choice) {
	if (head == nullptr) {
		std::cout << "The list is currently empty."<< std::endl;
		return;
	}
	bool isFound = false;
	isFound = findValueInTree(head, inputString);
}

bool LL::ManagerBST::findValueInTree(Node* currentNode, std::string inputString) {
	if (currentNode == nullptr) {
		std::cout << "\"" << inputString << "\" is not in the list." << std::endl;
		return false;
	}

	int result = LL::Shared::isNewStringGreater(inputString, currentNode->getStringValue());
	if (result == 0) {
		std::cout << "\"" << inputString << "\" is in the list." << std::endl;
		return true;
	}
	if (result > 0) {
		findValueInTree(currentNode->getNext(), inputString);
	}
	else if (result < 0) {
		findValueInTree(currentNode->getPrevious(), inputString);
	}
}

bool LL::ManagerBST::insertNode(std::string inputString) {
	return insertInOrder(inputString);
}

void LL::ManagerBST::printList() {
	char answer;
	bool isGoodAnswer = true;
	do {
		std::cout << "[1] pre-order print." << std::endl;
		std::cout << "[2] in-order print." << std::endl;
		std::cout << "[3] post-order print." << std::endl;
		std::cout << "[4] breadth first print." << std::endl;
		std::cin >> answer;
		CLEARSCREEN;
		switch (answer) {
		case '1':
			printPreOrder(head);
			break;
		case '2':
			printInOrder(head);
			break;
		case '3':
			printPostOrder(head);
			break;
		case '4':
			printBreadthFirst(head);
			break;
		default:
			isGoodAnswer = false;
			break;
		}
	} while (isGoodAnswer == false);
}

void LL::ManagerBST::printPreOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	std::cout << currentNode->getStringValue() << std::endl;
	printPreOrder(currentNode->getPrevious());
	printPreOrder(currentNode->getNext());
}

void LL::ManagerBST::printInOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	printInOrder(currentNode->getPrevious());
	std::cout << currentNode->getStringValue() << std::endl;
	printInOrder(currentNode->getNext());
}

void LL::ManagerBST::printPostOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	printPostOrder(currentNode->getPrevious());
	printPostOrder(currentNode->getNext());
	std::cout << currentNode->getStringValue() << std::endl;
}

void LL::ManagerBST::printBreadthFirst(Node* currentNode) {
	int height = treeHeight(head);
	for (int i = 0; i < height; i = i + 1) {
		std::cout << std::endl << "Level [" << i << "]:" << std::setw((height - i) * 4) << " ";
		processCurrentLevel(head, i, ((height - i) * 4));
	}
	std::cout << std::endl << std::endl;
}

void LL::ManagerBST::processCurrentLevel(Node* currentNode, int level, int space) {
	if (currentNode == nullptr) {
		std::cout << std::setw(space) << " ";
		return;
	}
	if (level == 0) {
		std::cout  << std::setw(space) << currentNode->getStringValue();
	}
	else if (level > 0) {
		processCurrentLevel(currentNode->getPrevious(), level - 1, space);
		processCurrentLevel(currentNode->getNext(), level - 1, space);
	}
}

int LL::ManagerBST::treeHeight(Node* currentNode) {
	if (currentNode == nullptr) {
		return 0;
	}
	else {
		int leftHeight = treeHeight(currentNode->getPrevious());
		int rightHeight = treeHeight(currentNode->getNext());

		if (leftHeight > rightHeight) {
			return (leftHeight + 1);
		}
		else {
			return (rightHeight + 1);
		}
	}
}

void LL::ManagerBST::sizeOfList() {
	std::cout << "The list has " << countNode(head) << " elements." << std::endl;
	std::cout << "The height is: " << treeHeight(head) << std::endl << std::endl;
}

int LL::ManagerBST::countNode(Node* currentNode) {
	int count = 1;
	if (currentNode == nullptr) {
		return 0;
	}
	else {
		count = count + countNode(currentNode->getPrevious());
		count = count + countNode(currentNode->getNext());
		return count;
	}
}

bool LL::ManagerBST::clearFullList() {
	head = clearTree(head);
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

LL::Node* LL::ManagerBST::clearTree(Node* currentNode) {
	if (currentNode == nullptr) {
		return nullptr;
	}
	currentNode->setPrevious(currentNode->getPrevious());
	currentNode->setNext(currentNode->getNext());
	currentNode = nullptr;
	return currentNode;
}

bool LL::ManagerBST::deleteNode(Node*& deleteMeNode) {

	if (head == nullptr) {
		return true;
	}
	else {

	}

	return false;
}

bool LL::ManagerBST::deleteHeadNode() {
	return false;
}

int LL::ManagerBST::getSizeOfList() {
	return 0;
}

bool LL::ManagerBST::insertHeadNode(Node*& newNode) {
	head = newNode;
	return true;
}

bool LL::ManagerBST::insertInOrder(Node* currentNode, Node* newNode) {
	if (newNode->isNumber() == true && currentNode->isNumber() == true) {
		if (newNode->getIntValue() < currentNode->getIntValue()) {
			if (currentNode->getPrevious() == nullptr) {
				currentNode->setPrevious(newNode);
				return true;
			}
			else {
				insertInOrder(currentNode->getPrevious(), newNode);
			}
		}
		else if (newNode->getIntValue() > currentNode->getIntValue()) {
			if (currentNode->getNext() == nullptr) {
				currentNode->setNext(newNode);
				return true;
			}
			else {
				insertInOrder(currentNode->getNext(), newNode);
			}
		}
		else {
			return false;
		}
	}
	else if (newNode->isNumber() == true && currentNode->isNumber() == false) {
		if (currentNode->getPrevious() == nullptr) {
			currentNode->setPrevious(newNode);
			return true;
		}
		else {
			insertInOrder(currentNode->getPrevious(), newNode);
		}
	}
	else if (newNode->isNumber() == false && currentNode->isNumber() == true) {
		if (currentNode->getNext() == nullptr) {
			currentNode->setNext(newNode);
			return true;
		}
		else {
			insertInOrder(currentNode->getNext(), newNode);
		}
	}
	else {
		int result = LL::Shared::isNewStringGreater(newNode->getStringValue(), currentNode->getStringValue());
		if (result < 0) {
			if (currentNode->getPrevious() == nullptr) {
				currentNode->setPrevious(newNode);
				return true;
			}
			else {
				insertInOrder(currentNode->getPrevious(), newNode);
			}
		}
		else if (result > 0) {
			if (currentNode->getNext() == nullptr) {
				currentNode->setNext(newNode);
				return true;
			}
			else {
				insertInOrder(currentNode->getNext(), newNode);
			}
		}
		return false;
	}

	return false;
}
