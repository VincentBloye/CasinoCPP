#pragma once
#include <string>

using namespace std;
class Card
{
public:
	Card(int v);
	string getName();
	int getValue();
private:
	int value;
	string name;
	string setName(int v);
	int setValue(int v);
	
};

