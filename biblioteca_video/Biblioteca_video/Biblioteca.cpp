
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Biblioteca.h"

using namespace std;


//void Adauga_titlu_film_serial( std::string& titl,  std::string& des,  std::string& gen, int dr, int an, double nt,
//    const std::string& dif, int vr,  std::string& pr, int sz)
//{
    

//}



void Utilizator::Inregistrare(string N,string E,string P, int V)
{

	ofstream fisier("Autentificare.out", std::ios::app);
	if (fisier)
	{
		fisier <<endl << "Nume si prenume: " << N << endl;
		fisier << "E-mail: " << E << endl;
		fisier << "Parolă: " << P << endl;
		fisier << "Varstă: " << V << endl;
		fisier.close();
		cout << "Contul dumneavoastra a fost inregistrat.";
	}
	else {
		cout << "Eroare la inregistrarea pe aceasta platforma.";
	}
}

void Utilizator::Autentificare(string N, string E, string P, int V)
{   
    string r1 = "Nume si prenume: " + N;
    string r2 = "E-mail: " + E;
	string r3 = "Parolă: " + P;
	string r4 = "Varstă: " + to_string(V);
	string linie;
	bool gasit = false;

	ifstream f("Autentificare.out");
	if (f)
	{
		while (getline(f, linie) && gasit==0)
		{ 
			string l = linie.c_str();
			
			if (l == r1)
			{
				//cout << "Numele este corect!"<< endl;
				getline(f, linie);
				string l = linie.c_str();
				if (l == r2)
				{
					//cout << "E_mail-ul este corect"<< endl;
					getline(f, linie);
					string l = linie.c_str();
					if (l == r3)
					{ 
						//cout << "Parola este corecta"<< endl;
						getline(f, linie);
						string l = linie.c_str();
						if (l == r4)
						{   
							//cout << "Toate datele sunt corecte"<< endl;
							gasit = 1;
						}
						//else { cout << "Varsta este gresita!"<< endl; 
			            //}
					}
					//else {
					//	cout << "Parola este gresita!"<< endl;
					//}
				}
				//else {
				//	cout << "E_mail-ul este gresit!"<< endl;
				//}
			}
			//else
			//{
			//	cout << "Numele este gresit!"<< endl;
			//}

		}
	}

	if(gasit)
	{
		cout << "Autentificare reusita! " << endl;
	}
	else {
		cout << "Datele introduse sunt gresite!" << endl;
	}
}