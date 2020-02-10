/*

Commandline Parameter Management
This allows the user to give the program a string of commandline arguments 
and they will be automatically identified and passed to the corresponding functions. 
The order in which the arguments are written doesn't matter and not all arguments 
have to be specified. Interpretation of the values is up to the user. 
The user has to create a function for each argument that handles the value. 

EXAMPLE:

functions
saveInterpret(std::string value);
speedInterpret(std::string value);
nameInterpret(std::string value);

command line arguments
name=Richard save=true kefir=drink

name=Richard is arg[0] cstring and its value[0] = "Richard"
speed=10.0 is arg[1] cstring and its value[1] = "10.0"
kefir=drink is arg[2] cstring and its value[2] = "drink"

executes functions
nameInterpret("Richard");
speedInterpret("10.0");
>exception kefir is unknown parameter

*/

#pragma once

#include <string>
#include <map>

namespace RK{
	namespace CPM{
		//defines the structure of an interpreter function
		typedef void (*interpreterFunc)(std::string value);

		//holds all the parameters
		extern std::map<const std::string, interpreterFunc> parameterFunctions;

		/*
		extracts the parameter by looking at the string before the delimiter
		*/
		std::string extractParameter(char* argument, std::string delimiter = "=");

		/*
		extracts the value by looking at the string after the delimiter
			on success returns the value as a string
			on failure returns an empty string
		*/
		std::string extractValue(char* argument, std::string delimiter = "=");
		
		/*
		sends the value to the appropriate function
		*/
		void interpret(char* argument, std::string delimiter = "=");
		
		/*
		iterates through all arguments in the array
		sends the value to the appropriate function
		*/
		void interpret(int argumentCount, char* arguments[], std::string delimiter = "=");

	}
}

