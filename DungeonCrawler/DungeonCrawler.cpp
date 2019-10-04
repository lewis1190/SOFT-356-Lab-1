// DungeonCrawler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

string genMap(string theMap[][31]);
int drawMap();

struct PlayerLoc {
	int xPos;
	int yPos;
};

int main()
{
	string theMap[10][31];

	theMap = genMap(theMap);
 	drawMap();
}

string genMap(string theMap[][31])
{
	string line;
	std::ifstream inFile;

	int mapXSize = 30;
	int mapYSize = 10;

	inFile.open("./Map.txt");
	if (!inFile)
	{
		std::cerr << "Unable to open the map!";
		exit(1); // Stop the program
	}
	else
	{
		PlayerLoc location;
		string gameMap[10][31];

		int lineNo = 0;

		while (getline(inFile, line))
		{
			int charNo = 0;
			for (char& c : line) {
				//cout << c << endl;
				gameMap[lineNo][charNo] = c;

				if (c == 'S')
				{
					location.xPos = lineNo;
					location.yPos = charNo;
				}
				charNo++;
			};

			if (lineNo <= mapYSize) {
				lineNo++;
			}
			else {
				cout << "stop";
			}

		}

		cout << "map rendered" << endl;

		if (&location)
		{
			cout << "Found player at: " << endl;
			cout << "x Pos: " << location.xPos << endl;
			cout << "y Pos: " << location.yPos << endl;
		};

		return **theMap;
	};
}

int drawMap() {
	return 0;
}

//for (int y = 0; y < 9; y++) {
//	for (int x = 0; x < 30; x++)
//	{
//		inFile >> gameMap[y][x];
//		//cout << gameMap[y][x];
//	}
//}

//if (line.find('S') != string::npos)
//{
//	location.xPos = 5;
//	location.yPos = 10;
//}