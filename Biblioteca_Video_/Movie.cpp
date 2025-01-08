#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Movie.h";


using namespace std;



void Movie::Add_movie()
{   
	Movie movie;
	//string Title_M, Description_M, Type_M, Grade_M, Release_to_M, Main_Actors_M;
	//int Time_M, Year_M, Age_limit_M;
	string tempT, tempTR, tempD, tempG, tempGR, tempP, tempM;
	int tempY, tempA, tempTI;


	cout << "Enter the title you want to add: ";
	//cin.ignore();
	getline(cin, tempT);
	movie.settitleM(tempT);

	cout << "Enter the trailer link: ";
	getline(cin, tempTR);
	movie.settrailerM(tempTR);

	cout << "Enter description of the chosen movie: ";
	getline(cin, tempD);
	movie.setdescriptionM(tempD);

	cout << "Enter the genre of the chosen movie: ";
	getline(cin, tempG);
	movie.settypeM(tempG);

	cout << "Enter the duration of the movie (minutes): ";
	cin >> tempTI;
	movie.settimeM(tempTI);
	cin.ignore();  

	cout << "Enter the broadcasting platform: ";
	getline(cin, tempP);
	movie.setrelease_toM(tempP);


	cout << "Enter the year the chosen movie was released: ";
	cin >> tempY;
	movie.setyearM(tempY);
	cin.ignore();

	cout << "Enter the rating received by the chosen movie: ";
	getline(cin, tempGR);
	movie.setgradeM(tempGR);

	cout << "Enter the age limit of the chosen movie: ";
	cin >> tempA;
	movie.setageM(tempA);
	cin.ignore();

	cout << "Enter the names of the main actors: ";
	getline(cin, tempM);
	movie.setmain_actorsM(tempM);

	cout << "DEBUG: Title is: " << movie.gettitleM() << endl;
	cout << "DEBUG: Trailer is: " << movie.gettrailerM() << endl;
	cout << "DEBUG: Description is: " << movie.getdescriptionM() << endl;
	cout << "DEBUG: Genre is: " << movie.gettypeM() << endl;
	cout << "DEBUG: Duration is: " << movie.gettimeM() << endl;
	cout << "DEBUG: Platform of release is: " << movie.getrelease_toM() << endl;
	cout << "DEBUG: Year is: " << movie.getyearM() << endl;
	cout << "DEBUG: Rating is: " << movie.getgradeM() << endl;
	cout << "DEBUG: Age Limit is: " << movie.getageM() << endl;
	cout << "DEBUG: Main Actors are: " << movie.getmain_actorsM() << endl;


	ofstream file("All_movies.txt", ios::app);
	if (file)
	{
		file << "TITLE: " << movie.gettitleM() << endl;
		file << "TRAILER: " << movie.gettrailerM() << endl;
		file << "DESCRIPTION: " << movie.getdescriptionM() << endl;
		file << "GENRE: " << movie.gettypeM() << endl;
		file << "YEAR OF RELEASE: " << movie.getyearM() << endl;
		file << "GRADE(IMDB): " << movie.getgradeM() << endl;
		file << "PLATFORM: " << movie.getrelease_toM() << endl;
		file << "AGE LIMIT: " << movie.getageM() << endl;
		file << "MAIN ACTORS: " << movie.getmain_actorsM() << endl;
		file << "TIME(min): " << movie.gettimeM() << endl;
		file << "----------------------------" << endl;
		file.close();

		cout << "Movie added successfully!" << endl;
	}
	else {
		cout << "Error opening the file!" << endl;
	}

	
	

}
void Movie::Delete_Movie()
{
	Movie movie;

	ifstream file("All_movies.txt");
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
	movie.settitleM(tempT);
	string titleToDelete = "TITLE: " + movie.gettitleM();
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
	if (remove("All_movies.txt") != 0) {
		cout << "Error deleting the original file." << endl;
		return;
	}

	if (rename("temp.txt", "All_movies.txt") != 0) {
		cout << "Error renaming the temp file." << endl;
		return;
	}

	cout << "Movie deleted successfully." << endl;
	return;
	
}

void Movie::Search_Movie()
{
	Movie movie;


	string tempT;


	cout << "Enter the title you want to find: ";
	getline(cin, tempT);
	movie.settitleM(tempT);
	string line;
	
	string titleToSearch = "TITLE: " + tempT;

	ifstream f("All_movies.txt" , ios::in);
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
		cout << "Movie not found." << endl;
	else cout << "Movie found." << endl;
		f.close();
}