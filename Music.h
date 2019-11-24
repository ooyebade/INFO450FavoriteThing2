#pragma once
#include <iostream>
#include <string>
using namespace std;

class Music
{
private:
	string songTitle;
	string artistName;
	string genre;
	int rating;
	double songLength{ 0.0 };

public:
	//constructors
	Music();
	~Music();

	//getters
	string getSongTitle();
	string getArtistName();
	string getGenre();
	int getRating();
	double getSongLength();

	//setters
	void setSongTitle(string ST);
	void setArtistName(string ArN);
	void setGenre(string g);
	void setRating(int r);
	void setSongLength(double SL);

	void addSongLibrary();

	friend ostream &operator << (ostream &os, Music &playlist);
	friend bool operator==(const Music& lhs, const Music& rhs); 
	// end class
};
