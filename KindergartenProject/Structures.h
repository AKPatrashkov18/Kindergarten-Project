#pragma once
#include<string>
using namespace std;
struct USER
{
	int id=0;
	string username;
	string password;
	string fName;
	string lName;
	string address;
	string childName;
	int childAge;
};

struct ADMIN {
	string adminUsername;
	string adminPassword;
};