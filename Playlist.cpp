#include <iostream>
#include <string>
#include <fstream>
#include "Music.h"
#include "Playlist.h"

using namespace std;

//constructor
Playlist::Playlist()
{
	listsize = 0;
}

bool Playlist::isDuplicateEntry(Music playlist)
{
	int i;
	for (i = 0; i < listsize; i++)
	{
		if ((playlist.getSongTitle() == plist[i].getSongTitle()) && (playlist.getArtistName() == plist[i].getArtistName()))
		{
			return true;
		}
	}
	return false;
}

void Playlist::addSong()
{
	Music newPlaylist;
	newPlaylist.addSongLibrary();
	if (isDuplicateEntry(newPlaylist))
	{
		cout << "You have already entered a Music with this song title and artist name" << endl;
		newPlaylist.~Music();
		listsize--; 
	}
	else
	{
		plist[listsize] = newPlaylist;
		listsize++;
	}
}

// displays every object in array
void Playlist::displayList()
{
	int i;
	for (i = 0; i < listsize; i++)
	{
		cout << plist[i] << endl;
		cout << endl;
	}
}

void Playlist::showMusic()
{
	if (listsize != 0)
	{
		cout << endl << "Here is the list of music you've added: " << endl; 
		int i;
		for (i = 0; i < listsize; i++)
		{
			cout << plist[i];
		}
		cout << "Total numbers of music is " << listsize << "." << endl;
	}
	else
	{
		cout << "You currently have no music added. Try opening a file or adding a music." << endl; 
	}
}
void Playlist::readMusic(string filename)
{
	ifstream inputFile;
	inputFile.open(filename, ios::in); 
	if (!inputFile)
	{
		cout << "Could not open file. Please make sure the file exists and has been entered correctly." << endl;
		return; 
	}

	string songTitle;
	string artistName;
	string genre;
	int rating;
	double songLength; 
	string inputString;

	while (!inputFile.eof())
	{
		getline(inputFile, inputString, '|');
		if (inputString.length() >= 1)
		{
			artistName = inputString; 
			getline(inputFile, songTitle, '|');
			rating = stoi(inputString); 
			getline(inputFile, genre, '|');
			songLength = stoi(inputString); 


			//plist[listsize].setIdentifier(Id)
			plist[listsize].setSongTitle(songTitle);
			plist[listsize].setArtistName(artistName);
			plist[listsize].setGenre(genre);
			plist[listsize].setRating(rating); 
			plist[listsize].setSongLength(songLength); 
			listsize++; 
		}
	}
	inputFile.close(); 
}
void Playlist::saveMusic(string filename)
{
	int i;
	ofstream outputFile;
	outputFile.open(filename, ios::in);
	if (!outputFile)
	{
		outputFile.open(filename, ios::out);
	}

	for (i = 0; i < listsize; i++)
	{
		outputFile << plist[listsize].getSongTitle() << "|";
		outputFile << plist[listsize].getArtistName() << "|";
		outputFile << plist[listsize].getGenre() << "|";
		outputFile << plist[listsize].getRating() << "|";
		outputFile << plist[listsize].getSongLength() << "|"; 
	}
	outputFile.close(); 
	//return 0;
}
Playlist::~Playlist()
{
}