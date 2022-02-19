#pragma once
#include "Menu.h"
#include "ManagerSLL.h"

namespace LL {
	class MenuSLL :
		public virtual Menu
	{
	public:
		~MenuSLL();
		void menu();
	private:
		ManagerSLL* manager;
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
