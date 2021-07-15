#pragma once
#include<iostream>
#include<string>
#include <stdlib.h>
#include"Structures.h"
using namespace std;


//DATA layer

bool checkForAge(USER* users, int& counter)
{
	
		if (users[counter].childAge >= 1 && users[counter].childAge<=5)
		{
			return true;
		}
	return false;
}
void checkForAgeDisplay(USER* users, int& counter)
{
	if (!checkForAge(users, counter))
	{
		cout << "Your child is too old/young to be in Kindergarten."<<endl;
		counter--;
	}
	int goback;
	cout << "Press 1 to go back to main menu: ";
	cin >> goback;
}
//Makes you enter a new option until you have entered a correct one
void checkForWrongInput(int variable) 
{
	while (cin.fail())
	{
		cout << "\nEnter a number, please: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> variable;
	}
}


//Checks if you enter valid username and password 
bool grantAccessForAdmin(string username, string password, int count, ADMIN* admins)
{
	for (int i = 0; i < count; i++)
	{
		if (admins[i].adminUsername == username
			&& admins[i].adminPassword == password)
		{
			return 1;
		}
	}
	return 0;
}


//
int findUserIndexByUsername(string username, int count, USER* users) 
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username)
		{
			return i;
		}
	}
	return -1;
}

//applicant form
void registrationAsParent(USER* users, int& counter)
{
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[counter].username); cout << endl;

	cout << "Password: ";
	getline(cin, users[counter].password); cout << endl;

	cout << "First name: ";
	cin >> users[counter].fName; cout << endl;

	cout << "Last name: ";
	cin >> users[counter].lName; cout << endl;

	cout << "Address: ";
	cin.ignore();
	getline(cin,users[counter].address); cout << endl;

	cout << "Child's first and last name: ";
	cin.ignore();
	getline(cin, users[counter].childName); cout << endl;

	cout << "Child's years: ";
	cin >> users[counter].childAge; cout << endl;
	checkForAgeDisplay(users, counter);

	counter++;
}

//register as admin if you want to edit
void registrationAsAdmin(ADMIN* admins, int& adminCounter)
{
	cout << "Username: ";
	cin.ignore();
	getline(cin, admins[adminCounter].adminUsername); cout << endl;

	cout << "Password: ";
	getline(cin, admins[adminCounter].adminPassword); cout << endl;

	adminCounter++;

}


void createUser(USER* users,int& counter)
{
	cout << "Enter Id: ";
	cin >> users[counter].id;
	cout << "Enter Username: ";
	cin >> users[counter].username;
	cout << "Enter password: ";
	cin >> users[counter].password;
	cout << "Enter first name: ";
	cin >> users[counter].fName;
	cout << "Enter last name: ";
	cin >> users[counter].lName;
	cout << "Enter address: ";
	cin.ignore();
	getline(cin, users[counter].address);
	cout << "Enter child's full name: ";
	getline(cin, users[counter].childName);
	cout << "Enter child's age: ";
	cin >> users[counter].childAge;
	counter++;
}

