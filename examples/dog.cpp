#include "dog.hpp"
using namespace std;

dog::dog(string nameIn, string breedIn){
	name = nameIn;
	breed = breedIn;
}

string dog::getName(){
	return name;
}

string dog::getBreed(){
	return breed;
}

int main(){
	dog testDog = dog("Pico","Pug");
	cout << testDog.getName() << endl;
	cout << testDog.getBreed() << endl;
}
