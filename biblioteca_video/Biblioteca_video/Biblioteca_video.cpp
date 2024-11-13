// Biblioteca_video.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "Biblioteca.h"
#include "Biblioteca.cpp"




using namespace std;


//Utilizator::Utilizator(string Nume, string E_mail, string Parola, int Varsta)
//{
//	this->Nume = Nume;
//	this->E_mail = E_mail;
//	this->Parola = Parola;
//	this->Varsta = Varsta;
//}


//Utilizator::~Utilizator() {
//}

int main()
{    

	string N,E,P;
	int V, alegere;

	cout << "Meniu:" << endl;
	cout << "Pentru autentificare apasati tasta 1."<<endl;
	cout << "Pentru inregistrare apasati tasta 2." << endl;
	
	cin >> alegere;
	cin.ignore();

	switch (alegere)
	{
	case 1:
	{
		cout << "Introdu nume si prenume: ";
		getline(cin, N);

		cout << "Introdu e_mail: ";
		getline(cin, E);

		cout << "Introdu parola: ";
		getline(cin, P);

		cout << "Introdu varsta: ";
		cin >> V;

		Utilizator utilizator;
		utilizator.Autentificare(N, E, P, V);

		break;
	}


	case 2:
	{
		cout << "Introduceti nume si prenume: ";
		getline(cin, N);

		cout << "Introduceti E-mail: ";
		getline(cin, E);

		cout << "Introduceti parola: ";
		getline(cin, P);

		cout << "Introduceti varsta: ";
		cin >> V;

		Utilizator utilizator;
		utilizator.Inregistrare(N, E, P, V);

		break;
	}

	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
