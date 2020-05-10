#pragma once

#include <iostream>

template <class T>
class Serializer
{
public:
    Serializer() {};
    ~Serializer() {};
    virtual T fromString(std::string line, char delim) = 0;
};