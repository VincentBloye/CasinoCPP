#include "Blackjack.h"
#include "Utility.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Casino.h"
#include "Card.h"
#include <vector>

using namespace std;

vector<Card> playerCards, dealerCards; // initialises vector of card objects
int playerScore = 0, dealerScore = 0;

void playBlackjack() {
	int select;
	playerCards.clear(); //resets variables
	dealerCards.clear();
	playerScore = 0;
	dealerScore = 0;
	srand((unsigned int)time(NULL));
	clearConsole();
	cout << "You chose Blackjack" << endl;

	cout << "1. Play" << endl << "2. Rules" << endl << "3. Back" << endl;
	cin >> select;
	select = validateSelect(3, cin.fail(), select);


	switch (select)
	{
	case 1: // play game
		dealHand();
		break;
	case 2: // get rules
		rules(2);
		system("pause>0");
		playBlackjack();
		break;
	case 3: // go back
		main();
		break;
	}
}

void dealHand() { //deals 2 cards to player and dealer
	
	playerCards.push_back(dealCard()); // adds card to vector stack
	dealerCards.push_back(dealCard());
	playerCards.push_back(dealCard());
	dealerCards.push_back(dealCard());
	playerScore = updateScore(playerCards);
	dealerScore = updateScore(dealerCards);
	showHand();
	playerAction();
}

void playerAction() {
	int select = 0;

	while (select < 1 || select > 2) {
		cout << "1. Stick   2. Hit " << endl;
		cin >> select;
		select = validateSelect(3, cin.fail(), select);

		if (select == 1) {
			results();
		}
		else if (select == 2) { //deals another card to player
			playerCards.push_back(dealCard());
			playerScore = updateScore(playerCards);
			showHand();
			if (playerScore > 21) { // player loses if score above 21
				cout << "You went bust" << endl << "Press enter to return to the menu..." << endl;
				cin;
				pause();
				playBlackjack();
			}
			playerAction();
		}
	}

}

void results() {
	cout << "Your score was " << playerScore << endl;
	cout << "The dealers score was " << dealerScore << endl;
	if (playerScore > dealerScore) { //player wins if score above dealers
		cout << "You Win!" << endl;
	}
	else {
		cout << "You Lose" << endl; //players loses if score below dealers
	}
	pause();
	playBlackjack();
}

int updateScore(vector<Card> hand) { //updates score based in card vector parameter
	int score= 0;
	for (int i = 0; i < (int) hand.size(); i++) {
		score += hand[i].getValue();
	}
	return score;
}

int dealCard() {
	int value;
	value = rand() % 13 + 1; //generates value between 1 and 13
	return value;
}

void showHand() {
	cout << "Your cards are: " << endl;
	for (int i = 0; i < (int)playerCards.size(); i++) { //displays cards to user
		cout << playerCards[i].getName() << endl;
	}
	cout << "Your total is: " << playerScore << endl;
}