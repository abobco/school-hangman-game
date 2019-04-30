#include "ascArt.h"

ascArt::ascArt()
{
	iFile.open("TitleArt.txt");
	string line;
	while (iFile)
	{
		getline(iFile, line);
		line += '\n';
		mainTitle += line;
	}
	iFile.close();

	iFile.open("hangArt.txt");
	for(int j = 0; j < 7; j++)
	{
		string temp;
		for (int i = 0; i < 7; i++)
		{
			getline(iFile, line);
			line += '\n';
			temp += line;
		}
		hangState.push_back(temp);
	}
	iFile.close();

	iFile.open("loseArt.txt");
	while (iFile)
	{
		getline(iFile, line);
		line += '\n';
		failscreen += line;
	}
	iFile.close();

	iFile.open("victory.txt");
	while (iFile)
	{
		getline(iFile, line);
		line += '\n';
		victoryscreen += line;
	}
	iFile.close();
}

void ascArt::printTitle()
{
	system("CLS");
	cout << mainTitle;
}

void ascArt::printHangman(int state)
{
	system("CLS");
	cout << hangState[state];
}

void ascArt::printFail()
{
	system("CLS");
	cout << failscreen;
}

void ascArt::printVictory()
{
	system("CLS");
	cout << victoryscreen;
}