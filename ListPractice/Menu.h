#pragma once
#include "ManagerSLL.h"

namespace LL {
	class Menu
	{
	public:
		virtual ~Menu();
		virtual void menu() = 0;
	protected:
		virtual void menuSwitch(char menuOption, bool& isDone) = 0;
		virtual void loadPremadeList() = 0;
		virtual void inputValue() = 0;
		virtual void showList() = 0;
		virtual void getSizeOfList() = 0;
		virtual void findValue() = 0;
		virtual void deleteValue() = 0;
		virtual void clearList() = 0;
	};
}
