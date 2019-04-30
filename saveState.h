#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#ifndef __SAVESTATE_H__
#define __SAVESTATE_H__

using namespace std;
class saveState
{
private:
	ifstream iFile;
	ofstream oFile;
	

public:

		int wordsize;
		int hangstate;
		int difficulty;

		string chosenWord;
		string displayWord;
		string guessedLetters;
		vector<string> guessedWords;

	saveState();

	void load();

	void save(int difficult, int wordsiz, int hangstat, string chosenWor, string displayWor, string guessedletter, vector<string> guessedWord);



};

#endif