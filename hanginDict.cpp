#include "hanginDict.h"
#include <time.h>

hanginDict::hanginDict()
{
	iFile.open("hanginDictEASY.txt");
	string temp;
	while (iFile)
	{
		iFile >> temp;
		sDictEASY.push_back(temp);
	}
	iFile.close();
	iFile.open("hanginDictMED.txt");
	while (iFile)
	{
		iFile >> temp;
		sDictMED.push_back(temp);
	}
	iFile.close();
	iFile.open("hanginDictHARD.txt");
	while (iFile)
	{
		iFile >> temp;
		sDictHARD.push_back(temp);
	}
	iFile.close();
}

string hanginDict::selectWord(int difficulty)
{
	int size;
	int index;
	srand(time(NULL));
	switch (difficulty)
	{
	case 1:
		size = sDictEASY.size();
		index = rand() % size;
		return sDictEASY[index];
		break;
	case 2:
		size = sDictMED.size();
		index = rand() % size;
		return sDictMED[index];
		break;
	case 3:
		size = sDictHARD.size();
		index = rand() % size;
		return sDictHARD[index];
		break;
	default:
		return "X";
		break;
	}
}