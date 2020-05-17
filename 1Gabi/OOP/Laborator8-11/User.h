#pragma once
#include <string>

class User
{
private:
	std::string userName;
	std::string password;

public:
	User();
	User(std::string, std::string);
	~User();
	
	std::string getUserName();
	std::string getPassword();
	void setUserName(std::string);
	void setPassword(std::string);
	bool operator==(const User& u);
	std::string toString();
	std::string toStringDelimiter(char delimiter);
};
