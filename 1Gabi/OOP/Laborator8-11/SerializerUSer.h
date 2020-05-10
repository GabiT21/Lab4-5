#pragma once
#include <sstream>
#include <vector>
#include "User.h"
#include "Serializer.h"
#include "Shopping.h"
#include "Mancare.h"

class SerializerUser : public Serializer<User*>
{
public:
    SerializerUser() {}
    ~SerializerUser() {}
    inline User* fromString(std::string, char);
};

User* SerializerUser::fromString(std::string line, char delim)
{
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string item;
    while(getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    User* user = new User(line, delim);
    return user;
}

