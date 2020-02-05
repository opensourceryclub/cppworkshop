# C++ Workshop

## Pre-Workshop

Before the workshop, it's important to get gcc set up.
If you're on Linux, it's probably in your distro's repositories. A simple ``sudo apt install gcc g++`` should do.

If you're on mac, I reccomend you install brew (if you don't have it, [this](https://brew.sh) website will explain). From there just ``brew install gcc``.

If you're on windows, you can either install [WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10), which is a virtual linux terminal, and then follow the Linux instructions, or follow [these instructions](https://geekstraw.com/compile-and-run-c-program-in-windows-10-using-command-prompt/)

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

## Cats!

Today, we'll be making a program that lets you play with cats, 'cause aren't
they the cutest?

### Starting

First things first, let's create the barebones of the program. There's one
available in this git repo in the examples folder, or you can just follow
along!

```cpp
#include <iostream>
#include <string>
```
Should go at the top of the file. ``#include`` tells the
compiler to, well, include the given library. Next:
```cpp
int main(){
// Code goes here
}
```
This is the main function, which will run when we run the binary file.
Replace ``// Code goes here`` with the following:
```cpp
std::cout << "What's the cat's name?" << std::endl;

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
if on Linux/Mac, or
``
.\bin
``
if on windows.
You shoud get the following output:
```
"What's the cat's name?"
```

## User Input

We haven't made much more than hello world, though. Let's make it take in
the user's name! Remember, this is what we have:

```cpp
#include <iostream>
#include <string>

int main(){
	std::cout << "What's the cat's name?" << std::endl;

	return 0;
}
```
First, let's create a string variable above the output.
```cpp
std::string name;
```
If you've used java before, this syntax should be looking similar, except
for that pesky ``std::``. That's going to get annoying to type, so after
the include statements add
```cpp
using namespace std;
```
Now we don't have to keep typing that over and over again! This is just
saying "automatically use namespace std." In some contexts, this can be
dangerous, but here it's fine. Delete all those ``std::``'s now!
Now, to get the actually get the user input:
```cpp
cin >> name;
```
``>>`` is the opposite of ``<<``. Rather than inserting something from a
stream, it extracts it. You don't need to end the line here.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(){
	string name;
	cout << "What's the cat's name?";
	cin >> name;

	return 0;
}
```
## Header Files

Header files are very important in C++. They let you declare the details of
classes outside of their implementations. Make a file called``cat.hpp``. The
``cat.hpp`` file is a header file. In cat.hpp, write the following:

```cpp
#ifndef CAT_H
#define CAT_H
```

This is a bit uncommon -- lines that start with # are instructions directly
to the compiler. In this case, we're telling it "is CAT_H" defined? If not,
define it with the following!" This is important because otherwise if
multiple files include cat.hpp, you'd end up declaring the cat class
multiple times.

```cpp
#include <string>
#include <iostream>
```
This is just telling it to include the string and input/output libraries.
Then, we're going to define a class:

```cpp
class cat{
	public:
		cat(std::string nameIn, std::string breedIn);
		std::string describe();
		std::string makeNoise();
	private:
		std::string name;
		std::string breed;
}
```

If you've done object oriented-programming before, this should look somewhat
familiar. Note that we haven't actually defined any of the variables or
methods, just declared them. And uh oh, the ``std::``'s are back! Well, we
could use ``using namespace std;`` in a header file, but it's frowned upon
because it's prone to cause errors. Better safe than sorry. Before we're
done with this file, add the following to end:

```cpp
#endif
```

Remember that question we asked the compiler earlier? "Is CAT_H"
defined?  This is just telling it we're done with that now. It's like a
``}``. Now back to the cpp file. First things first, we need the header file
we wrote!
```cpp
#include "cat.hpp"
```

Now we need to actually implement the class.
Well, before the main function, add this.

```cpp
cat::cat(string nameIn, string breedIn){
	name = nameIn;
	breed = breedIn;
}
```

``cat::cat`` is saying "in the cat class, I'm defining the constructor."
This is then followed by the arguments. Watch out, the arguments have to be
exactly like the ones in the header file, or it will cause errors on
compilation. Now lets implement the describe function.

```cpp
string cat::describe(){
	string out = name.append(" is a ").append(breed).append(" cat!");
	return out;
}
```

And the makeNoise function!

```cpp
string cat::makeNose(){
	return "Purr!"
}
```

Finally, let's test it in the main function!

```cpp
int main(){
	string name;
	cout << "What's the cat's name?";
	cin >> name;
	cat cat1 = cat(name,"snowshoe");
	cout << cat1.describe() << endl;

	return 0;

}
```

