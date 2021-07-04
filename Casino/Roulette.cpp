#include "Roulette.h"
#include <iostream>
#include "Utility.h"
#include "Casino.h"
#include <stdlib.h>
#include <time.h>
using namespace std;



void playRoulette() {
	int select;
	srand((unsigned int)time(NULL));
	clearConsole();
	cout << "You chose Roulette" << endl;

	cout << "1. Play" << endl << "2. Rules" << endl << "3. Back" << endl;
	cin >> select;
	select = validateSelect(3, cin.fail(), select);


	switch (select)
	{
	case 1: // play game
		SelectNumbers();
		break;
	case 2: // get rules
		rules(3);
		system("pause>0");
		playRoulette();
		break;
	case 3: // go back
		main();
		break;
	}
}

void SelectNumbers() {
	int select;
	int choiceType;
	int choice;
	cout << "Please select how you would like to bet" << endl;
	cout << "1. Specific Number" << endl << "2. Red/Black" << endl << "3. Odd/Even" << endl << "4. Back" << endl;
	cin >> select;
	select = validateSelect(4, cin.fail(), select);


	switch (select)
	{
	case 1: // Specific number
		choice = 0;
		choiceType = 1;
		while (choice < 1 || choice > 34) { //checks input is between 1 and 34
		cout << "Please enter a number between 1 and 34 to bet on" << endl;
		cin >> choice;
		}
		Spinwheel(choiceType, choice);
		break;
	case 2: // red/black
		choice = 0;
		choiceType = 2;
		while (choice < 1 || choice > 2) { //checks input is between 1 and 2
			cout << "Please enter 1 to bet on Red or 2 to bet on Black" << endl;
			cin >> choice;
		}
		Spinwheel(choiceType, choice);
		break;
	case 3: // odd/even
		choice = 0;
		choiceType = 3;
		while (choice < 1 || choice > 2) { //checks input is between 1 and 2
			cout << "Please enter 1 to bet on Odd or 2 to bet on Even" << endl;
			cin >> choice;
		}
		Spinwheel(choiceType, choice);
		break;
	case 4: // go back
		playRoulette();
		break;
	}
}

void Spinwheel(int choiceType, int choice) {
	int result;
	bool playerWin = false;
	string resultColour;
	result = rand() % 34 + 1; //generates result value betwen 1 and 34
	if ((result < 11 )|| (result > 18 && result < 29)) { //checks if result was black or red
		if (result % 2 == 0) {
			resultColour = "Black"; 
		}
		else {
			resultColour = "Red";
		}
	}
	else {
		if (result % 2 == 0) {
			resultColour = "Red";
		}
		else {
			resultColour = "Black";
		}
	}
	
	cout << "choiceType: " << choiceType << " choice: " << choice << endl;
	cout << "The winning number is " << result << " " << resultColour << endl;

	switch (choiceType)
	{
	case 1:
		if (result == choice) { // if player guessed correct number > win
			playerWin = true;
		}
		break;
	case 2: //if player guessed correct colour > win
		if (choice == 1 && resultColour == "Red") {
			playerWin = true;
		}
		else if (choice == 2 && resultColour == "Black") {
			playerWin = true;
		}
		break;
	case 3: // if player guessed odd/even correctly > win
		if (choice == 1) {
			if (result % 2 != 0) { 
				playerWin = true;
			}
		}
		else if (choice == 2) {
			if (result % 2 == 0) {
				playerWin = true;
			}
		}
		break;
	}

	if (playerWin) { //outputs result
		cout << "You Win!" << endl;
	}
	else {
		cout << "You Lose" << endl;
	}
	pause();
	playRoulette();
}


