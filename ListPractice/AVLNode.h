#pragma once
#include "Node.h"

namespace LL {
    class AVLNode :
        public virtual Node
    {
	public:
		AVLNode(std::string inputString);
		~AVLNode();
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
