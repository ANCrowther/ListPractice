#include <iostream>
#include <iomanip>
#include "Shared.h"
#include "ManagerSLL.h"
#include "Node.h"

LL::ManagerSLL::ManagerSLL() {
	this->head = nullptr;
}

LL::ManagerSLL::~ManagerSLL() { 
	clearList();
}

bool LL::ManagerSLL::clearList() {
	std::cout << "List is cleared." << std::endl << std::endl;
	return clearFullList();
}

bool LL::ManagerSLL::clearFullList() {
	Node* currentNode = head;
	Node* nextNode;
	while (currentNode != nullptr) {
		nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
	delete currentNode;
	head = nullptr;
	return true;
}

void LL::ManagerSLL::deleteValue(std::string inputString, int choice) {
	deleteValueChoice(inputString, choice);
}

bool LL::ManagerSLL::deleteValueChoice(std::string inputString, int choice) {
	switch (choice) {
	case 1:
		return deleteValueLocation(inputString);
	case 2:
		return deleteIndexLocation(inputString);
	default:
		return false;
	}
}

bool LL::ManagerSLL::deleteValueLocation(std::string inputString) {
	bool isDeleted = false;
	Node* currentNode = head;

	if (currentNode == nullptr) {
		return isDeleted;
	}
	else if (currentNode->getStringValue() == inputString) {
		return deleteHeadNode();
	}
	else {
		while (currentNode->getNext()->getStringValue() != inputString) {
			currentNode = currentNode->getNext();
			if (currentNode->getNext() == nullptr) {
				break;
			}
		}
		if (currentNode->getNext() != nullptr) {
			return deleteNode(currentNode);
		}
	}
	delete currentNode;
	return isDeleted;
}

bool LL::ManagerSLL::deleteIndexLocation(std::string inputString) {
	bool isDeleted = false;
	Node* currentNode = head;
	int location = std::stoi(inputString);
	int index = 0;

	if (currentNode == nullptr) {
		return isDeleted;
	}
	else if (location == 1) {
		return deleteHeadNode();
	}
	else {
		index++;
		while ((index + 1) != location) {
			index++;
			currentNode = currentNode->getNext();
			if (currentNode->getNext() == nullptr) {
				break;
			}
		}
		if (currentNode->getNext() != nullptr) {
			return deleteNode(currentNode);
		}
	}
	delete currentNode;
	return isDeleted;
}

bool LL::ManagerSLL::deleteHeadNode() {
	Node* currentNode = head->getNext();
	delete head;
	head = currentNode;
	return true;
}

bool LL::ManagerSLL::deleteNode(Node*& currentNode) {
	Node* tempNode = currentNode->getNext();
	currentNode->setNext(tempNode->getNext());
	delete tempNode;
	return true;
}

void LL::ManagerSLL::findValue(std::string inputString, int choice) {
	findValueChoice(inputString, choice);
}

bool LL::ManagerSLL::findValueChoice(std::string inputString, int choice) {
	switch (choice) {
	case 1:
		return printValueLocation(inputString);
	case 2:
		return printIndexLocation(inputString);
	default:
		return false;
	}
}

int LL::ManagerSLL::findValueLocation(std::string inputString) {
	Node* currentNode = head;
	int output = 0;
	bool isFound = false;

	while (currentNode != nullptr) {
		output++;
		if (currentNode->getStringValue() == inputString) {
			isFound = true;
			break;
		}
		currentNode = currentNode->getNext();
	}

	if (isFound == false) {
		output = 0;
	}

	return output;
}

std::string LL::ManagerSLL::findIndexLocation(std::string inputString) {
	std::string output = "\0";
	int index = 0;
	int location = std::stoi(inputString);
	bool isFound = false;
	Node* currentNode = head;
	while (currentNode != nullptr) {
		index++;
		if (index == location) {
			output = currentNode->getStringValue();
			break;
		}
		currentNode = currentNode->getNext();
	}

	return output;
}

bool LL::ManagerSLL::insertNode(std::string inputString) {
	return insertInOrder(inputString);
}

bool LL::ManagerSLL::insertInOrder(std::string inputString) {
	bool isInserted = false;
	Node* newNode = factory.createNode(NodeTypeFactory::SLLtype, inputString);
	if (head == nullptr) {
		isInserted = insertHeadNode(newNode);
	}
	else {
		Node* currentNode = head;
		if (newNode->isNumber() == true) {
			while (currentNode->isNumber() == true &&
				currentNode->getNext() != nullptr &&
				currentNode->getNext()->isNumber() == true &&
				currentNode->getNext()->getIntValue() <= newNode->getIntValue()) {
				currentNode = currentNode->getNext();
			}

			if (currentNode->isNumber() == false || currentNode->getIntValue() > newNode->getIntValue()) {
				isInserted = insertLesserNode(newNode, currentNode);
			}
			else if (currentNode->getIntValue() == newNode->getIntValue()) {
				isInserted = false;
			}
			else {
				isInserted = insertGreaterNode(newNode, currentNode);
			}
		}
		else {
			while (currentNode->isNumber() == true &&
				currentNode->getNext() != nullptr &&
				currentNode->getNext()->isNumber() == true) {
				currentNode = currentNode->getNext();
			}
			while (currentNode->getNext() != nullptr &&
				LL::Shared::isNewStringGreater(newNode->getStringValue(), currentNode->getNext()->getStringValue()) >= 0) {
				currentNode = currentNode->getNext();
			}

			int isGreater = LL::Shared::isNewStringGreater(newNode->getStringValue(), currentNode->getStringValue());

			if (currentNode->isNumber() == false && isGreater < 0) {
				// Without this check, word node would sometimes remove all the integer nodes before it.
				isInserted = insertLesserNode(newNode, currentNode);
			}
			else if (isGreater < 0) {
				// Seems redundent, though handles assigning new head node (without integer consideration).
				isInserted = insertLesserNode(newNode, currentNode);
			}
			else if (isGreater == 0) {
				isInserted = false;
			}
			else {
				isInserted = insertGreaterNode(newNode, currentNode);
			}
		}
	}

	return isInserted;
}

bool LL::ManagerSLL::insertHeadNode(Node*& newNode) {
	head = newNode;
	return true;
}

bool LL::ManagerSLL::insertGreaterNode(Node*& newNode, Node*& currentNode) {
	newNode->setNext(currentNode->getNext());
	currentNode->setNext(newNode);
	return true;
}

bool LL::ManagerSLL::insertLesserNode(Node*& newNode, Node*& currentNode) {
	newNode->setNext(currentNode);
	head = newNode;
	return true;
}

int LL::ManagerSLL::getSizeOfList() {
	Node* currentNode = head;
	int index = 0;
	while (currentNode != nullptr) {
		index++;
		currentNode = currentNode->getNext();
	}
	delete currentNode;
	return index;
}

void LL::ManagerSLL::printList() {
	if (head != nullptr) {
		int index = 1;
		Node* printNode = head;
		while (printNode != nullptr) {
			std::cout << "Index [" << std::setw(2) << index << "] : " << printNode->getStringValue() << std::endl;
			index++;
			printNode = printNode->getNext();
		}
		std::cout << std::endl;
		delete printNode;
	}
	else {
		std::cout << "The list is currently empty." << std::endl << std::endl;
	}
}

bool LL::ManagerSLL::printValueLocation(std::string inputString) {
	int index = findValueLocation(inputString);
	if (index > 0) {
		std::cout << "\"" << inputString << "\" is at index [" << index << "]." << std::endl << std::endl;
		return true;
	}
	else {
		std::cout << inputString << " is not in the list." << std::endl << std::endl;
		return false;
	}
}

bool LL::ManagerSLL::printIndexLocation(std::string indexString) {
	std::string result = findIndexLocation(indexString);
	if (result == "\0") {
		std::cout << "Index [" << indexString << "] does not exist." << std::endl << std::endl;
		return false;
	}
	else {
		std::cout << "\"" << result << "\" is at index [" << indexString << "]." << std::endl << std::endl;
		return true;
	}
}

void LL::ManagerSLL::sizeOfList() {
	std::cout << "The list has " << getSizeOfList() << " elements." << std::endl << std::endl;
}
