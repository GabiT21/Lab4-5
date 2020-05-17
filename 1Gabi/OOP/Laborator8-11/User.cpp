#include "User.h"



User::User()
{}

User::User(std::string us,std::string pass):userName(us),password(pass)
{}

User::~User()
{}

std::string User::getUserName()
{
	return userName;
}

std::string User::getPassword()
{
	return password;
}

void User::setUserName(std::string us)
{
	userName = us;
}

void User::setPassword(std::string pass)
{
	password = pass;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

std::string User::toString()
{
	return userName + " " + password;
}

std::string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + password;
}