void showUserInfo(USER users)
{
	cout << "Id: " << users.id << endl;
	cout << "Username: " << users.username << endl;
	cout << "Password: " << users.password << endl;
	cout << "First name: " << users.fName<<endl;
	cout << "Last name: " << users.lName << endl;
	cout << "Address: " << users.address << endl;
	cout << "Child name: " << users.childName << endl;
	cout << "Child age: " << users.childAge << endl;
}
int getUserIndexById(USER* users, int& counter, int id)
{
	for (int i = 0; i < counter; i++)
	{
		if (users[i].id == id) // check 
		{
			return i;
		}
	}

	return -1;
}
USER getUser(USER* users, int& counter, int id)
{
	int index = getUserIndexById(users, counter, id);
	return users[index];
}
void updateUser(USER* users, int counter, int id, USER newUser) //overwrites the students data
{
	int index = getUserIndexById(users, counter, id);
	users[index] = newUser;
}
void showAllUsersInfo(USER* users, int& counter)
{	
	for (int i = 0; i < counter; i++)
	{
		showUserInfo(users[i]);
		cout << endl;
	}
	cout << endl;
	int goback;
	cout << "Press 1 to go back to the admin menu: ";
	cin >> goback;
}
void editUserMenu(USER* users, int& counter)
{
	int id;
	cout << "Enter the id of the user you want to edit: "; cin >> id;
	USER user = getUser(users, counter, id);

	cout << "1. Edit Username" << endl;
	cout << "2. Edit Password" << endl;
	cout << "3. Edit First name" << endl;
	cout << "4. Edit Last name" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "Username: "; cin >> user.username;
		updateUser(users, counter, id, user);
		break;
	
	case 2:cout << "Password: "; cin >> user.password; 
		updateUser(users, counter, id, user);
		break;
	
	case 3: cout << "First name: "; cin >> user.fName;
		updateUser(users, counter, id, user); break;
	
	case 4: cout << "Last name: "; cin >> user.lName;
		updateUser(users, counter, id, user); break;
	default:
		break;
	}
	cout << endl;
	system("cls");
	cout << "User edited successfully!" << endl;
}
void editUserById(USER* users, int& counter)
{
	int id;
	cout << "Enter the id: "; cin >> id;
	int index = getUserIndexById(users, counter, id);
	
}




void deleteUserById(USER* users, int &counter, int id)
{
	int index = getUserIndexById(users, counter, id);
	for (int i = index; i < counter - 1; i++)
	{
		users[i] = users[i + 1];
	}
	counter--;
}

void deleteUserMenu(USER* students, int& counter) //takes the id that the admin entered
{
	int userId;
	cout << "Enter the Id of the user you want to delete: ";
	cin >> userId;
	deleteUserById(students, counter, userId);
}

//shows the admin rights
bool adminMenu(int count, ADMIN* admins, int userId,USER* users, int& counter)
{
	int choice;
	cout << "---ADMIN MENU---"<<endl;
	cout << "1. Create user" << endl;
	cout << "2. Edit user" << endl;
	cout << "3. Delete user" << endl;
	cout << "4. Show users" << endl;
	cout << "5. Search user by parent's last name" << endl;
	cout << "6. Search user by child's name" << endl;
	cout << "9. Return to main menu" << endl;


	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: system("cls"); createUser(users, counter); break;
	case 3: system("cls"); deleteUserMenu(users, counter); break;
	case 2: system("cls"); editUserMenu(users, counter); break;
	case 4:system("cls"); showAllUsersInfo(users, counter); break;
	case 6: break;
	case 9: return 0;

	default:cout << "Try choosing an available opton. "
		<< endl << endl; break;
	}
	return 1;
}


//login function for admins only
void login(int count, ADMIN* admins,USER* users,int &counter)
{
	string username, password;
	int wrongCounter = 0;

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	while (!grantAccessForAdmin(username, password, count, admins)
		&& wrongCounter < 3)
	{
		cout << endl;
		cout << "Your username/password is incorrect" << endl;
		cout << "Please try again" << endl;

		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		wrongCounter++;
	}

	int userId = findUserIndexByUsername(username, count, users);

	if (grantAccessForAdmin(username, password, count, admins) && wrongCounter < 3)
	{
		
		bool showMenu;
		do
		{
			system("cls");
			showMenu = adminMenu(count, admins, userId,users,counter);
			
		} while (showMenu);
	}
}


//PRESENTATION layer
bool mainMenu(USER* users, int& counter, ADMIN* admins, int& adminCounter)
{
	int choice;
	cout << "1. Registration as Parent" << endl;
	cout << "2. Registration as Admin" << endl;
	cout << "3. Login as Admin" << endl;
	cout << "9. Exit" << endl;


	cout << "Enter your choice: ";
	cin >> choice;
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:registrationAsParent(users, counter); break;

	case 2:registrationAsAdmin(admins, adminCounter); break;

	case 3:login(adminCounter, admins, users, counter); break;

	case 9:return 0;

	default: break;

	}
	return 1;
	
}