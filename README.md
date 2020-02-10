# Commandline-Parameter-Manager
A simple commandline argument manager. 

This allows the user to give the program a string of commandline arguments and they will be automatically identified and passed to the corresponding functions. The order in which the arguments are written doesn't matter and not all arguments have to be specified. Interpretation o fthe values is up to the user. The user has to create a function for each argument that handles the value. 

<h3> EXAMPLE: </h3>

```
#include <iostream>
#include <exception>
#include "CPM.hh"

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
	RK::CPM::parameterFunctions = {
		{"test", test},
		{"sausage", sausage},
		{"beer", beer}
	};

	//run interpreter on all arguments
	try{
		//first argument is always the program executable
		RK::CPM::interpret(argc - 1, &argv[1]);
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
[RK::CPM::interpret()] No Interpreter function for "bullshit" in "bullshit=failure" found.
```

<p>
I know Cmake is a bit overkill at this size of a project (it was for learning purposes). <br>
Maybe I will make it a header only in the future.
</p>
