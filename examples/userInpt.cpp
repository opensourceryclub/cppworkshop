#include <iostream>

using namespace std;

int main(){
	int check = 2;
	int inpt;
	cout << "Input a number: ";
	cin >> inpt;
	cout << endl;
	if ((inpt % check) == 0) {
		cout << "It's even!";
	}
	else {
		cout << "It's odd!";
	}
	cout << endl;
	return 0;
}
