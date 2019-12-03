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
