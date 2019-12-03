#ifndef DOG_H
#define DOG_H
#include <string>
#include <iostream>

class dog{
	public:
		dog(std::string nameIn, std::string breedIn);
		std::string getName();
		std::string getBreed();
	private:
		std::string name;
		std::string breed;
};
#endif
