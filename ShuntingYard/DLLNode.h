#pragma once
#include "Node.h"

namespace LL {
    class DLLNode :
        public virtual Node
    {
	public:
		DLLNode(std::string inputString);
		~DLLNode();
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
