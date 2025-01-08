#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin {
private:
	string Name_A;
	string Email_A;
	string Password_A;

public:
	Admin() : Name_A(""), Email_A(""), Password_A(""){}

	Admin(string Name_A, string Email_A, string Password_A) :
		Name_A(Name_A), Email_A(Email_A), Password_A(Password_A){}


	~Admin() {}

	string getNameA() const { return Name_A; }
	string getEmailA() const { return Email_A; }
	string getPasswordA() const { return Password_A; }

	void setNameA(string name_A) { Name_A = name_A; }
	void setEmailA(string email_A) { Email_A = email_A; }
	void setPasswordA(string password_A) { Password_A = password_A; }

	void Autentification_A(string Name_A, string Email_A, string Password_A);

};

#endif