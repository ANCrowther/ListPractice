#pragma once
#include <vector>
#include "Manager.h"

namespace LL {
	class ManagerAVL :
		public virtual Manager
	{
	public:
		ManagerAVL();
		~ManagerAVL();
		bool clearList();
		void deleteValue(std::string inputString, int choice);
		void findValue(std::string inputString, int choice);
		bool insertNode(std::string inputString);
		void printList();
		void sizeOfList();
	protected:
		Node** base;
		bool clearFullList();
		bool deleteNode(Node*& deleteMeNode);
		bool deleteHeadNode();
		int getSizeOfList();
		bool insertHeadNode(Node*& newNode);
		bool insertInOrder(std::string inputString);

		int treeHeight(Node* currentNode);
		int countNode(Node* currentNode);
		bool insertInOrder(Node* currentNode, Node* newNode);
		void printPreOrder(Node* currentNode);
		void printInOrder(Node* currentNode);
		void printPostOrder(Node* currentNode);
		void printBreadthFirst(Node* currentNode);
		void processCurrentLevel(Node* currentNode, int level, int space);
	};
}
