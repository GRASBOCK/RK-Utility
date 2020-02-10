#include <iostream>

#include "CPM.hh"

std::map<const std::string, RK::CPM::interpreterFunc> RK::CPM::parameterFunctions;

std::string RK::CPM::extractParameter(char* arg, std::string delimiter){
	std::string argument = arg;
	std::string parameter;
	size_t delimiterIndex = argument.find(delimiter);
	if(delimiterIndex != std::string::npos)
		parameter = argument.substr(0, delimiterIndex);
	return parameter;
}

std::string RK::CPM::extractValue(char* arg, std::string delimiter){
	std::string argument = arg;
	std::string parameter;
	size_t delimiterIndex = argument.find(delimiter);
	std::string value;
	if(delimiterIndex != std::string::npos)
		value = argument.substr(delimiterIndex + 1, argument.size());
	return value;
}

bool RK::CPM::interpret(char* arg, std::string delimiter){
	std::string argument = arg;
	size_t delimiterIndex = argument.find(delimiter);
	if(delimiterIndex != std::string::npos){
		std::string parameter = argument.substr(0, delimiterIndex);
		auto it = parameterFunctions.find(parameter);
		if(it != parameterFunctions.end()){
			std::string value = argument.substr(delimiterIndex + 1, argument.size());
			it->second(value);
		}else{
			std::cerr << "[RK::CPM::interpret()] No Interpreter function for \"" << parameter <<  "\" in \"" << argument << "\" found." << std::endl;
			return false;
		}
	}else{
		std::cerr << "[RK::CPM::interpret()] Argument \"" << argument << "\" is invalid. Should have a delimiter as specified by user" << std::endl;
		return false;
	}
}

unsigned int RK::CPM::interpret(int argumentCount, char* arguments[], std::string delimiter){
	unsigned int failed = 0;
	for(int i = 0; i < argumentCount; i++){
		if(!interpret(arguments[i], delimiter)) failed++;
	}
	return failed;
}