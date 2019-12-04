#include <iostream>
#include <string>
#include "dog.hpp"

// This is including the dog class, which is in the dog.hpp and doglib.cpp files.
//doglib is exactly the same as dog.cpp, but without the main function

using namespace std;

void multiplyByTwo(int* inpt){
	*inpt = *inpt * 2;
}

int main(){
	int i = 4;
	dog dog1 = dog("Sam","German Shepard"); // Construct a dog named Sam
	dog* dog2 = new dog("Pico","Pug"); //Construct a dog named Toby, and get it's pointer.
	cout << dog1.getName() << endl;
	cout << dog2->getName() << endl;
	int* p = &i;
	cout << *p + 2 << endl;
	cout << "Original value: " << *p << endl;
	multiplyByTwo(p);
	cout << "New value: " << *p << endl;
	delete dog2;
}
