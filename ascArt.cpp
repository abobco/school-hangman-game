#include "ascArt.h"

ascArt::ascArt()
{

	string line;

	iFile.open("asciiArt/hangArt.txt");
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



	mainTitle = loadArt("asciiArt/TitleArt.txt");
	failscreen = loadArt("asciiArt/loseArt.txt");
	victoryMED = loadArt("asciiArt/victory.txt");
	victoryEASY = loadArt("asciiArt/victoryEASY.txt");
	victoryHARD = loadArt("asciiArt/victoryHARD3.txt");

}

string ascArt::loadArt(string filename)
{
	string line;
	string output;
	iFile.open(filename);
	while (iFile)
	{
		getline(iFile, line);
		line += '\n';
		output += line;
	}
	iFile.close();
	return output;
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

void ascArt::printVictory(int difficulty)
{
	system("CLS");
	switch (difficulty)
	{
	case 1:
		cout << victoryEASY;
		break;
	case 2:
		cout << victoryMED;
		break;
	case 3:
		cout << victoryHARD;
		break;
	default:
		cout << "How did you get here?";
		break;
	}
}