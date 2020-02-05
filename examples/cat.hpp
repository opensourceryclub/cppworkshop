#ifndef CAT_H
#define CAT_H
#include <string>
#include <iostream>

class cat{
	public:
		cat(std::string nameIn, std::string breedIn);
		std::string describe();
		std::string makeSound();
	private:
		std::string name;
		std::string breed;
};
#endif