If you use java, you might have noticed the lack of "new" to create an object. Well, "new" actually does something else in C++, actually! To just create an object, we don't need it. So, the full files look like this!

cat.hpp:
```cpp
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
}
#endif
```

cat.cpp:
```cpp
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
	return "Purr!"
}

int main(){
	string name;
	cout << "What's the cat's name?";
	cin >> name;
	cout << endl;
	cat cat1 = cat(name,"snowshoe");
	cout << cat1.describe() << endl;
	cout << cat1.makeNoise() << endl;

	return 0;

}
```
Compile it with

```bash
g++ -o bin cat.cpp
```

and run the ``bin`` file! You should get:

```
What's the cat's name? <Input>
<Input> is a snowshoe cat!
Purr!
```

Hmm... just for fun, let's make it a little more complex.  Let's move the
current main into a seperate function and build most of the interface
seperately. Most everything from here is pretty much java syntax.

```cpp
cat makeCat(){
	cout << "What should it's name be? "
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
		elif (cmd == "pet"){
			cout <<	yourCat.makeSound() << endl;

		}
		elif (cmd == "done"){
			cout << "Thanks for playing!" << endl;
			done = true;
		}
		elif (cmd == "look"){
			cout << yourCat.describe() << endl;
		}
		else{
			cout << "That isn't a command." << endl;
		}
	}
}
```

## Pointers
(if we have time)

I'm gong to explain something called pointers, which is pretty
unique in C and C++. This is going
to get complicated quick, so let's use the pointers.cpp file in the examples
folder to explain. It looks like this:

```cpp
#include <iostream>
#include "cat.hpp"

using namespace std;

cat::cat(string nameIn, string breedIn){
	name = nameIn;
	breed = breedIn;
}

string cat::getName(){
	return name;
}

string cat::getBreed(){
	return breed;
}

string cat::makeNoise(){
	return "Purr!"
}

void multiplyByTwo(int* inpt){
	*inpt = *inpt * 2;
}

int main(){
	cat cat1 = cat("Isabelle","Tabby"); // Construct a cat named
	Isabelle
	cat* cat2 = new cat("Otto","Raas"); //Construct a cat named Otto, and get it's pointer.
	cout << cat1.getName() << endl;
	cout << cat2->getName() << endl;
	int* p = &i;
	cout << *p + 2 << endl;
	cout << "Original value: " << *p << endl;
	multiplyByTwo(p);
	cout << "New value: " << *p << endl;

	delete cat2;
}
```

Wtf is all that about? What's with the ``->`` and the ``*``'s? Well, the
answer is pointers!

### What's a pointer?

Let's look at what happens when we don't use a pointer.

```cpp
cat cat1 = cat(string("Isabelle"));
```

This is saying "alright, I want a variable called cat1 to contain a cat
object with the name "Isabelle." So, what's with the other one?

```cpp
cat* cat2 = new cat(string("Otto"));
```

Well, ``new cat()`` is basically saying "create the cat object." No
weirdness there, but then why is ``cat2`` a ``cat*`` variable? Well, when
you use new to create an object, it doesn't actually return the object
itself. Instead it returns what's called a pointer, which is object's
address, rather than the object itself. If you've used Java, in that
language pretty much every variable that's not a primitive is a "pointer." In
C++, though, you have to explicitly state the difference. You can also get
the address of a variable -- or the pointer -- like this

```cpp
cat* catPointer = &cat1;
```

You can even take this to it's logical extreme like this:

```cpp
cat** catPointerPointer = &catPointer;
```

That's a pointer of a pointer. After all, pointers take up memory too! They
have addresses! You can also get the pointer of primitive types, as shown
in.

```cpp
int* p = &i
```

From there, you can get pointee by putting a ``*`` before the name.

```cpp
cout << *p + 2 << endl;
```

Finally, at the end, we have to include the following line

```cpp
delete cat2;
```

We created the ``cat2`` variable with ``new``, which means unless we do
something ``cat2`` will just be floating around in the void of our memory,
it won't get deleted once we exit the scope. We need that space for other
stuff! So we have to explicitly delete it. In this specific case it's not
entirely neccesary, since the program ends, but it's important to remember
this when making larger projects.

### Why Use Pointers?

Well, once of the cool things about pointers is their pointees are mutable.
You can make a function that takes in a pointer and then edits that object
directly, rather than having to mess around with creating a copy and then
returning it. You can see that when p is passed into multiplyByTwo, but
multiplyByTwo doesn't return anything. Instead it directly manipulates p. It
also allows for stuff like two objects referencing each other without
creating an infinite loop. It also makes it a lot easier on the memory to be
tossing about addresses rather than full objects, so it's part of efficient
coding.
