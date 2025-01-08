
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "User.h"
#include "Menu_video.h"
#include "Movie.h"

using namespace std;

void User::Inregistration(string Name, string Email, string Password, int Age)
{

	ofstream fisier("Log_in_user.out", std::ios::app);
	if (fisier)
	{
		fisier << endl << "First and last name: " << Name << endl;
		fisier << "E-mail: " << Email << endl;
		fisier << "Password: " << Password << endl;
		fisier << "Age: " << Age << endl;
		fisier.close();
		cout << "Your account has been registered." << endl; 


		Menu_series_movies_user();
	}
	else {
		cout << "Error when registering on this platform.";
	}
}

void User::Autentification(string Name, string Email, string Password, int Age)
{
	string r1 = "First and last name: " + Name;
	string r2 = "E-mail: " + Email;
	string r3 = "Password: " + Password;
	string r4 = "Age: " + to_string(Age);
	string line;
	bool found_u = false;

	ifstream f("Log_in_user.out");
	if (f)
	{
	  while (getline(f, line) && found_u == 0)
		{
			string l = line.c_str();

			if (l == r1)
			{
				//cout << "Numele este corect!"<< endl;
				getline(f, line);
				string l = line.c_str();
				if (l == r2)
				{
					//cout << "E_mail-ul este corect"<< endl;
					getline(f, line);
					string l = line.c_str();
					if (l == r3)
					{
						//cout << "Parola este corecta"<< endl;
						getline(f, line);
						string l = line.c_str();
						if (l == r4)
						{
							//cout << "Toate datele sunt corecte"<< endl;
							found_u = 1;
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

	if (found_u)
	{   cout << "Successful autentification for user! " << endl;
		Menu_series_movies_user();
	}
	else {
		cout << "The information entered is incorrect for user!" << endl;
	}
}
void User::Visualization_list()
{
	Movie movie;
	string Name;
	string tempT;
	ofstream f("Visualization.txt", ios::app);

	int more = 1;

	cout << "Your name is: ";
	getline(cin, Name);
	cin.ignore();
	f << "*";
	f << Name << " saw: " << endl;
	int contor = 0;

	while (more == 1)
	{
		contor++;
		f << contor << ".";
		cout << "Enter the title you want to add in your list: ";
		cin.ignore();
		getline(cin, tempT);
		movie.settitleM(tempT);

		f << tempT << endl;

		cout << "If you want to add more titles press 1." << endl;
		int t;
		cin >> t;
		more = t;

	}
	cout << endl;
	f.close();
}

void User::Dislike_list()
{
	
	string Name;
	string tempT;
	ofstream f("Dislike.txt", ios::app);

	int more = 1;

	cout << "Your name is: ";
	getline(cin, Name);
	f << "*";
	f << Name << " dislikes: " << endl;
	int contor = 0;
	cin.ignore();
	while (more == 1)
	{
		contor++;
		f << contor << ".";
		cout << "Enter the title you want to add in your list: ";
		cin.ignore();
		getline(cin, tempT);
		
		f << tempT << endl;

		cout << "If you want to add more titles press 1." << endl;
		int t;
		cin >> t;
		more = t;

	}
	cout << endl;
	f.close();
}
void User::Favourite_list()
{
	string Name;
	string tempT;

	ofstream f("Favourite_list.in", ios::app);
	cout << "Your name is: ";

	getline(cin, Name);
	f << "*";
	f << Name << " likes: " << endl;
	int contor = 0;

	int more = 1;
	cin.ignore();
	while (more == 1)
	{
		contor++;
		f << contor << ".";
		cout << "Enter the title you want to add in your list: ";
		cin.ignore();
		getline(cin, tempT);

		f << tempT << endl;

		cout << "If you want to add more titles press 1." << endl;
		int t;
		cin >> t;
		more = t;

	}
	cout << endl;
}

void User::Display()
{
	ifstream file("All_movies.txt", ios::in);
	ifstream File("All_series.txt", ios::app);

	cout << "If you want to see our movies press '1'." << endl;
	cout << "If you want to see out series press '2'." << endl;

	string line, Line;
	int t;
	cin >> t;

	if (t == 1)
	{
		while (getline(file, line))
			cout << line << endl;
	}
	else
		if (t == 2)
		{
			while (getline(File, Line))
				cout << Line << endl;
		}
	file.close();
	File.close();
}

void User::Watch_list()
{
	string Name;
	string tempT;
	ofstream f("Watch_list.txt", ios::app);

	int more = 1;

	cout << "Your name is: ";
	getline(cin, Name);
	cin.ignore();
	f << "*";
	f << Name << " want to watch: " << endl;
	int contor = 0;

	while (more == 1)
	{
		contor++;
		f << contor << ".";
		cout << "Enter the title you want to add in your list: ";
		cin.ignore();
		getline(cin, tempT);
		

		f << tempT << endl;

		cout << "If you want to add more titles press 1." << endl;
		int t;
		cin >> t;
		more = t;

	}
	cout << endl;
	f.close();
}

void User::Search_movie_after_age_limit()
{
	int age_limit;
	string line, title;

	cout << "Your age is: ";
	getline(cin, line);
	cin.ignore();

	// Conversia vârstei la int
	try {
		age_limit = stoi(line);  // Convertim vârsta utilizatorului la int
	}
	catch (const invalid_argument&) {
		cout << "Invalid age input!" << endl;
		return;
	}

	int movie_age_limit = 0;  // Inițializăm variabila pentru limita de vârstă
	ifstream file("All_movies.txt");  

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;

	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {  
			title = line; 
			found_title = true;
		}
		else if (line.find("AGE LIMIT: ") == 0 && found_title) {
			// Extragem limita de vârstă
			try {
				movie_age_limit = stoi(line.substr(11));  // Convertim limita de vârstă
			}
			catch (const invalid_argument&) {
				cout << "Invalid age limit!" << endl;
				continue;  // Sărim peste această linie și continuăm cu următorul film
			}

			// Comparăm limita de vârstă cu vârsta utilizatorului
			if (movie_age_limit <= age_limit) {
				cout << title << endl;  // Afișăm titlul filmului
			}
			found_title = false;
		}
	}

	file.close();
}


void User::Search_series_after_age_limit()
{
	int age_limit;
	string line, title;

	cout << "Your age is: ";
	getline(cin, line);
	cin.ignore();

	// Conversia vârstei la int
	try {
		age_limit = stoi(line);  // Convertim vârsta utilizatorului la int
	}
	catch (const invalid_argument&) {
		cout << "Invalid age input!" << endl;
		return;
	}

	int movie_age_limit = 0;  // Inițializăm variabila pentru limita de vârstă
	ifstream file("All_series.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;

	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {
			title = line;
			found_title = true;
		}
		else if (line.find("AGE LIMIT: ") == 0 && found_title) {
			// Extragem limita de vârstă
			try {
				movie_age_limit = stoi(line.substr(11));  // Convertim limita de vârstă
			}
			catch (const invalid_argument&) {
				cout << "Invalid age limit!" << endl;
				continue;  // Sărim peste această linie și continuăm cu următorul film
			}

			// Comparăm limita de vârstă cu vârsta utilizatorului
			if (movie_age_limit <= age_limit) {
				cout << title << endl;  // Afișăm titlul filmului
			}
			found_title = false;
		}
	}

	file.close();
}


void User::Search_movie_after_main_actors()
{
	string actor_name;
	string line, title, main_actors;

	// Solicităm utilizatorului să introducă numele actorului
	cout << "Enter the actor's name: ";
	getline(cin, actor_name);
	cin.ignore();  // Curățăm buffer-ul

	ifstream file("All_movies.txt");

	// Verificăm dacă fișierul s-a deschis cu succes
	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;  // Flag pentru a urmări dacă un titlu este găsit

	// Citim fișierul linie cu linie
	while (getline(file, line)) {
		// Căutăm linia care conține titlul filmului
		if (line.find("TITLE: ") == 0) {
			title = line;  // Salvăm titlul
			found_title = true;  // Am găsit un titlu
		}
		// Căutăm linia care conține actorii principali
		else if (line.find("MAIN ACTORS: ") == 0 && found_title) {
			main_actors = line.substr(13);  // Presupunem că "MAIN ACTORS: " are 13 caractere

			// Verificăm dacă numele actorului introdus de utilizator se află în lista actorilor principali
			if (main_actors.find(actor_name) != string::npos) {
				cout << title << endl;  // Afișăm titlul filmului dacă actorul se află în lista principală
			}

			// După ce am verificat actorii, resetăm found_title pentru a căuta următorul film
			found_title = false;
		}
	}

	file.close();  // Închidem fișierul
}

void User::Search_series_after_main_actors()
{
	string actor_name;
	string line, title, main_actors;

	cout << "Enter the actor's name: ";
	getline(cin, actor_name);
	cin.ignore();  

	ifstream file("All_series.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}
	bool found_title = false;  

	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {
			title = line;  
			found_title = true;  
		}
		
		else if (line.find("MAIN ACTORS: ") == 0 && found_title) {
			main_actors = line.substr(13); 
			if (main_actors.find(actor_name) != string::npos) {
				cout << title << endl; 
			}

			found_title = false;
		}
	}
	file.close(); 

}

void User::Search_movie_after_year()
{
	int input_year;
	string line, title;

	cout << "Enter the year of release: ";
	getline(cin, line);
	cin.ignore();

	input_year = stoi(line);
	
	

	ifstream file("All_movies.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;

	// Citim fișierul linie cu linie
	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {  
			title = line;  
			found_title = true;
		}
		else if (line.find("YEAR OF RELEASE: ") == 0 && found_title) {
			try {
				// Extragem anul din linia "YEAR OF RELEASE: "
				int movie_year = stoi(line.substr(17));  // Presupunem că "YEAR OF RELEASE: " are 17 caractere
				if (movie_year == input_year) {
					cout << title << endl;  // Afișăm titlul filmului dacă anul coincide cu cel introdus
				}
			}
			catch (const invalid_argument&) {
				cout << "Invalid year format!" << endl;
				continue;  
			}

			found_title = false;  
		}
	}

	file.close();
	
}

void User::Search_series_after_year()
{
	int input_year;
	string line, title;

	cout << "Enter the year of release: ";
	getline(cin, line);
	cin.ignore();

	input_year = stoi(line);

	ifstream file("All_series.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;

	// Citim fișierul linie cu linie
	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {
			title = line;
			found_title = true;
		}
		else if (line.find("YEAR OF RELEASE: ") == 0 && found_title) {
			try {
				// Extragem anul din linia "YEAR OF RELEASE: "
				int movie_year = stoi(line.substr(17));  // Presupunem că "YEAR OF RELEASE: " are 17 caractere
				if (movie_year == input_year) {
					cout << title << endl;  // Afișăm titlul filmului dacă anul coincide cu cel introdus
				}
			}
			catch (const invalid_argument&) {
				cout << "Invalid year format!" << endl;
				continue;
			}

			found_title = false;
		}
	}

	file.close();

}

void User::Search_movie_after_genre()
{
	string genre;
	string line, title, Genre;

	cout << "Enter the genre: ";
	getline(cin, genre);
	cin.ignore();

	ifstream file("All_movies.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}
	bool found_title = false;

	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {
			title = line;
			found_title = true;
		}

		else if (line.find("GENRE: ") == 0 && found_title) {
			Genre = line.substr(13);
			if (Genre.find(genre) != string::npos) {
				cout << title << endl;
			}

			found_title = false;
		}
	}
	file.close();
}

void User::Search_series_after_genre()
{
	string genre;
	string line, title, Genre;

	cout << "Enter the genre: ";
	getline(cin, genre);
	cin.ignore();

	ifstream file("All_series.txt");

	if (!file.is_open()) {
		cout << "Error: Could not open the file!" << endl;
		return;
	}

	bool found_title = false;

	while (getline(file, line)) {
		if (line.find("TITLE: ") == 0) {
			title = line;
			found_title = true;
		}

		else if (line.find("GENRE: ") == 0 && found_title) {
			// Extrage genul (fără prefixul "GENRE: ")
			Genre = line.substr(7);

			// Compara genul cu cel căutat
			if (Genre.find(genre) != string::npos) {
				cout << title << endl;
			}

			found_title = false;
		}
	}

	file.close();
}