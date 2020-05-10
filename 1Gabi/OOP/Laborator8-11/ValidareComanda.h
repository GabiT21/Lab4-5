#pragma once
#include "Comanda.h"
#include <string>
#include <vector>

class ExceptieComanda
{
protected:
    std::vector<std::string> erori;

public:
    ExceptieComanda(std::vector<std::string> erori);
    std::vector<std::string> getErori();
};

class ValidareComanda
{
public:
    ValidareComanda() {}
    virtual void ValComanda(Comanda*&);
};