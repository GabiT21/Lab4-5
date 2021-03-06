#include "Mancare.h"
#include "Utils.h"

Mancare::Mancare() :Comanda()
{}

Mancare::Mancare(const std::string numeClient, const std::string adresaClient, const std::string listaPreparate, float pretTotal) : Comanda(numeClient, adresaClient, pretTotal)
{
    // listaPreparate = listaPreparate;
    // pretTotal = pretTotal;
    //setListaPreparate(listaPreparate);
    this->listaPreparate = listaPreparate;
}

Mancare::Mancare(const Mancare&m) : Comanda(m)
{
    listaPreparate = m.listaPreparate;
}

Mancare::~Mancare()
{}


Mancare::Mancare(std::string linie, char delim)
{
    std::vector<std::string> tokens = splitLine(linie, delim);
    numeClient = tokens[0];
    adresaClient = tokens[1];
    listaPreparate = tokens[2];
    pretTotal = stof(tokens[3]);
}

void Mancare::setListaPreparate(const std::string lp)
{
    listaPreparate =lp;
}

const std::string Mancare::getListaPreparate()
{
    return listaPreparate;
}

Mancare& Mancare::operator=(const Mancare& other)
{
    if(*this == other)
        return *this;

    Comanda::operator=(other);

    listaPreparate = other.listaPreparate;
    return *this;
}

bool Mancare::operator==(const Mancare& other) const
{
    return Comanda::operator==(other) and this->listaPreparate == other.listaPreparate;
}


std::string Mancare::toString()
{
    std::string str1, str2;
    str1 = numeClient;
    str2 = adresaClient;
    return str1 + " " + str2 + " " + std::to_string(pretTotal);
}

std::string Mancare::toStringWithDelimiter(char delimiter)
{
    std::string str1, str2, str3;
    str1 = numeClient;
    str2 = adresaClient;
    str3 = listaPreparate;
    return str1 + delimiter + str2 + delimiter + str3 + delimiter + std::to_string(pretTotal);
}


std::ostream& operator<<(std::ostream& os, Mancare& a)
{
     os << a.getNumeClient() << " " << a.getAdresaClient() << " " << a.getPretTotal() <<" " << a.getListaPreparate()<< "\n";
    return os;
}



