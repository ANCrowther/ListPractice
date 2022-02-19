#include <iostream>
#include <iomanip>
#include "ManagerAVL.h"
#include "Node.h"
#include "Shared.h"

#define CLEARSCREEN std::cout << "\x1B[2J\x1B[H"

LL::ManagerAVL::ManagerAVL() {
	head = nullptr;
}

LL::ManagerAVL::~ManagerAVL() {

}

bool LL::ManagerAVL::clearList() {
	return false;
}

void LL::ManagerAVL::deleteValue(std::string inputString, int choice) {

}

void LL::ManagerAVL::findValue(std::string inputString, int choice) {

}

bool LL::ManagerAVL::insertNode(std::string inputString) {
	return insertInOrder(inputString);
}

void LL::ManagerAVL::printList() {
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

void LL::ManagerAVL::printPreOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	std::cout << currentNode->getStringValue() << std::endl;
	printPreOrder(currentNode->getPrevious());
	printPreOrder(currentNode->getNext());
}

void LL::ManagerAVL::printInOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	printInOrder(currentNode->getPrevious());
	std::cout << currentNode->getStringValue() << std::endl;
	printInOrder(currentNode->getNext());
}

void LL::ManagerAVL::printPostOrder(Node* currentNode) {
	if (currentNode == nullptr) {
		return;
	}

	printPostOrder(currentNode->getPrevious());
	printPostOrder(currentNode->getNext());
	std::cout << currentNode->getStringValue() << std::endl;
}

void LL::ManagerAVL::printBreadthFirst(Node* currentNode) {
	int height = treeHeight(head);
	for (int i = 0; i < height; i = i + 1) {
		std::cout << std::endl << "Level [" << i << "]:" << std::setw((height - i) * 4) << " ";
		//processCurrentLevel(head, i, ((height - i) * 4));
	}
	std::cout << std::endl << std::endl;
}

void LL::ManagerAVL::processCurrentLevel(Node* currentNode, int level, int space) {
	if (currentNode == nullptr) {
		std::cout << std::setw(space) << " ";
		return;
	}
	if (level == 0) {
		std::cout << std::setw(space) << currentNode->getStringValue();
	}
	else if (level > 0) {
		processCurrentLevel(currentNode->getPrevious(), level - 1, space);
		processCurrentLevel(currentNode->getNext(), level - 1, space);
	}
}

int LL::ManagerAVL::treeHeight(Node* currentNode) {
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

void LL::ManagerAVL::sizeOfList() {
	std::cout << "The list has " << countNode(head) << " elements." << std::endl;
	std::cout << "The height is: " << treeHeight(head) << std::endl << std::endl;
}

bool LL::ManagerAVL::clearFullList() {
	return false;
}

bool LL::ManagerAVL::deleteNode(Node*& deleteMeNode) {
	return false;
}

bool LL::ManagerAVL::deleteHeadNode() {
	return false;
}

int LL::ManagerAVL::getSizeOfList() {
	return 0;
}

bool LL::ManagerAVL::insertHeadNode(Node*& newNode) {
	head = newNode;
	return true;
}

bool LL::ManagerAVL::insertInOrder(std::string inputString) {
	bool isInserted = false;
	Node* newNode = factory.createNode(NodeTypeFactory::AVLtype, inputString);
	if (head == nullptr) {
		isInserted = insertHeadNode(newNode);
	}
	else {
		isInserted = insertInOrder(head, newNode);
	}
	return isInserted;
}


int LL::ManagerAVL::countNode(Node* currentNode) {
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

bool LL::ManagerAVL::insertInOrder(Node* currentNode, Node* newNode) {
	return false;
}
