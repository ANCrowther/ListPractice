#pragma once
#include "Menu.h"
#include "ManagerAVL.h"

namespace LL {
    class MenuAVL :
        public virtual Menu
    {
	public:
		~MenuAVL();
		void menu();
	protected:
		ManagerAVL* manager;
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
