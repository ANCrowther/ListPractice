#pragma once
#include "Node.h"

namespace LL {
	class BSTNode :
		public virtual Node
	{
	public:
		BSTNode(std::string inputString);
		~BSTNode();
		std::string getStringValue();
		int getIntValue();
		bool isNumber();
		void setNext(Node* nextNode);
		void setPrevious(Node* previousNode);
		Node* getNext();
		Node* getPrevious();
		void setStringValue(std::string inputString);
	};
}
