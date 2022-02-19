#pragma once
#include <vector>
#include "Manager.h"

namespace LL {
	class ManagerBST :
		public virtual Manager
	{
	public:		
		ManagerBST();
		~ManagerBST();
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

		int countNode(Node* currentNode);
		Node* clearTree(Node* currentNode);
		Node* deleteNode(Node* currentNode, std::string inputString);
		std::string findMinimum(Node* currentNode);
		bool findValueInTree(Node* currentNode, std::string inputString);
		bool insertInOrder(Node* currentNode, Node* newNode);
		void printPreOrder(Node* currentNode);
		void printInOrder(Node* currentNode);
		void printPostOrder(Node* currentNode);
		void printBreadthFirst(Node* currentNode);
		void processCurrentLevel(Node* currentNode, int level, int space);
		int treeHeight(Node* currentNode);
	};
}
