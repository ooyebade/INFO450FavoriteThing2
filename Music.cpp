#include <iostream>
#include <string>
#include <fstream>
#include "Music.h"
using namespace std;

//default constructors
Music::Music()
{
	songTitle = "";
	artistName = "";
	genre = "";
	rating = 0;
	songLength = 0;
}

Music::~Music()
{
}


//getters
string Music::getSongTitle()
{
	return songTitle;
}
string Music::getArtistName()
{
	return artistName;
}
string Music::getGenre()
{
	return genre;
}
int Music::getRating()
{
	return rating;
}
double Music::getSongLength()
{
	return songLength;
}

//setters
void Music::setSongTitle(string ST)
{
	songTitle = ST;
}
void Music::setArtistName(string ArN)
{
	artistName = ArN;
}
void Music::setGenre(string g)
{
	genre = g;
}
void Music::setRating(int r)
{
	rating = r;
}
void Music::setSongLength(double SL)
{
	songLength = SL;
}

void Music::addSongLibrary()
{
	do
	{
		cout << "Enter the title of the song: " << endl;
		getline(cin, songTitle, '\n');

		cout << "Enter the name of the artist: " << endl;
		getline(cin, artistName, '\n');

		cout << "Enter the genre of the song: " << endl;
		getline(cin, genre);
		while (true)
		{
			cout << "Rate the song and artist: " << endl;
			cin >> rating;
			if (!cin.fail() && rating >= 1 && rating <= 10)
				break;
			else if (cin.fail())
				cout << "Rating can only be the digits of 1 through 10. Please enter a new rating" << endl;
			else if (rating < 1 || rating > 10)
				cout << "Rating must be between 1 and 10. Please enter a new rating" << endl;
			cin >> rating;
		}

		cout << "Enter the length of the song: " << endl;
		double songLength = 0.0;
		cin >> songLength;
		cin.ignore();
	} while (songTitle.empty());
}

//overide function which displays music to console
ostream & operator << (ostream &os, Music &playlist)
{
	os << "Music: " << playlist.songTitle << endl;
	os << "Artist Name: " << playlist.artistName << endl;
	os << "Genre: " << playlist.genre << endl;
	os << "Rating: " << playlist.rating << endl;
	os << "Duration: " << playlist.songLength << endl;
	return os;
}

bool operator==(const Music& lhs, const Music& rhs)
{
	return lhs.songTitle == rhs.songTitle && lhs.artistName == rhs.artistName; 
}

