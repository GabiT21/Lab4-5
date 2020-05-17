#pragma once
#include <sstream>
#include <string>
#include "Comanda.h"
#include "Shopping.h"
#include "Mancare.h"
#include "Serializer.h"
#include "Utils.h"
#include <vector>


class SerializerComanda: public Serializer<Comanda*>
{
public:
    SerializerComanda() {};
    ~SerializerComanda () {};
    Comanda* fromString(std::string ,char) override;
};

Comanda* SerializerComanda::fromString(std::string line, char delim)
{
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string item;
    while(std::getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    if(tokens.size() == 4)
    {
        Comanda* mancare = new Mancare(line, delim);
        return mancare;   
    }
    else
        if(tokens.size() == 5)
        {
            Comanda* shopping = new Shopping(line, delim);
            return shopping;
        }

}



