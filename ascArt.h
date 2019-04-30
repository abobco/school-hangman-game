#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
#ifndef __ASCART_H__
#define __ASCART_H__

class ascArt
{
private:
	//string representations of art
	vector<string> hangState;
	string mainTitle;
	string failscreen;
	string victoryscreen;

	//file io
	ifstream iFile;

public:
	ascArt();

	//print title art
	void printTitle();

	//print hangman from state
	void printHangman(int state);

	void printFail();

	void printVictory();

};
#endif
