#include "cat.hpp"
using namespace std;

cat::cat(string nameIn, string breedIn){
	name = nameIn;
	breed = breedIn;
}

string cat::describe(){
	string out = name.append(" is a ").append(breed).append(" cat!");
	return out;
}

string cat::makeSound(){
	return "Purr!";
}

cat makeCat(){
	string name;
	string breed;
	cout << "What should it's name be? ";
	cin >> name;
	cout << "It's breed? ";
	cin >> breed;
	return cat(name,breed);
}

int main(){
	bool done = false;
	string cmd;
	string name;
	string breed;
	cat yourCat = makeCat();
	while (!done){
		cout << "Please input a command (new, pet, look, or done): ";
		cin >> cmd;
		if (cmd == "new"){
			yourCat = makeCat();
		}
		else if (cmd == "pet"){
			cout <<	yourCat.makeSound() << endl;

		}
		else if (cmd == "done"){
			cout << "Thanks for playing!" << endl;
			done = true;
		}
		else if (cmd == "look"){
			cout << yourCat.describe() << endl;
		}
		else{
			cout << "That isn't a command." << endl;
		}
	}
}
