#include <iostream>
#include "Casino.h"
#include <vector>
#include "Utility.h"
#include "Slots.h"
#include "Blackjack.h"
#include "Roulette.h"


using namespace std;

int main()
{
	int select;
	clearConsole();
	cout << "Select the game you wish to play" << endl;
	cout << "1. Slots" << endl << "2. Blackjack" << endl << "3. Roulette" << endl;
	cin >> select; // read input
	select = validateSelect(3, cin.fail(), select); // validate input
	switch (select)
	{
	case 1:
		playSlots();
		// slots
		break;
	case 2:
		playBlackjack();
		// blackjack
		break;
	case 3:
		playRoulette();
		// roulette
		break;
	}
}