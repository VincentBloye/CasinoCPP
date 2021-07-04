#include <limits>
#include <iostream>

using namespace std;

int validateSelect(int max, bool fail, int choice) { // outputs message if input is invalid
	bool valid = true;
	while (1) {
		if (fail) {
			valid = false;
		}
		else if (choice < 1 || choice > max) {
			valid = false;
		}
		else {
			valid = true;
		}
		if (!valid) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please try again" << endl;
			cin >> choice;
		}
		else {
			break;
		}
	}
	return choice;
}