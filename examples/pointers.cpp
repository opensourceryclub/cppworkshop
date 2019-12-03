#include <iostream>
#include <string>
#include "include/dog.hpp"
// This is including the dog class, which is in the dog.hpp and dog.cpp files

using namespace std;

int main(){
	int i = 4;
	int* p = &i;
	cout << *p + 4 << endl;
	dog dog1 = dog(string("Sam")); //Constructing a dog named Sam
	dog* dog2 = new dog(string("Pico")); //Constructing a dog named Toby, and getting it's pointer.
	cout << dog1.getName() << endl;
	cout << dog2->getName() << endl;
}
