#include "AVLNode.h"
#include "Shared.h"

LL::AVLNode::AVLNode(std::string inputString) {
	this->stringValue = inputString;
	this->next = nullptr;
	this->previous = nullptr;
	if (LL::Shared::isNumberCheck(inputString) == true) {
		this->intValue = std::stoi(inputString);
		this->isIntNumber = true;
	}
	else {
		this->intValue = 0;
		this->isIntNumber = false;
	}
}

LL::AVLNode::~AVLNode() {

}

void LL::AVLNode::setStringValue(std::string inputString) {
	this->stringValue = inputString;
	if (LL::Shared::isNumberCheck(inputString) == true) {
		this->intValue = std::stoi(inputString);
		this->isIntNumber = true;
	}
	else {
		this->intValue = 0;
		this->isIntNumber = false;
	}
}

std::string LL::AVLNode::getStringValue() {
	return this->stringValue;
}

bool LL::AVLNode::isNumber() {
	return this->isIntNumber;
}

int LL::AVLNode::getIntValue() {
	return this->intValue;
}

void LL::AVLNode::setNext(Node* nextNode) {
	this->next = nextNode;
}

void LL::AVLNode::setPrevious(Node* previousNode) {
	this->previous = previousNode;
}

LL::Node* LL::AVLNode::getNext() {
	return this->next;
}

LL::Node* LL::AVLNode::getPrevious() {
	return this->previous;
}
