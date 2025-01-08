#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie
{
private:
	string Top_M[1000];
	string Title_M;
	string Trailer_M;
	string Description_M;
	string Type_M;
	int Time_M;
	int Year_M;
	string Grade_M;
	string Release_to_M;
	int Age_limit_M;
	string Main_Actors_M;
	int Rate_M;

public:
	Movie() : Top_M(),Title_M(""), Trailer_M(""), Description_M(""), Type_M(""), Time_M(0), Year_M(0), Grade_M(""), Release_to_M(""), Age_limit_M(0), Main_Actors_M(""), Rate_M(0) {}
	Movie(string Title_M, string Trailer_M, string Description_M, string Type_M, int Time_M, int Year_M, string Grade_M, string Release_to_M, int Age_limit_M, string Main_Actors_M, int Rate_M) :
		Title_M(Title_M), Trailer_M(Trailer_M), Description_M(Description_M), Type_M(Type_M), Time_M(Time_M), Year_M(Year_M), Grade_M(Grade_M), Release_to_M(Release_to_M), Age_limit_M(Age_limit_M), Main_Actors_M(Main_Actors_M), Rate_M(Rate_M) {}

	~Movie() {};

	string gettitleM() const { return Title_M; }
	string gettrailerM() const { return Trailer_M; }
	string getdescriptionM() const { return Description_M; }
	string gettypeM() const { return Type_M; }
	int gettimeM() const { return Time_M; }
	int getyearM() const { return Year_M; }
	string getgradeM() const { return Grade_M; }
	string getrelease_toM() const { return Release_to_M; }
	int getageM() const { return Age_limit_M; }
	string getmain_actorsM() const { return Main_Actors_M; }
	int getrateM() const { return Rate_M; }

	void settitleM(string title_M) { Title_M = title_M; }
	void settrailerM(string trailer_M) { Trailer_M = trailer_M; }
	void setdescriptionM(string description_M) { Description_M = description_M; }
	void settypeM(string type_M) { Type_M = type_M; }
	void settimeM(int time_M) { Time_M = time_M; }
	void setyearM(int year_M) { Year_M = year_M; }
	void setgradeM(string grade_M) { Grade_M = grade_M; }
	void setrelease_toM(string release_to_M) { Release_to_M = release_to_M; }
	void setageM(int age_limit_M) { Age_limit_M = age_limit_M; }
	void setmain_actorsM(string main_actors_M) { Main_Actors_M = main_actors_M; }
	void setrateM(int rate_M) { Rate_M = rate_M; }

	void Add_movie();
	void Delete_Movie();
	void Search_Movie();

};

#endif 
