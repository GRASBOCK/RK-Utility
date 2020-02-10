/*

Commandline Parameter Management
This allows the user to give the program a string of commandline parameters (or arguments) 
and they will be automatically identified and passed to the corresponding functions.
The order doesn't matter and not all arguments have to be specified
Interpretation is up to the user. 
This class just passes the argumentvalues to the user defined functions.

EXAMPLE:

functions
saveArgument(char* value);
speedArgument(char* value);
nameArgument(char* value);

command line arguments
name=Richard save=true kefir=drink

name=Richard is arg[0] cstring and its value[0] = "Richard"
speed=10.0 is arg[1] cstring and its value[1] = "10.0"
kefir=drink is arg[2] cstring and its value[2] = "drink"

executes functions
nameArgument("Richard");
speedArgument("10.0");
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
			return true on success
		*/
		bool interpret(char* argument, std::string delimiter = "=");
		
		/*
		iterates through all arguments in the array
		sends the value to the appropriate function
			returns the amount of failed recognition attempts
		*/
		unsigned int interpret(int argumentCount, char* arguments[], std::string delimiter = "=");

	}
}

