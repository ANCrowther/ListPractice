#pragma once
#include "Menu.h"
#include "ManagerDLL.h"

namespace LL {
	class MenuDLL :
		public virtual Menu
	{
	public:
		~MenuDLL();
		void menu();
	private:
		ManagerDLL* manager;
		void menuSwitch(char menuOption, bool& isDone);
		void loadPremadeList();
		void inputValue();
		void showList();
		void getSizeOfList();
		void findValue();
		char findValueMenu();
		void deleteValue();
		char deleteValueMenu();
		void clearList();
	};
}
