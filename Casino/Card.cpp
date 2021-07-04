#include "Card.h"
Card::Card(int v)
{
	
	name = setName(v);
	value = setValue(v);
	
}

int Card::getValue() {
	return value;
}

string Card::getName() {
	return name;
}

string Card::setName(int v) { //sets name of card
	string n;
	switch (v)
	{
	case 1:
		n = "Ace";
		break;
	case 2:
		n = "Two";
		break;
	case 3:
		n = "Three";
		break;
	case 4:
		n = "Four";
		break;
	case 5:
		n = "Five";
		break;
	case 6:
		n = "Six";
		break;
	case 7:
		n = "Seven";
		break;
	case 8:
		n = "Eight";
		break;
	case 9:
		n = "Nine";
		break;
	case 10:
		n = "Ten";
		break;
	case 11:
		n = "Jack";
		break;
	case 12:
		n = "Queen";
		break;
	case 13:
		n = "King";
		break;
	}
	return n;
}

int Card::setValue(int v) { //sets value of card
	if (v > 9) { // face cards = 10
		v = 10;
	}
	return (v);
}
