#pragma once
#include "Manager.h"

namespace LL {
	class ManagerSLL :
		public virtual Manager
	{
	public:
		ManagerSLL();
		~ManagerSLL();
		bool clearList();
		void deleteValue(std::string inputString, int choice);
		void findValue(std::string inputString, int choice);
		bool insertNode(std::string inputString);
		void printList();
		void sizeOfList();
	protected:
		bool clearFullList();
		bool deleteNode(Node*& deleteMeNode);
		bool deleteHeadNode();
		int getSizeOfList();
		bool insertHeadNode(Node*& newNode);
		bool insertInOrder(std::string inputString);

		bool deleteIndexLocation(std::string inputString);
		bool deleteValueChoice(std::string inputString, int choice);
		bool deleteValueLocation(std::string inputString);
		bool findValueChoice(std::string inputString, int choice);
		std::string findIndexLocation(std::string indexString);
		int findValueLocation(std::string inputString);
		bool insertGreaterNode(Node*& newNode, Node*& currentNode);
		bool insertLesserNode(Node*& newNode, Node*& currentNode);
		bool printIndexLocation(std::string inputString);
		bool printValueLocation(std::string inputString);
	};
}
