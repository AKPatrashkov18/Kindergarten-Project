#pragma once
#include<iostream>
#include<string>
#include"Structures.h"
using namespace std;


//DATA layer

void registration(USER* users,int& counter)
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
	cin >> users[counter].address; cout << endl;

	cout << "Child's first and last name: ";
	cin >> users[counter].childName; cout << endl;

	cout << "Child's years: ";
	cin >> users[counter].childAge; cout << endl;

	counter++;
}

void registrationAsAdmin(ADMIN* admins, int& adminCounter)
{
	cout << "Username: ";
	cin.ignore();
	getline(cin, admins[adminCounter].adminUsername); cout << endl;

	cout << "Password: ";
	getline(cin, admins[adminCounter].adminPassword); cout << endl;
	
	adminCounter++;

}





//PRESENTATION layer
bool mainMenu(USER* users, int& counter, ADMIN* admins, int& adminCounter)
{
	int choice;
	cout << "1. Registration as parent" << endl;
	cout << "2. Registration as admin" << endl;
	
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:registration(users, counter); break;

	case 2:registrationAsAdmin(admins, adminCounter); break;

	default:cout << "Try choosing an available opton. " 
		<< endl << endl; break;
	}
	return 1;
}