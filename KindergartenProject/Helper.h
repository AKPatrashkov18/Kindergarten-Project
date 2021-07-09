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






//PRESENTATION layer
bool mainMenu(USER* users, int& counter)
{
	int choice;
	cout << "1. Registration" << endl;
	
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:registration(users, counter); break;

	default:cout << "Try choosing an available opton. " 
		<< endl << endl; break;
	}
	return 1;
}