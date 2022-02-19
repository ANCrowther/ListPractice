#pragma once
#include <string>
#include "NodeTypeFactory.h"

namespace LL {
	class Manager
	{
	public:
		virtual ~Manager();
		virtual bool clearList() = 0;
		virtual void deleteValue(std::string inputString, int choice) = 0;
		virtual void findValue(std::string inputString, int choice) = 0;
		virtual bool insertNode(std::string inputString) = 0;
		virtual void printList() = 0;
		virtual void sizeOfList() = 0;
	protected:
		Node* head = nullptr;
		Node* tail = nullptr;
		NodeTypeFactory factory;
		virtual bool clearFullList() = 0;
		virtual bool deleteNode(Node*& deleteMeNode) = 0;
		virtual bool deleteHeadNode() = 0;
		virtual int getSizeOfList() = 0;
		virtual bool insertHeadNode(Node*& newNode) = 0;
		virtual bool insertInOrder(std::string inputString) = 0;
	};
}
