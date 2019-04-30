#include "saveState.h"

saveState::saveState()
{

}

void saveState::load()
{
	iFile.open("save.txt");
	string line;
	int count = 0;
	if (iFile)
	{
		getline(iFile, line);
		difficulty = stoi(line);

		getline(iFile, line);
		wordsize = stoi(line);

		getline(iFile, line);
		hangstate = stoi(line);

		getline(iFile, line);
		chosenWord = line;

		getline(iFile, line);
		displayWord = line;
	}
	iFile.close();

	iFile.open("saveGuessedLetters.txt");
	if(iFile)
	{

		getline(iFile, line);
		guessedLetters = line;
	}
	iFile.close();

	iFile.open("saveGuessedWords.txt");
	while (iFile)
	{
		getline(iFile, line);
		guessedWords.push_back(line);
	}
	iFile.close();
}

void saveState::save(int difficult, int wordsiz, int hangstat, string chosenWor, string displayWor, string guessedletter, vector<string> guessedWord)
{
	oFile.open("save.txt");

	oFile << difficult << endl << wordsiz << endl << hangstat << endl << chosenWor << endl << displayWor;
	oFile.close();

	oFile.open("saveGuessedLetters.txt");
	oFile << guessedletter;
	oFile.close();

	oFile.open("saveGuessedWords.txt");
	for (int i = 0; i < int(guessedWord.size()); i++)
		oFile << guessedWord[i] << endl;
	oFile.close();

}