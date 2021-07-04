#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Utility.h"
#include "Slots.h"
#include "Casino.h"

using namespace std;


void playSlots() {
	int select;
	srand((unsigned int)time(NULL));
	clearConsole();
	cout << "You chose slots" << endl;

	cout << "1. Play" << endl << "2. Rules" << endl << "3. Back" << endl;
	cin >> select;
	select = validateSelect(3, cin.fail(), select);


	switch (select)
	{
	case 1: // play game
		rollSlots();
		break;
	case 2: // get rules
		rules(1);
		system("pause>0");
		playSlots();
		break;
	case 3: // go back
		main();
		break;
	}
}



void rollSlots() {
	vector<string> slotIcons{ "Bar", "Bell", " 7 " }; //vector of slot icons
	vector<int> slots(3); //id of slot icons
	for (int i = 0; i < 3; i++) {
		slots[i] = rand() % 3; //random number between 0 and 2
		//slots[i] = 2;
	}
	cout << "----- SLOT MACHINE -----" << endl;
	cout << slotIcons[slots[0]] << "       " << slotIcons[slots[1]] << "       " << slotIcons[slots[2]] << endl; //display slot machine
	if (slots[0] == slots[1] && slots[1] == slots[2]) {
		if (slots[0] == 2) {
			cout << "JACKPOT!" << endl; // if all 7 > jackpot
		}
		else
		{
			cout << "YOU WIN!" << endl; // if all match > win
		}
	}
	else {
		cout << "YOU Lose!" << endl; // if slots do not match > lose
	}
	cout << endl;
	cout << "Play again Y/N" << endl;
	string playAgain;
	cin >> playAgain;
	if (playAgain == "Y" || playAgain == "y") { //reroll or return to main menu
		rollSlots();
	}
	else {
		main();
	}
}