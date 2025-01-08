#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Series.h"

using namespace std;

void Series::Add_Series()
{

	string tempSES, tempTITL, tempTRL, tempDESC, tempTYP, tempGRD, tempREL, tempMACT, line;
	int   tempYER, tempAGE, tempRATE, t = 0;

	Series series;


	ifstream f("All_series.txt", ios::in);

	cout << "Enter the title you want to add: ";
	getline(cin, tempTITL);
	series.settitleS(tempTITL);
	cin.ignore();
	while (getline(f, line))
	{
		if (line == "TITLE: " + tempTITL)
		{
			t = 1;
			break;
		}
	}
	f.close();

	if (t) {
		cout << "This title is already in the file!" << endl;
		return;
	}

	cout << "Enter the trailer: ";
	getline(cin, tempTRL);
	series.settrailerS(tempTRL);

	cout << "Enter description of the chosen series: ";
	getline(cin, tempDESC);
	series.setdescriptionS(tempDESC);

	cout << "Enter the genre of the chosen series: ";
	getline(cin, tempTYP);
	series.settypeS(tempTYP);

	cout << "Enter the number of seasons of the series: ";
	getline(cin, tempSES);
	series.setseasonsS(tempSES);


	cout << "Enter the year chosen series was released: ";
	cin >> tempYER;
	series.setyearS(tempYER);
	cin.ignore();

	cout << "Enter the rating received by the chosen series IMDB: ";
	getline(cin, tempGRD);
	series.setgardeS(tempGRD);

	cout << "Enter the age limit of the chosen series: ";
	cin >> tempAGE;
	series.setageS(tempAGE);
	cin.ignore();

	cout << "Enter the names of the main actors: ";
	getline(cin, tempMACT);
	series.setmain_actorsS(tempMACT);

	cout << "Enter the broadcasting platform: ";
	getline(cin, tempREL);
	series.setrelease_toS(tempREL);
	cin.ignore();


	ofstream file("All_series.txt", ios::app);
	if (file.is_open())
	{
		file << "TITLE: " << series.gettitleS() << endl;
		file << "TRAILER: " << series.gettrailerS() << endl;
		file << "DESCRIPTION: " << series.getdescriptionS() << endl;
		file << "GENRE: " << series.gettypeS() << endl;
		file << "YEAR OF RELEASE: " << series.getyearS() << endl;
		file << "GRADE: " << series.getgradeS() << endl;
		file << "PLATFORM: " << series.getrelease_toS() << endl;
		file << "AGE LIMIT: " << series.getageS() << endl;
		file << "MAIN ACTORS: " << series.getmain_actorsS() << endl;
		file << "NUMBER OF SEASONS: " << series.getseasonsS() << endl;
		file << "----------------------------";
		file.close();

		cout << "Series added successfully!" << endl;
	}
	else {
		cout << "Error opening the file!" << endl;
	}

}

void Series::Delete_S()
{
	Series series;

	ifstream file("All_series.txt");
	if (!file) {
		cout << "Could not open the file for reading." << endl;
		return;
	}

	ofstream tempFile("temp.txt");
	if (!tempFile) {
		cout << "Could not open the temp file for writing." << endl;
		return;
	}

	string line;
	string tempT;
	cin.ignore();
	cout << "Enter the title you want to delete: ";
	getline(cin, tempT);
	series.settitleS(tempT);
	string titleToDelete = "TITLE: " + series.gettitleS();
	bool skipLines = false;

	while (getline(file, line)) {
		if (line != titleToDelete) {
			tempFile << line << endl; // Copiază liniile care nu trebuie șterse
		}
		else
		{
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
			getline(file, line);
			cin.ignore();
		}

	}

	file.close();
	tempFile.close();

	// Înlocuiește fișierul original cu fișierul temporar
	if (remove("All_series.txt") != 0) {
		cout << "Error deleting the original file." << endl;
		return;
	}

	if (rename("temp.txt", "All_series.txt") != 0) {
		cout << "Error renaming the temp file." << endl;
		return;
	}

	cout << "Series deleted successfully." << endl;
	return;

}

void Series::Search_Series()
{
	Series serie;


	string tempT;


	cout << "Enter the title you want to find: ";
	getline(cin, tempT);
	serie.settitleS(tempT);
	string line;

	string titleToSearch = "TITLE: " + tempT;

	ifstream f("All_series.txt", ios::in);
	if (!f.is_open()) {
		cout << "Could not open the file." << endl;
		return;
	}


	bool found = false;
	while (getline(f, line)) {
		if (line == titleToSearch) {
			found = true;
			cout << line << endl;

			// Print the following lines until separator
			while (getline(f, line)) {
				if (line == "----------------------------") {
					break;
				}
				cout << line << endl;
			}
			break;  // Exit after finding the series
		}
	}

	if (found == false)
		cout << "Series not found." << endl;
	else cout << "Series found." << endl;
	f.close();
}