#include "Comanda.h"

Comanda::Comanda() : numeClient(""), adresaClient(""), pretTotal(0.0f)
{}

Comanda::Comanda(const std::string& numeClient, const std::string& adresaClient, float pretTotal) : numeClient(numeClient), adresaClient(adresaClient), pretTotal(pretTotal)
{}

Comanda::Comanda(const Comanda& c) : numeClient(c.numeClient), adresaClient(c.adresaClient),  pretTotal(c.pretTotal)
{}

// Comanda::Comanda(std:: string line, char delim)
// {
//     std::vector <std::string> token = splitLine(line, delim);
//     numeClient = token[0];
//     adresaClient = token[1];
//     pretTotal = stof(token[2]);
// }

Comanda::~Comanda()
{} 

const std::string& Comanda::getNumeClient() const
{
    return numeClient;
}

const std::string& Comanda::getAdresaClient() const
{
    return adresaClient;
}

float Comanda::getPretTotal()
{
    return pretTotal;
}

void Comanda::setNumeClient(const std::string& numeC)
{
    numeClient = numeC;
}

void Comanda::setAdresaClient(const std::string& adresaC)
{
    adresaClient = adresaC;
}

void Comanda::setPretTotal(float pt)
{
    pretTotal = pt;
}


Comanda& Comanda::operator=(const Comanda& other)
{
    // if(*this == other)
    //     return *this;
    numeClient   = other.numeClient;
    adresaClient = other.adresaClient;
    pretTotal    = other.pretTotal;
    return *this;

}

bool Comanda::operator==(const Comanda& other) const
{
    return this->numeClient == other.numeClient and this->adresaClient == other.adresaClient and this->pretTotal == other.pretTotal;
}


std::ostream& operator<<(std::ostream& os, Comanda a)
{
    os << a.getNumeClient() << " " << a.getAdresaClient() << " " << a.getPretTotal() <<"\n";
    return os;
}


std::string Comanda::toString()
{
    std::string str1, str2;
    str1 = numeClient;
    str2 = adresaClient;
    return str1 + " " + str2 + " " + std::to_string(pretTotal);
}

std::string Comanda::toStringWithDelimiter(char delimiter)
{
    std::string str1, str2;
    str1 = numeClient;
    str2 = adresaClient;
    return str1 + delimiter + str2 + delimiter + std::to_string(pretTotal);

}
