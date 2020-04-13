#include "Shopping.h"

Shopping::Shopping() : numeClient{NULL}, adresaClient{NULL}, listaCumparaturi{NULL}, pretTotal{0}, numeMagazin{NULL}
{}

Shopping::Shopping(const std::string numeClient, const std::string adresaClient, const std::string listaCumparaturi,int pretTotal, const std::string numeMagazin)
: numeClient{numeClient}, adresaClient{adresaClient}, listaCumparaturi{listaCumparaturi},pretTotal{pretTotal}, numeMagazin{numeMagazin}
{}

Shopping::Shopping(const Shopping& m)
{
    this->numeClient = m.numeClient;
    this->adresaClient = m.adresaClient;
    this->listaCumparaturi = m.listaCumparaturi;
    this->pretTotal = m.pretTotal;
    this->numeMagazin = m.numeMagazin;
}

Shopping::~Shopping()
{}

const std::string& Shopping::getNumeClient() const
{
    return numeClient;
}

const std::string& Shopping::getAdresaClient() const
{
    return adresaClient;
}

const std::string& Shopping::getListaCumparaturi() const
{
    return listaCumparaturi;
}

int Shopping::getPretTotal() const
{
    return pretTotal;
}

const std::string& Shopping::getNumeMagazin() const
{
    return numeMagazin;
}

void Shopping::setNumeClient(const std::string& nClient)
{
    numeClient = nClient;
}

void Shopping::setAdresaClient(const std::string& adresaC)
{
    adresaClient = adresaC;
}

void Shopping::setListaCumparaturi(const std::string& lista)
{
    listaCumparaturi = lista;
}

void Shopping::setPretTotal(const int p)
{
    pretTotal = p;
}

void Shopping::setNumeMagazin(const std::string& numeMag)
{
    numeMagazin = numeMag;
}


Shopping& Shopping::operator=(const Shopping& other)
{
    if (*this == other)
        return *this;
    this->numeClient       = other.numeClient;
    this->adresaClient     = other.adresaClient;
    this->listaCumparaturi = other.listaCumparaturi;
    this->pretTotal        = other.pretTotal;
    this->numeMagazin      = other.numeMagazin;
}

bool Shopping::operator==(const Shopping& other) const
{
    return this->numeClient   == other.numeClient and this->adresaClient == other.adresaClient and this->listaCumparaturi == other.listaCumparaturi and this->pretTotal    == other.pretTotal and this->numeMagazin  == other.numeMagazin;
}

std::ostream& operator<<(std::ostream& os, const Shopping& a)
{
    os << a.numeClient << " " << a.adresaClient << " " <<a.listaCumparaturi<<" "<< a.pretTotal<<" "<<a.numeMagazin;
    return os;
}
