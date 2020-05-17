#include "Shopping.h"
#include "Comanda.h"
#include "Utils.h"

Shopping::Shopping() : Comanda()
{}

Shopping::Shopping(const std::string numeClient, const std::string adresaClient, const std::string listaCumparaturi, float pretTotal, const std::string numeMagazin) : Comanda(numeClient, adresaClient, pretTotal)
{
    this->listaCumparaturi = listaCumparaturi;
    this->numeMagazin = numeMagazin;
    // setListaCumparaturi(listaCumparaturi);
    // setNumeMagazin(numeMagazin);
}

Shopping::Shopping(const Shopping& s) : Comanda(s)
{
    listaCumparaturi = s.listaCumparaturi;
    numeMagazin = s.numeMagazin;
}

Shopping::Shopping(std::string linie, char delim)
{
    std::vector<std::string> tokens = splitLine(linie, delim);
    numeClient = tokens[0];
    adresaClient = tokens[1];
    listaCumparaturi = tokens[2];
    pretTotal = stof(tokens[3]);
    numeMagazin = tokens[4];
}

Shopping::~Shopping()
{}

void Shopping::setListaCumparaturi(const std::string lc)
{
    listaCumparaturi = lc;
}

const std::string Shopping::getListaCumparaturi()
{
    return listaCumparaturi;
}

void Shopping::setNumeMagazin(const std::string nm)
{
    numeMagazin = nm;
}

const std::string Shopping::getNumeMagazin()
{
    return numeMagazin;
}

Shopping& Shopping::operator=(const Shopping& other)
{
    if(*this == other)
        return *this;

    Comanda::operator=(other);
    listaCumparaturi = other.listaCumparaturi;
    numeMagazin = other.numeMagazin;
    
    return *this;
}

bool Shopping::operator==(const Shopping& other) const
{
    return Comanda::operator==(other) and this->listaCumparaturi == other.listaCumparaturi and this->numeMagazin == other.numeMagazin;
}

std::string Shopping::toStringWithDelimiter(char delim)
{
    return numeClient + delim + adresaClient + delim + listaCumparaturi + delim + std::to_string(pretTotal) + delim + numeMagazin;
}

std::ostream& operator<<(std::ostream& os, Shopping a)
{
    os <<a.getNumeClient() << a.getAdresaClient() << a.getListaCumparaturi() << a.getPretTotal() << a.getNumeMagazin() ;
    return os;
}
