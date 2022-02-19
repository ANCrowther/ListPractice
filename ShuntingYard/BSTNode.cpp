#include "BSTNode.h"
#include "Shared.h"

LL::BSTNode::BSTNode(std::string inputString) {
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

LL::BSTNode::~BSTNode() {

}

void LL::BSTNode::setStringValue(std::string inputString) {
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

std::string LL::BSTNode::getStringValue() {
	return this->stringValue;
}

bool LL::BSTNode::isNumber() {
	return this->isIntNumber;
}

int LL::BSTNode::getIntValue() {
	return this->intValue;
}

void LL::BSTNode::setNext(Node* nextNode) {
	this->next = nextNode;
}

void LL::BSTNode::setPrevious(Node* previousNode) {
	this->previous = previousNode;
}

LL::Node* LL::BSTNode::getNext() {
	return this->next;
}

LL::Node* LL::BSTNode::getPrevious() {
	return this->previous;
}
