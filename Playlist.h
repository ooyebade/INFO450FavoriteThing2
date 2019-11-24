#pragma once
#include <iostream>
#include <string>
#include "Music.h"

using namespace std; 

class Playlist 
{
protected:
	Music plist[100]; 
	int listsize;

public: 
	Playlist();
	void addSong(); 
	void displayList(); 
	bool isDuplicateEntry(Music playlist);
	void showMusic();
	void readMusic(string filename);
	void saveMusic(string filename);
	~Playlist(); 

};