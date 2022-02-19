#include "SLLNode.h"
#include "Shared.h"

LL::SLLNode::SLLNode(std::string inputString) {
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

LL::SLLNode::~SLLNode() {

}

void LL::SLLNode::setStringValue(std::string inputString) {

}

LL::Node* LL::SLLNode::getNext() {
	return this->next;
}

LL::Node* LL::SLLNode::getPrevious() {
	return nullptr;
}

void LL::SLLNode::setNext(Node* nextNode) {
	this->next = nextNode;
}

void LL::SLLNode::setPrevious(Node* nextNode) {

}

bool LL::SLLNode::isNumber() {
	return this->isIntNumber;
}

std::string LL::SLLNode::getStringValue() {
    return this->stringValue;
}

int LL::SLLNode::getIntValue() {
    return this->intValue;
}
