#include <iostream>
#include <iomanip>
#include "ManagerDLL.h"
#include "Node.h"
#include "Shared.h"

LL::ManagerDLL::ManagerDLL() {
	head = nullptr;
	tail = nullptr;
}

LL::ManagerDLL::~ManagerDLL() {
	clearList();
}

bool LL::ManagerDLL::insertNode(std::string inputString) {
	return insertInOrder(inputString);
}

bool LL::ManagerDLL::clearList() {
	std::cout << "List is cleared." << std::endl << std::endl;
	return clearFullList();
}

void LL::ManagerDLL::findValue(std::string inputString, int choice) {
	findValueChoice(inputString, choice);
}

void LL::ManagerDLL::deleteValue(std::string inputString, int choice) {
	if (deleteValueChoice(inputString, choice) == true) {
		std::cout << "Deleted successfully." << std::endl << std::endl;
	}
	else {
		std::cout << "Deleted failed. The element is not on the list." << std::endl << std::endl;
	}
}

void LL::ManagerDLL::printList() {
	char answer;
	bool isBadAnswer = true;

	do {
		std::cout << "[1] print list in ascending order." << std::endl;
		std::cout << "[2] print list in descending order." << std::endl;
		std::cin >> answer;
		switch (answer) {
		case '1':
			isBadAnswer = false;
			printListAscending();
			break;
		case '2':
			isBadAnswer = false;
			printListDescending();
			break;
		default:
			break;
		}
	} while (isBadAnswer == true);
}

void LL::ManagerDLL::sizeOfList() {
	int count = getSizeOfList();
	std::cout << "The list has " << count << " elements." << std::endl << std::endl;
}

bool LL::ManagerDLL::clearFullList() {
	Node* currentNode = head;
	Node* nextNode;
	while (currentNode != nullptr) {
		nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
	delete currentNode;
	head = nullptr;
	tail = nullptr;
	return true;
}

int LL::ManagerDLL::getSizeOfList() {
	int output = 0;
	Node* currentNode = head;
	while (currentNode != nullptr) {
		output++;
		currentNode = currentNode->getNext();
	}
	delete currentNode;
	return output;
}

bool LL::ManagerDLL::insertInOrder(std::string inputString) {
	bool isInserted = false;
	Node* newNode = factory.createNode(NodeTypeFactory::DLLtype, inputString);
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

			if (currentNode->getPrevious() == nullptr && currentNode->isNumber() == false) {
				isInserted = insertHeadNode(newNode);
			}
			else if (currentNode->getPrevious() == nullptr && currentNode->getIntValue() > newNode->getIntValue()) {
				isInserted = insertHeadNode(newNode);
			}
			else if (currentNode->isNumber() == true && currentNode->getIntValue() > newNode->getIntValue()) {
				currentNode = currentNode->getPrevious();
				isInserted = insertNodeInMiddle(newNode, currentNode);
			}
			else if(currentNode->getIntValue() == newNode->getIntValue()) {
				isInserted = false;
			}
			else {
				isInserted = insertNodeInMiddle(newNode, currentNode);
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

			if (currentNode->getPrevious() == nullptr && isGreater < 0) {
				isInserted = insertHeadNode(newNode);
			}
			else if (isGreater > 0) {
				isInserted = insertNodeInMiddle(newNode, currentNode);
			}
			else if (isGreater == 0) {
				isInserted = false;
			}
			else {
				currentNode = currentNode->getPrevious();
				isInserted = insertNodeInMiddle(newNode, currentNode);
			}
		}
	}

	return isInserted;
}

bool LL::ManagerDLL::insertHeadNode(Node*& newNode) {
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = head->getPrevious();
	}

	return true;
}

bool LL::ManagerDLL::insertTailNode(Node*& newNode, Node* currentNode) {
	newNode->setPrevious(currentNode);
	currentNode->setNext(newNode);

	tail->setNext(currentNode->getNext());
	tail = tail->getNext();
	tail->setPrevious(currentNode);
	
	return true;
}

bool LL::ManagerDLL::insertNodeInMiddle(Node*& newNode, Node*& currentNode) {
	if (currentNode->getNext() == nullptr) {
		return insertTailNode(newNode, currentNode);
	}
	else {
		newNode->setNext(currentNode->getNext());
		newNode->setPrevious(currentNode);
		currentNode->getNext()->setPrevious(newNode);
		currentNode->setNext(newNode);
	}

	return true;
}

bool LL::ManagerDLL::findValueChoice(std::string inputString, int choice) {
	switch (choice) {
	case 1:
		return printValueLocation(inputString);
	case 2:
		return printIndexLocation(inputString);
	default:
		return false;
	}
}

bool LL::ManagerDLL::printValueLocation(std::string inputString) {
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

bool LL::ManagerDLL::printIndexLocation(std::string indexString) {
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

int LL::ManagerDLL::findValueLocation(std::string inputString) {
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

std::string LL::ManagerDLL::findIndexLocation(std::string indexString) {
	std::string output = "\0";
	int index = 0;
	int location = std::stoi(indexString);
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

bool LL::ManagerDLL::deleteValueChoice(std::string inputString, int choice) {
	switch (choice) {
	case 1:
		return deleteValueLocation(inputString);
	case 2:
		return deleteIndexLocation(inputString);
	default:
		return false;
	}
}

bool LL::ManagerDLL::deleteValueLocation(std::string inputString) {
	bool isDeleted = false;
	Node* currentNode = head;
	if (currentNode == nullptr) {
		return isDeleted;
	}
	else if (currentNode->getStringValue() == inputString) {
		isDeleted = deleteHeadNode();
	}
	else {
		while (currentNode->getStringValue() != inputString) {
			currentNode = currentNode->getNext();
			if (currentNode->getNext() == nullptr) {
				break;
			}
		}
		if (currentNode->getStringValue() == inputString) {
			isDeleted = deleteNode(currentNode);
		}
	}

	return isDeleted;
}

bool LL::ManagerDLL::deleteIndexLocation(std::string inputString) {
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
		while (index != location) {
			index++;
			currentNode = currentNode->getNext();
			if (currentNode->getNext() == nullptr) {
				break;
			}
		}
		if (index == location) {
			isDeleted = deleteNode(currentNode);
		}
	}
	
	return isDeleted;
}

bool LL::ManagerDLL::deleteHeadNode() {
	Node* currentNode = head->getNext();
	currentNode->setPrevious(nullptr);
	delete head;
	head = currentNode;
	return true;
}

bool LL::ManagerDLL::deleteNode(Node*& currentNode) {
	Node* tempNode = currentNode;
	if (currentNode->getNext() != nullptr) {
		currentNode->getPrevious()->setNext(currentNode->getNext());
		currentNode->getNext()->setPrevious(currentNode->getPrevious());
	}
	else {
		tail = tail->getPrevious();
		tail->setNext(nullptr);
		currentNode = currentNode->getPrevious();
		currentNode->setNext(nullptr);
	}
	delete tempNode;
	return true;
}

void LL::ManagerDLL::printListAscending() {
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

void LL::ManagerDLL::printListDescending() {
	if (tail != nullptr) {
		int index = 1;
		Node* printNode = tail;
		while (printNode != nullptr) {
			std::cout << "Index [" << std::setw(2) << index << "] : " << printNode->getStringValue() << std::endl;
			index++;
			printNode = printNode->getPrevious();
		}
		std::cout << std::endl;
		delete printNode;
	}
	else {
		std::cout << "The list is currently empty." << std::endl << std::endl;
	}
}
