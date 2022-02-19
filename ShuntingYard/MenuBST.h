#pragma once
#include "menu.h"
#include "ManagerBST.h"

namespace LL {
	class MenuBST :
		public virtual Menu
	{
	public:
		~MenuBST();
		void menu();
	private:
		ManagerBST* manager;
		void menuSwitch(char menuOption, bool& isDone);
		void loadPremadeList();
		void inputValue();
		void showList();
		void getSizeOfList();
		void findValue();
		void deleteValue();
		void clearList();
	};
}
