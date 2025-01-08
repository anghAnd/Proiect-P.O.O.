#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Admin.h"
#include "Menu_video.h"

using namespace std;
void Admin::Autentification_A(string Name_A, string Email_A, string Password_A)
{
	string r1 = Name_A;
	string r2 = Email_A;
	string r3 = Password_A;
	string line;
	bool found_a = false;

	ifstream f("Log_in_admin.in");
	if (f)
	{
		while (getline(f, line) && found_a == false)
		{
			string l = line.c_str();

			if (l == r1)
			{
				//cout << "Numele este corect!" << endl;
				getline(f, line);
				string l = line.c_str();
				if (l == r2)
				{
					//cout << "E_mail-ul este corect" << endl;
					getline(f, line);
					string l = line.c_str();
					if (l == r3)
					{
						//cout << "Toate datele sunt corecte" << endl;
						found_a = true;

					}
					//else {
						//cout << "Parola este gresita!" << endl;
					//}
				}
				//else {
					//cout << "E_mail-ul este gresit!" << endl;
				//}
			}
			///else
			//{
			//	cout << "Numele este gresit!" << endl;
			//}

		}
	}
	//else cout << "NU" << endl;

	if (found_a==1)
	{
		cout << "Successful autentification for admin !" << endl;

		 Menu_series_movies_admin();
	}
	else {
		cout << "The information entered is incorrect for admin !" << endl;
	}
}
