#include <iostream>
#include<string>
#include "Structures.h"
#include "Helper.h"
using namespace std;

int main()
{
	system("color b");
	USER users[64];
	int counter=0;
	bool showMenu = true;
	do
	{
		showMenu = mainMenu(users, counter);
		system("CLS");
	} while (showMenu);
}
