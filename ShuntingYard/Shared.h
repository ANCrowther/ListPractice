#pragma once
#include <iostream>
#include <vector>

namespace LL {
	class Shared
	{
	public:
		static int isNewStringGreater(std::string newNodeValue, std::string currentNodeValue);
		static bool isNumberCheck(std::string inputString);
		static std::vector<std::string> testLists(int option);
		static int getTestOption();
	};
}
