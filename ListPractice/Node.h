#pragma once
#include <string>

namespace LL {
	class Node
	{
	public:
		virtual ~Node();
		virtual std::string getStringValue() = 0;
		virtual int getIntValue() = 0;
		virtual bool isNumber() = 0;
		virtual void setNext(Node* nextNode) = 0;
		virtual void setPrevious(Node* previousNode) = 0;
		virtual Node* getNext() = 0;
		virtual Node* getPrevious() = 0;
		virtual void setStringValue(std::string inputString) = 0;
	protected:
		bool isIntNumber;
		std::string stringValue;
		int intValue;
		Node* next;
		Node* previous;
	};
}
