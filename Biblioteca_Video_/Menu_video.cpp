#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include "Menu_video.h"
#include "Series.h"
#include "Movie.h"
#include "User.h"
#include "Admin.h"

using namespace std;





void Menu_series_movies_admin() // ce poate sa faca adminul
{
	Series series;
	Movie movie;


	cout << "Menu for admin: " << endl;
	cout << "If you want to add/delete movies press 1. " << endl;//pt choose
	cout << "If you want to add/delete with series press 2. " << endl;



	int choose;
	cin >> choose;
	cout << "...................................." << endl;
	cin.ignore();


	if (choose == 1)
	{
		cout << "If you want to add a new movie press 11." << endl; //pt function
		cout << "If you want to delete a movie press 12." << endl;

		int function;
		cin >> function;
		cout << "....................................." << endl;
		cin.ignore();

		if (function == 11)
		{
			Movie movie;
			movie.Add_movie();
			return;
		}

		if (function == 12)
		{
			Movie movie;
			movie.Delete_Movie();
			return;
			
		}
	}

		if (choose == 2)
		{   
			Series serie;

			cout << "If you want to add a new series press 21." << endl; //pt fct
			cout << "If you want to delete a serie press 22." << endl;

			int fct;
			cin >> fct;
			cin.ignore();

			if (fct == 21)
			{
				serie.Add_Series();
				return;
			}
		
			if (fct == 22)
			{
				serie.Delete_S();
				return;
			}
		}
	
}



void Menu_series_movies_user() //ce poate sa faca utilizatorul;
{
	Series serie;
	Movie movie;
	User user;

	

	cout << "Menu for user: " << endl;
	cout << "To create a favourite list press 1. " << endl; //facut
	cout << "To search a movie press 2." << endl;   //facut
	cout << "To search a series press 3." << endl;   //facut
	cout << "Create a dislike list press 4. " << endl;  //facut
	cout << "To create a visualization list press 5. " << endl;  // facut
	cout << "To see all the movies we have press 6." << endl;  //facut
	cout << "To search a movie afer GENRE press 7." << endl;  //facut
	cout << "To search a movie afer MAIN ACTORS press 71." << endl; //facut
	cout << "To search a movie afer AGE LIMIT press 72." << endl; //facut
	cout << "To search a movie afer YEAR RELEASE press 73." << endl; //facut
	cout << "To search a series after GENRE press 8." << endl; //facut
	cout << "To search a series afer MAIN ACTORS press 81." << endl; //facut
	cout << "To search a series afer AGE LIMIT press 82." << endl; //facut
	cout << "To search a series afer YEAR RELEASE press 83." << endl;
	cout << "To create a watch list press 9." << endl; //facut


    int want;
	cin >> want;
	cin.ignore();

	
	if (want == 1)
	{	user.Favourite_list();
		return;
	}
	else
	if (want == 2)
	{   movie.Search_Movie();
		return;
	}
	else
	if (want == 3)
	{   serie.Search_Series();
		return;
	}
	else
	if (want == 4)
	{   user.Dislike_list();
		return;
	}
	else 
	if (want == 5)
	{   user.Visualization_list();
		return;
	}
	else 
	if (want == 6)
	{   user.Display();
		return;
	}
	else
    if (want == 7)
    {
		user.Search_movie_after_genre();
		return;
    } 
    else
    if (want == 71)
    {
	    user.Search_movie_after_main_actors();
	    return;
    }
    else
    if (want == 72)
    {
	    user.Search_movie_after_age_limit();
	    return;
    }
	else
	if (want == 73)
	{
	    user.Search_movie_after_year();
		return;
	}
    else
	if (want == 8)
	{
		user.Search_series_after_genre();
		return;
	}
    if (want == 81)
    {
		user.Search_series_after_main_actors();
	    return;
    }
	else
	if (want == 82)
	{
		user.Search_series_after_age_limit();
		return;
	}
	else
	if (want == 83)
	{
		user.Search_series_after_year();
		return;
	}
	if (want == 9)
	{   user.Watch_list();
		return;
	}
	
}