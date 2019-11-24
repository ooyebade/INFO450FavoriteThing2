#include <iostream>
#include <string>
#include "Music.h"
#include "Playlist.h"

using namespace std;

void instructions();
void tellUserStuff();

int main()
{
	int selection = 1; 
	cout << "This application will track user information." << endl; 
	Music myMusic;
	Playlist myList;
	instructions();
	char answer;
	string fileLocation; 

	do
	{
		cout << "1. Read items from a file." << endl;
		cout << "2. Add a new song to the list." << endl;
		cout << "3. Display your favorite song." << endl;
		cout << "4. Save your current playlist." << endl;
		cout << "0. Exit" << endl;
		cout << "Enter a number to choose from the above options" << endl;
		cin >> selection;
		cin.ignore();

		if (selection == 0)
		{
			break;
		}
		else if (selection == 1)
		{
			cout << "Enter the full file name: ";
			getline(cin, fileLocation);
			myList.readMusic(fileLocation);
			cout << "\nSuccessfully loaded file. Check your list so far by using choice 3." << endl;
		}
		else if (selection == 2)
		{
			myList.addSong();
			cout << "\nSuccessfully added music to the list." << endl;
		}
		else if (selection == 3)
		{
			myList.showMusic();
			cout << endl;
		}
		else if (selection == 4)
		{
			cout << "Enter the full file name: ";
			getline(cin, fileLocation);
			myList.saveMusic(fileLocation);
			cout << "Successfully saved" << endl;
		}
		else
		{
			cout << "Invalid response. Try again!" << endl;
		}

	} while (selection != 0); 

	do
	{
		myList.addSong();

		tellUserStuff();

		cin >> answer;

		cout << endl;
		cin.clear();
		cin.ignore();
	} while (answer == 'Y');


	myList.displayList();
	

	system("pause");
	return 0;
}

void instructions()
{
	cout << "**" << "  ********************  " << "**" << endl;
	cout << "**" << "                        " << "**" << endl;
	cout << "**" << "     Keep a list        " << "**" << endl;
	cout << "**" << "    of your favorite    " << "**" << endl;
	cout << "**" << "         Music!!!       " << "**" << endl;
	cout << "**" << "                        " << "**" << endl;
	cout << "**" << "     You can enter:     " << "**" << endl;
	cout << "**" << "    Song Title, Artist  " << "**" << endl;
	cout << "**" << "    Name, Song Genre,   " << "**" << endl;
	cout << "**" << "    Star Rating, and    " << "**" << endl;
	cout << "**" << "       Song Length      " << "**" << endl;
	cout << "**" << "                        " << "**" << endl;
	cout << "**" << "  ********************  " << "**" << endl;
	cout << endl;
	cout << endl;
}

void tellUserStuff()
{
	cout << endl;
	cout << "*********************" << endl;
	cout << endl;
	cout << "Would you like to add another Music Playlist? Y for Yes" << endl;
	cout << endl;
	cout << "*********************" << endl;
}