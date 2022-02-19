#include "DLLNode.h"
#include "Shared.h"

LL::DLLNode::DLLNode(std::string inputString) {
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

LL::DLLNode::~DLLNode() {

}

void LL::DLLNode::setStringValue(std::string inputString) {

}

void LL::DLLNode::setNext(Node* nextNode) {
	this->next = nextNode;
}

void LL::DLLNode::setPrevious(Node* previousNode) {
	this->previous = previousNode;
}

LL::Node* LL::DLLNode::getNext() {
	return this->next;
}

LL::Node* LL::DLLNode::getPrevious() {
	return this->previous;
}

bool LL::DLLNode::isNumber() {
	return this->isIntNumber;
}

std::string LL::DLLNode::getStringValue() {
	return this->stringValue;
}

int LL::DLLNode::getIntValue() {
	return this->intValue;
}
