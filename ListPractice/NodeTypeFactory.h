#pragma once
#include "Node.h"
#include "SLLNode.h"

namespace LL {
	class NodeTypeFactory {
	public:
		enum nodeType{ SLLtype, DLLtype, BSTtype, AVLtype };
		Node* createNode(nodeType type, std::string inputString);
	private:
	};
}
