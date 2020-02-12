#pragma once

#include <string>
#include <map>

namespace RK{
	namespace CAP{
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

