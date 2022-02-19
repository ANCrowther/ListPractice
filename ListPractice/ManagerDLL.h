#pragma once
#include "Manager.h"

namespace LL {
	class ManagerDLL :
		public virtual Manager
	{
	public:
		ManagerDLL();
		~ManagerDLL();
		bool clearList();
		void deleteValue(std::string inputString, int choice);
		void findValue(std::string inputString, int choice);
		bool insertNode(std::string inputString);
		void printList();
		void sizeOfList();
	private:
		bool clearFullList();
		bool deleteNode(Node*& deleteMeNode);
		bool deleteHeadNode();
		int getSizeOfList();
		bool insertHeadNode(Node*& newNode);
		bool insertInOrder(std::string inputString);

		bool deleteIndexLocation(std::string inputString);
		bool deleteValueChoice(std::string inputString, int choice);
		bool deleteValueLocation(std::string inputString);
		std::string findIndexLocation(std::string indexString);
		bool findValueChoice(std::string inputString, int choice);
		int findValueLocation(std::string inputString);
		bool insertNodeInMiddle(Node*& newNode, Node*& currentNode);
		bool insertTailNode(Node*& newNode, Node* currentNode);
		bool printIndexLocation(std::string inputString);
		void printListAscending();
		void printListDescending();
		bool printValueLocation(std::string inputString);
	};
}
