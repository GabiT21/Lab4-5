#include "Mancare.h"

Mancare::Mancare() : numeClient{NULL}, adresaClient{NULL}, pretTotal{0}
{}

Mancare::Mancare(const std::string numeClient, const std::string adresaClient, int pretTotal, const std::string numeMagazin)
: numeClient{numeClient}, adresaClient{adresaClient}, pretTotal{pretTotal}, numeMagazin{numeMagazin}
{}

Mancare::Mancare(const Mancare& m)
{
    this->numeClient = m.numeClient;
    this->adresaClient = m.adresaClient;
    this->pretTotal = m.pretTotal;
    this->numeMagazin = m.numeMagazin;
}

Mancare::~Mancare()
{}

const std::string& Mancare::getNumeClient() const
{
    return numeClient;
}

const std::string& Mancare::getAdresaClient() const
{
    return adresaClient;
}

int Mancare::getPretTotal() const
{
    return pretTotal;
}

const std::string& Mancare::getNumeMagazin() const
{
    return numeMagazin;
}

void Mancare::setNumeClient(const std::string& nClient)
{
    numeClient = nClient;
}

void Mancare::setAdresaClient(const std::string& adresaC)
{
    adresaClient = adresaC;
}

void Mancare::setPretTotal(const int p)
{
    pretTotal = p;
}

void Mancare::setNumeMagazin(const std::string& numeMag)
{
    numeMagazin = numeMag;
}


Mancare& Mancare::operator=(const Mancare& other)
{
    if (*this == other)
        return *this;
    this->numeClient   = other.numeClient;
    this->adresaClient = other.adresaClient;
    this->pretTotal    = other.pretTotal;
    this->numeMagazin  = other.numeMagazin;
}

bool Mancare::operator==(const Mancare& other) const
{
    return this->numeClient   == other.numeClient and this->adresaClient == other.adresaClient and this->pretTotal    == other.pretTotal and this->numeMagazin  == other.numeMagazin;
}

std::ostream& operator<<(std::ostream& os, const Mancare& a)
{
    os << a.numeClient << " " << a.adresaClient << " " << a.pretTotal<<" "<<a.numeMagazin;
    return os;
}
