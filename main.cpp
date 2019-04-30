#include <iostream>
#include "hanginDict.h"
#include "ascArt.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	string input;
	string Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
	string chosenWord;
	string displayWord;
	string guessedLetters;
	vector<string> guessedWords;

	ascArt allArt;
	hanginDict dict;
	
	int difficulty;
	int hangstate = 0;
	int wordsize;
	
	bool inMenu = true;
	bool victory = false;
	bool exit = false;
	bool alreadyguessed = false;

	while (!exit)
	{
		while (inMenu)
		{
			displayWord = "";
			guessedLetters = "";
			guessedWords.clear();
			allArt.printTitle();
			cout << Qinput;
			cin >> input;
			if (input[0] == 'X')
			{
				exit = true;
				break;
			}
			if (!isdigit(input[0]) || input.size() > 1)
			{
				Qinput = "Invalid input\nSelect difficulty(1 - 3):\n";
			}
			else
			{
				difficulty = stoi(input);
				if (difficulty > 3 || difficulty < 1)
				{
					Qinput = "Invalid input\nSelect difficulty(1 - 3):\n";
				}
				else
				{
					Qinput = "Guess a letter or word:\n";
					chosenWord = dict.selectWord(difficulty);
					wordsize = int(chosenWord.size());
					for (int i = 0; i < wordsize; i++)
					{
						displayWord += '_';
					}
					displayWord += '\n';
					inMenu = false;
				}
			}
		}
		while (!inMenu)
		{
			//	print the hangman art
			allArt.printHangman(hangstate);

			//	print the half guessed word
			for (int i = 0; i < wordsize; i++)
			{
				cout << displayWord[i] << ' ';
			}

			//	ask for input
			cout << "\nGuessed Words: ";
			for (int i = 0; i < int(guessedWords.size()); i++)
			{
				cout << guessedWords[i] << ' ';
			}
			cout << '\n' << "Guessed Letters: " << guessedLetters << '\n' << Qinput;
			cin >> input;

			bool guessflag = false;

			// 1 letter guess case
			if (input.size() == 1)
			{
				alreadyguessed = false;
				for (unsigned int i = 0; i < guessedLetters.size(); i++)
				{
					if (guessedLetters[i] == toupper(input[0]))
						alreadyguessed = true;
				}
				if (!alreadyguessed)
				{
					guessedLetters += toupper(input[0]); +' ';
					//check each letter
					for (int i = 0; i < wordsize; i++)
					{
						if (input[0] == chosenWord[i] || input[0] == toupper(chosenWord[i]))
						{
							guessflag = true;
							displayWord[i] = toupper(input[0]);
						}
					}
				}
			}

			// full word guess case
			else if (int(input.size()) == wordsize)
			{

				// convert input to lowercase for comparison
				for (int i = 0; i < wordsize; i++)
				{
					input[i] = tolower(input[i]);
				}

				bool wordAlreadyGuessed = false;

				for (int i = 0; i < int(guessedWords.size()); i++)
				{
					wordAlreadyGuessed = true;
					for (int j = 0; j < wordsize; j++)
					{
						if (input[j] != guessedWords[i][j])
						{
							wordAlreadyGuessed = false;
							break;
						}
					}
					if (wordAlreadyGuessed)
					{
						alreadyguessed = true;
						break;
					}
				}
				if (!wordAlreadyGuessed)
				{
					guessedWords.push_back(input);

					victory = true;
					guessflag = true;


					// check each letter
					for (int i = 0; i < wordsize; i++)
					{
						if (input[i] != chosenWord[i])
						{
							victory = false;
							guessflag = false;
						}
					}
				}
			}
			else
				Qinput = "Invalid input\nGuess a letter or word:\n";
			if (!alreadyguessed)
			{
				if (!guessflag && hangstate < 7)
					hangstate++;
				if (hangstate == 6)
				{
					inMenu = true;


					allArt.printHangman(hangstate);

					for (int i = 0; i < wordsize; i++)
						cout << char(toupper(chosenWord[i])) << ' ';
					cout << "\nPress any key to continue:\n";
					cin >> input;
					allArt.printFail();
					cout << "Press any key to return to menu\n";
					cin >> input;
					Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
					hangstate = 0;
				}

				//check for victory

				if (!victory)
				{
					string compWord;
					victory = true;
					for (int i = 0; i < wordsize; i++)
					{
						compWord += toupper(chosenWord[i]);
					}
					for (int i = 0; i < wordsize; i++)
					{
						if (compWord[i] != displayWord[i])
						{
							victory = false;
							break;
						}
					}
				}
				if (victory == true)
				{
					inMenu = true;
					allArt.printHangman(hangstate);
					for (int i = 0; i < wordsize; i++)
						cout << char(toupper(chosenWord[i])) << ' ';
					cout << "\nPress any key to continue:\n";
					cin >> input;
					hangstate = 0;
					allArt.printVictory(difficulty);
					cout << "Press any key to return to menu\n";
					cin >> input;
					Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
					victory = false;
				}
			}
		}
	}
}