#include "ValidareComanda.h"

ExceptieComanda::ExceptieComanda(std::vector<std::string> e) : erori(e)
{}

std::vector<std::string> ExceptieComanda:: getErori()
{
    return erori;
}

void ValidareComanda::ValComanda(Comanda *& comanda)
{
    std::vector<std::string> erori;
    if (comanda->getNumeClient().size() > 1)
        erori.push_back("Numarul de caractere ");
}

