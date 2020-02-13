# RK-Utility
This repository contains my own utility stuff, that I use often.

<p>
<ul class="toc_list">
	<li><a href="#CAP">Command Argument Parser</a>
		<ul>
			<li><a href="#CAP_usage">Usage</a></li>
			<li><a href="#CAP_example">Example</a></li>
		</ul>
	</li>
	<li><a href="#Future Content">Future Content</a></li>
</ul>
</p>

<h2 id="CAP">Command Argument Parser</h2>

Allows the user to give the program a string of commandline arguments and they will be automatically identified and passed to the corresponding functions. 
<ul class="toc_list">
	<li>order in which the arguments are written doesn't matter</li>
	<li>interpretation of the values is up to the user</li>
	<li>not all arguments have to be specified by the one typing in the command, even if the user has specified more options</li>
</ul>

<h3 id="CAP_usage">Usage</h3>
Write an interpreter function for the values passed to the argument by the user<br>

```
void interpretTest(std::string value){
	std::cout << "test: " << value << std::endl;
}
```

set parameters and associate them with their interpreter function<br>

```
RK::CAP::parameterFunctions = {
	{"test", interpretTest}
};
```

run interpreter on all arguments (in this example taken from commandline)<br>

```
try{
	//first argument is always the program executable
	RK::CAP::interpret(argc - 1, &argv[1]);
}catch(std::exception& e){
	std::cerr << e.what() << std::endl;
}
```

<h3 id="CAP_example">Example</h3>

```
#include <iostream>
#include <exception>
#include "CAP.hh"

//interpreter functions
void test(std::string value){
	std::cout << "test: " << value << std::endl;
}
void sausage(std::string value){
	std::cout << "sausage: " << value << std::endl;
}
void beer(std::string value){
	std::cout << "beer: " << value << std::endl;
}

int main(int argc, char* argv[]){

	//set up parameters
	RK::CAP::parameterFunctions = {
		{"test", test},
		{"sausage", sausage},
		{"beer", beer}
	};

	//run interpreter on all arguments
	try{
		//first argument is always the program executable
		RK::CAP::interpret(argc - 1, &argv[1]);
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
```
If you run your application like this:<br>
```
applicationName test=4 beer=drinkingContest bullshit=failure sausage=meat
```
You will receive following message:
```
test: 4
beer: drinkingContest
[RK::CAP::interpret()] No Interpreter function for "bullshit" in "bullshit=failure" found.
```

<p>
I know Cmake is a bit overkill at this size of a project. <br>
I will add new libraries to it later though.
</p>
