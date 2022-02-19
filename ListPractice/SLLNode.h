#pragma once
#include "Node.h"

namespace LL {
	class SLLNode :
		public virtual Node
	{
	public:
		SLLNode(std::string inputString);
		~SLLNode();
		std::string getStringValue();
		int getIntValue();
		Node* getNext();
		Node* getPrevious();
		void setNext(Node* nextNode);
		void setPrevious(Node* nextNode);
		bool isNumber();
		void setStringValue(std::string inputString);
	};
}
