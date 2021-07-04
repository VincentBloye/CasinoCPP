#pragma once
#include<iostream>
using namespace std;
inline void clearConsole() { system("cls"); }; // clears console
int validateSelect(int max, bool fail, int choice);
inline void rules(int game) { //displays rules for selected game
	switch (game)
	{
	case 1:
		cout << "if all three items match, you win" << endl;
		break;
	case 2:
		cout << "if your total is above the dealer's total, and less than or equal to 21, you win" << endl;
		break;
	case 3:
		cout << "if the ball lands on your selection, you win" << endl;
		break;
	}
	cout << "Continue..." << endl;
};
inline void pause() { system("pause"); } // waits for user input