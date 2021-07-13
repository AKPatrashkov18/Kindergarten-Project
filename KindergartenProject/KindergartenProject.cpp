#include <iostream>
#include<string>
#include <stdlib.h>
#include "Structures.h"
#include "Helper.h"
using namespace std;

int main()
{
	system("color b");
	USER users[64];
	int counter=0;

	ADMIN admins[64];
	int adminCounter = 0;

	int maxId = 1;

	bool showMenu = true;
	do
	{
		
		showMenu = mainMenu(users, counter, admins, adminCounter);
		system("cls");
	} while (showMenu);
}
