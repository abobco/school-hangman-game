#include <iostream>
#include "hanginDict.h"
#include "ascArt.h"

using namespace std;

int main()
{
	string input;
	string Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
	string chosenWord;
	string displayWord;
	string guessedLetters;

	ascArt allArt;
	hanginDict dict;
	
	int difficulty;
	int hangstate = 0;
	int wordsize;
	
	bool inMenu = true;
	bool victory = false;
	bool exit = false;

	while (!exit)
	{
		while (inMenu)
		{
			displayWord = "";
			guessedLetters = "";
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
					wordsize = chosenWord.size();
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
			cout << '\n' << "Guessed Letters: " << guessedLetters << '\n' << Qinput;
			cin >> input;

			bool guessflag = false;

			// 1 letter guess case
			if (input.size() == 1)
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

			// full word guess case
			else if (input.size() == wordsize)
			{
				victory = true;

				// convert input to lowercase for comparison
				for (int i = 0; i < wordsize; i++)
				{
					input[i] = tolower(input[i]);
				}
				// check each letter
				for (int i = 0; i < wordsize; i++)
				{
					if (input[i] != chosenWord[i])
					{
						victory = false;
					}
				}
			}
			else
				Qinput = "Invalid input\nGuess a letter or word:\n";

			if (!guessflag && hangstate < 7)
				hangstate++;
			if (hangstate == 6)
			{
				inMenu = true;
				hangstate = 0;
				allArt.printFail();
				cout << "Press any key to return to menu\n";
				cin >> input;
				Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
			}
			
			//check for victory

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
			if (victory == true)
			{
				inMenu = true;
				hangstate = 0;
				allArt.printVictory();
				cout << "Press any key to return to menu\n";
				cin >> input;
				Qinput = "Select difficulty(1 - 3) or type 'X' to exit:\n";
			}

		}
	}
}