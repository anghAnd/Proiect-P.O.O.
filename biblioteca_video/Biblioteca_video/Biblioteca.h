#pragma once

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<fstream>

using namespace std;

class Movies_Series {
private:
	string titlu;
	string descriere;
	string gen;
	int durata;
	int an;
	double nota;
	string difuzare;
	int varsta;
	string protagonisti;
	int sezoane;
	string rate;
public:
	//Movies_series() {}

	//Movies_Series(string titlu, string descriere, string gen, int durata, int an, double nota, string difuzare, int varsta, string protagonisti, int sezoane,string rate);
	//~Movies_Series();
	
	//void Adauga_titlu_film_serial(string& titl, string& des, string& gen, int& dr, int& an, double& nt,
	//	 string& dif, int& vr, string& pr, int& sz,string& rt);
	//void Adauga_serial(string& titl, string& des, string& gen, int& dr, int& an, double& nt,
	///	string& dif, int& vr, string& pr, int& sz, string& rt);
	//void Sterge_continut(string& titl, string& des, string& gen, int& dr, int& an, double& nt,
	///	 string& dif, int& vr, string& pr, int& sz, string& rt);
	//void Afisare_lista_gem(string titl, string gen);
	//void Afisare_lista_rate(string titl, string& rt);
	//void Afisare_lista_varsta(string titl, int vr);
	//void Afisare_lista_actori(string titl, string pr);
	//void Afisare_lista_loc_vizionare(string titl, string dif);
	//void Creare_lista_de_vizionat(string& titl);
	//void Adaugare_eticheta(string& titl);
	//void Personalizare(string titl, string& gen);
	

	
	 
};


class Utilizator {
private:
	string Nume;
	string E_mail;
	string Parola;
	int Varsta;
	
public:
	Utilizator() : Nume(""), E_mail(""), Parola(""), Varsta(0) {}

	Utilizator(string Nume, string E_mail, string Parola, int Varsta) :
		Nume(Nume), E_mail(E_mail), Parola(Parola), Varsta(Varsta) {}


	~Utilizator() {} 

	string getNume() const { return Nume; }
	string getEmail() const { return E_mail; }
	string getParola() const { return Parola; }
	int getVarsta() const { return Varsta; }

	void setNume(string N) { Nume = N; }
	void setEmail(string E) { E_mail = E; }
	void setParola(string P) { Parola = P; }
	void setVarsta(int V) { Varsta = V; }

	void Inregistrare(string Nume, string E_mail, string Parola, int Varsta);
	void Autentificare(string Nume, string E_mail, string Parola, int Varsta);
};

#endif