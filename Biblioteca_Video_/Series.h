#ifndef SERIES_H
#define SERIES_H

using namespace std;


class Series
{


private:
	string Title_S;
	string Trailer_S;
	string Description_S;
	string Type_S;
	string Seasons_S;
	int Year_S;
	string Grade_S;
	string Release_to_S;
	int Age_limit_S;
	string Main_Actors_S;
	int Rate_S;

public:
	Series() : Title_S(""), Trailer_S(""), Description_S(""), Type_S(""), Seasons_S(""), Year_S(0), Grade_S(""), Release_to_S(""), Age_limit_S(0), Main_Actors_S(""), Rate_S(0) {}
	Series(string Title_S, string Description_S, string Type_S, string Seasons_S, int Year_S, string Grade_S, string Release_to_S, int Age_limit_S, string Main_Actors_S, int Rate_S) :
		Title_S(Title_S), Trailer_S(Trailer_S), Description_S(Description_S), Seasons_S(Seasons_S), Year_S(Year_S), Grade_S(Grade_S), Release_to_S(Release_to_S), Age_limit_S(Age_limit_S), Main_Actors_S(Main_Actors_S), Rate_S(Rate_S) {}

	~Series() {};

	string gettitleS() const { return Title_S; }
	string gettrailerS() const { return Trailer_S; }
	string getdescriptionS() const { return Description_S; }
	string gettypeS() const { return Type_S; }
	string getseasonsS() const { return Seasons_S; }
	int getyearS() const { return Year_S; }
	string getgradeS() const { return Grade_S; }
	string getrelease_toS() const { return Release_to_S; }
	int getageS() const { return Age_limit_S; }
	string getmain_actorsS() const { return Main_Actors_S; }
	int getrateS() const { return Rate_S; }

	void settitleS(string title_S) { Title_S = title_S; }
	void settrailerS(string trailer_S) { Trailer_S = trailer_S; }
	void setdescriptionS(string description_S) { Description_S = description_S; }
	void settypeS(string type_S) { Type_S = type_S; }
	void setseasonsS(string seasons_S) { Seasons_S = seasons_S; }
	void setyearS(int year_S) { Year_S = year_S; }
	void setgardeS(string grade_S) { Grade_S = grade_S; }
	void setrelease_toS(string release_to_S) { Release_to_S = release_to_S; }
	void setageS(int age_limit_S) { Age_limit_S = age_limit_S; }
	void setmain_actorsS(string main_actors_S) { Main_Actors_S = main_actors_S; }
	void setrateS(int rate_S) { Rate_S = rate_S; }

	void Add_Series();
	void Delete_S();
	void Search_Series();

};
#endif