#include "User.h"



User::User()
{
}

User::User(std::string u,std::string p):userName(u),password(p)
{
}

std::string User::getUserName()
{
	return userName;
}

std::string User::getPassword()
{
	return password;
}

void User::setUserName(std::string u)
{
	userName = u;
}

void User::setPassword(std::string p)
{
	password=p;
}

bool User::operator==(const User & u)
{
	return (userName==u.userName) and (password==u.password);
}

std::string User::toString()
{
	return userName + " " + password;
}

std::string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + password;
}


User::~User()
{
}
