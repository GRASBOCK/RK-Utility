#include <iostream>
#include <exception>

#include "CPM.hh"

class CPM_exception : public std::exception
{
	std::string _msg;

	public: 
	CPM_exception(std::string message) : _msg(message){};

	virtual const char* what() const throw(){
		return _msg.c_str();
	}
};

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

void RK::CPM::interpret(char* arg, std::string delimiter){
	std::string argument = arg;
	size_t delimiterIndex = argument.find(delimiter);
	if(delimiterIndex != std::string::npos){
		std::string parameter = argument.substr(0, delimiterIndex);
		auto it = parameterFunctions.find(parameter);
		if(it != parameterFunctions.end()){
			std::string value = argument.substr(delimiterIndex + 1, argument.size());
			it->second(value);
		}else{
			throw CPM_exception("[RK::CPM::interpret()] No Interpreter function for \"" + parameter +  "\" in \"" + argument + "\" found.");
		}
	}else{
		throw CPM_exception("[RK::CPM::interpret()] Argument \"" + argument + "\" is invalid. Should have a delimiter as specified by user");
	}
}

void RK::CPM::interpret(int argumentCount, char* arguments[], std::string delimiter){
	for(int i = 0; i < argumentCount; i++){
		interpret(arguments[i], delimiter);
	}
}