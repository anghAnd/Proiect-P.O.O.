#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Menu_log.h"
#include "User.h"
#include "Admin.h"

using namespace std;



void Menu()
{
	string temp1, temp2, temp3;
	string Name, Name_A, Email, Email_A, Password, Password_A;
	//long int right;
	int choose, choose_1, Age;

	cout << "Menu:" << endl;
	cout << "If you are admin press 1 else press 2. " << endl;
	cin >> choose_1;
	cin.ignore();



	switch (choose_1)
	{
	case 1:
	{
		Admin admin;
		cout << "Enter first and last name: ";
		getline(cin, Name_A); 
		admin.setNameA(Name_A);

		cout << "Enter e_mail: ";
		getline(cin, Email_A);
		admin.setEmailA(Email_A);

		cout << "Enter password: ";
		getline(cin, Password_A);
		admin.setPasswordA(Password_A);

		admin.Autentification_A(Name_A, Email_A, Password_A);

		break;

	}

	case 2:
	{
		User user;
		cout << "Menu for user:" << endl;
		cout << "To autenficate user press key 1." << endl;
		cout << "To record a new user press key 2." << endl;
		cin >> choose;
		cin.ignore();

		switch (choose)
		{
		case 1:
		{
			cout << "Enter first and last name: ";
			getline(cin, Name);
			user.setName(Name);

			cout << "Enter e_mail: ";
			getline(cin, Email);
			user.setEmail(Email);

			cout << "Enter password: ";
			getline(cin, Password);
			user.setPassword(Password);

			cout << "Enter age: ";
			cin >> Age;
			user.setAge(Age);


			user.Autentification(Name, Email, Password, Age);


			break;
		}


		case 2:
		{
			cout << "Enter first and last name: ";
			getline(cin, Name);
			user.setName(Name);

			cout << "Enter e_mail: ";
			getline(cin, Email);
			user.setEmail(Email);

			cout << "Enter password: ";
			getline(cin, Password);
			user.setPassword(Password);

			cout << "Enter age: ";
			cin >> Age;
			user.setAge(Age);

			user.Inregistration(Name, Email, Password, Age);

			break;
		}

		}
	}


	}
}

