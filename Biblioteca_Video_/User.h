#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User {
private:
	string Name;
	string Email;
	string Password;
	int Age;

public:
	User() : Name(""), Email(""), Password(""), Age(0) {}

	User(string Name, string Email, string Password, int Age) :
		Name(Name), Email(Email), Password(Password), Age(Age) {}


	~User() {}

	string getName() const { return Name; }
	string getEmail() const { return Email; }
	string getPassword() const { return Password; }
	int getAge() const { return Age; }

	void setName(string name) { Name = name; }
	void setEmail(string email) { Email = email; }
	void setPassword(string password) { Password = password; }
	void setAge(int age) { Age = age; }

	void Inregistration(string Name, string Email, string Password, int Age);
	void Autentification(string Name, string Email, string Password, int Age);
	void Visualization_list();
	void Dislike_list();
	void Favourite_list();
	void Display();
	void Watch_list();
	void Search_movie_after_age_limit();
	void Search_series_after_age_limit();
	void Search_movie_after_main_actors();
	void Search_series_after_main_actors();
	void Search_movie_after_year();
	void Search_series_after_year();
	void Search_movie_after_genre();
	void Search_series_after_genre();
};

#endif