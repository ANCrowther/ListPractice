#include "NodeTypeFactory.h"
#include "SLLNode.h"
#include "DLLNode.h"
#include "BSTNode.h"
#include "AVLNode.h"
#include "Node.h"

LL::Node* LL::NodeTypeFactory::createNode(nodeType type, std::string inputString) {
	switch (type) {
	case SLLtype: return new SLLNode(inputString);
	case DLLtype: return new DLLNode(inputString);
	case BSTtype: return new BSTNode(inputString);
	case AVLtype: return new AVLNode(inputString);
	default:
		break;
	}
	return nullptr;
}
