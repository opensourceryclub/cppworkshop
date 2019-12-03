# C++ Workshop

## Pre-Workshop

Before the workshop, it's important to get gcc set up.
If you're on Linux, it's probably in your distro's repositories. A simple ``sudo apt install gcc`` should do.

If you're on mac, I reccomend you install brew (if you don't have it, [this](https://brew.sh) website will explain). From there just ``brew install gcc``.

If you're on windows, you can either install [WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10), which is a virtual linux terminal, or follow [these instructions](https://geekstraw.com/compile-and-run-c-program-in-windows-10-using-command-prompt/)

I would also recommend making sure you have a decent text editor. If you
don't already have a favorite, some good examples include:

- GUI:
	- [Notepad++](https://notepad-plus-plus.org/)
	- [Atom](https://atom.io/)
- Terminal:
	- [nano](https://www.nano-editor.org/)
	- [vim](https://www.vim.org/)

## Introduction

C++ is an object oriented, compiled language that acts as something of an addition to C. Because of this, all C code will compile in C++! So, if you know C, you already kind of know C++.

## Compilation

There are a few ways to compile C++, but for very simple project just using
gcc will do. For larger projects, using a [make
file](https://www.gnu.org/software/make/manual/make.html) and maybe
something like [CMake](https://cmake.org/) makes things much simpler. IDEs
may have something built in to do this easier, but for this we'll just be
using gcc and a text editor. Anything from notepad to vim will do.

## Hello World First Draft

### Writing

First things first, let's create a simple HelloWorld program. There's one
available in this git repo in the examples folder, or you can just follow
along!

```cpp
#include <iostream>
```
Should go at the top of the file. ``#include <iostream>`` tells the
compiler to, well, include the iostream library. Next:
```cpp
int main(){
// Code goes here
}
```
This is the main function, which will run when we run the binary file.
Replace ``// Code goes here`` with the following:
```cpp
std::cout << "Hello world!";
std::cout << std::endl;
return 0;
```
The ``<<`` operator here is used as a stream insertion operator.
You can read ``std::cout`` as "standard c out", which makes it more clear
what it does. ``std::endl`` might be read as "standard end line." If you
don't include that, the next string you insert in the ``cout`` stream won't
be on a new line.

``return 0`` tells the program that it's not ending with an error. If it
returned any other number, it would recognize it as an error. This can mess
up things like shell scripting, so make sure you return 0 if it works!

### Compilation

Alright! Now that we have a simple statment going, let's take a look at
actually building the thing. Save the file, and head to the directory of it
in your terminal. Then run:

```bash
g++ -o bin <filename>
```
If you then run ls or dir, you should see the new file ``bin``, for binary.
That file is executable, so just run it with
``
./bin
``
kf on Linux/Mac, or
``
.\bin
``
if on windows.
You shoud get the following output:
```
Hello world!
```

### Slimming down the code

That code wasn't perfect, though. Let's look at the whole thing again:

```cpp
#include <iostream>

int main(){
	std::cout << "Hello world!";
	std::cout << std::endl;
	return 0;
}
```

First of all, two lines to print is a bit wordy, isn't it? Luckily, the
``<<`` operator can "chain." So replace those two lines with:
```cpp
std::cout << "Hello world!" << std::endl;
```
Cool, eh? But aren't those pesky ``std::``'s a bit annyoing? Well, luckily,
we can get rid of those by putting the following line of code after the
include statement(s):

```cpp
using namespace std;
```
This just tells the code to include everything in the std namespace
automatically. Now our line of code can look like:
```cpp
cout << "Hello world!" << endl;
```
Much nicer!

## User Input

Lets make a somewhat more complicated program, now. One that
takes in a number from the user, and checks if it's even or odd. Start out
just like hello world:
```cpp
#include <iostream>
using namespace std;

int main(){
	// Code goes here
}
```
Now, for the actual code. First, let's create an integer variable.
```cpp
int inpt;
```
If you've used java before, this syntax should be looking similar. For the
purposes of examples, I'll also create the check variable:
```cpp
int check = 2;
```
This will be the the number we check if the input is divisible by. Now, time
to prompt the user:
```cpp
cout << "Input a number: ";
```
If we don't add an ``endl``, the input will be placed on the same line,
which feels right. Now, to get the actual input:
```cpp
cin >> inpt;
```
``>>`` is the opposite of ``<<``. Rather than inserting something from a
stream, it extracts it. Don't forget to end the line after this.
```cpp
cout << endl;
```
Nice! Now, let's use that input. If statments are similar to most languages,
so I'll go through that more quickly!
```cpp
if ((inpt % 2) == 0){
	cout << "It's even!";
}
else{
	cout << "It's odd!";
}
cout << endl;
```
Finally, add the last return line:
```cpp
return 0;
```
Now, the entire program should look like this:
```cpp
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
```
Compile it the same way as before:
```bash
g++ -o bin2 <filename>
```
and run the bin2 file!
You're output should look like:
```
Input a number: 2
It's even!
```
or
```
Input a number: 3
It's odd!
```
Pretty simple!

## Header Files

Header files are very important in C++. They let you declare the details of
classes outside of their implementations. Make two files: one named
``dog.cpp`` and one named ``dog.hpp``. The ``dog.hpp`` file is a header
file. In dog.hpp, write the following:

```cpp
#ifndef DOG_H
#define DOG_H
```

This is a bit uncommon -- lines that have a # are instructions directly to
the compiler. In this case, we're telling it "is DOG_H" defined? If not,
define it!" This is important because otherwise if multiple files include
dog.hpp, you'd end up declaring the dog class multiple times.

```cpp
#include <string>
#include <iostream>
```
This is just telling it to include the string and input/output libraries.
Then, we're going to define a class:

```cpp
class dog{
	public:
		dog(std::string nameIn, std::string breedIn);
		std::string getName();
		std::string getBreed();
	private:
		std::string name;
		std::string breed;
}
```

If you've done object oriented-programming before, this should look
somewhat familiar. Note that we haven't actually defined any of the
variables or methods, just declared them. And uh oh, the ``std::``'s are
back! Well, we could use ``using namespace std;`` in a header file, but
it's frowned upon because it's prone to cause errors. Better safe than
sorry. Before we're done with this file, add the following to end:

```cpp
#endif
```

Remember that question we asked the compiler earlier? "Is DOG_H"
defined?  This is just telling it we're done with that now. It's like a
``}``. Now onto the cpp file. Start if off with this

```cpp
#include "dog.hpp"
```

No need to include <iostream\>, since we already included it in dog.hpp.

We're also free to use std by default, so add this.

```cpp
using namespace std;
```

Now then, how do we actually implement the class?

```cpp
dog::dog(string nameIn, string breedIn){
	name = nameIn;
	breed = breedIn;
}
```

``dog::dog`` is saying "in the dog class, we're talking about the dog
constructor." This is then followed by the arguments. Watch out, the
arguments
have to exactly like the ones in the header file, or it will cause
errors on compilation. Now lets implement the getters.

```cpp
string dog::getName(){
	return name;
}

string dog::getBreed(){
	return breed;
}
```

Finally, a main function!

```cpp
int main(){
	dog testDog = dog("Pico","Pug");
	cout << testDog.getName() << endl;
	cout << testDog.getBreed() << endl;
}
```

So, the full files look like this!

dog.hpp:
```cpp
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
}
#endif
```

dog.cpp:
```cpp
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
```
Compile it with

```bash
g++ -o binDog dog.cpp
```

and run the ``binDog`` file! You should get:

```
Pico
Pug
```

## Pointers
(if we have time)

I'm gong to explain something called pointers, which is pretty
unique in C and C++. This is going
to get complicated quick, so let's use the pointers.cpp file in the examples
folder to explain. It looks like this:

```cpp
#include <iostream>
#include "include/dog.hpp"
// This is including the dog class, which is in the dog.hpp and dog.cpp files

using namespace std;

int main(){
	dog dog1 = dog(string("Sam")); //Constructing a dog named Sam
	dog* dog2 = new dog(string("Pico")); //Constructing a dog named Toby, and getting it's pointer.
	cout << dog1.getName() << endl;
	cout << dog2->getName() << endl;
}
```

Wtf is all that about? What's with the ``->`` and the ``*``'s? Well, the
answer is pointers!

### What's a pointer?

Let's look at what happens when we don't use a pointer.

```cpp
dog dog1 = dog(string("Sam"));
```

This is saying "alright, I want a variable called dog1 to contain a dog
object with the name "Sam." So, what's with the other one?

```cpp
dog* dog2 = new dog(string("Pico"));
```

Well, ``new dog()`` is basically saying "create the dog object." No
weirdness there, but then why is ``dog2`` a ``dog*`` variable? Well, when
you use new to create an object, it doesn't actually return the object
itself. Instead it returns what's called a pointer, which is object's
address, rather than the object itself.
