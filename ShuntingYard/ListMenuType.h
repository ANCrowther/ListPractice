#pragma once

namespace LL {
	class ListMenuType
	{
	public:
		void menu();
	private:
		void menuSwitch(char menuOption, bool& isDone);
		void loadSLL();
		void loadDLL();
		void loadBST();
		void loadAVL();
	};
}
