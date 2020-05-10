#pragma once
#include <sstream>
#include <string>
#include "Comanda.h"
#include "Shopping.h"
#include "Mancare.h"
#include "Serializer.h"
#include <vector>


class SerializerComanda: public Serializer<Comanda*>
{
public:
    SerializerComanda() {};
    ~SerializerComanda () {};
    inline Comanda* fromString(std::string ,char) override;
};

Comanda* SerializerComanda::fromString(std::string line, char delim) override
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
        try
        {
            int i = std::stoi(tokens[3]);
            Comanda* c = new Mancare(line, delim);
            return c;
        }
        catch(...)
        {
            Comanda* c =  new Shopping(line, delim);
            return c;
        }
        
    }

}
