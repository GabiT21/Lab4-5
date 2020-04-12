#include "Aplicatie.h"


Aplicatie::Aplicatie() : nume {NULL}, consumKb {0}, status {NULL}
{}

Aplicatie::Aplicatie(const std::string& nume, int consumKb, const std::string& status) {

    setNume(nume);
    setConsumKb(consumKb);
    setStatus(status);
}

Aplicatie::Aplicatie(const Aplicatie& a)
{
    this->nume = a.nume;
    this->consumKb = a.consumKb;
    this->status = a.status;
}

Aplicatie::~Aplicatie()
{}

const std::string& Aplicatie::getNume() const
{
    return nume;
}

int Aplicatie::getConsumKb() const
{
    return consumKb;
}

const std::string& Aplicatie::getStatus() const
{
    return status;
}

void Aplicatie::setNume(const std::string& nume)
{
    this->nume = nume;
}

void Aplicatie::setConsumKb(int c)
{   
    this->consumKb = c;
}

void Aplicatie::setStatus(const std::string& s)
{
    status = s;
}

Aplicatie& Aplicatie::operator=(const Aplicatie& other)
{
    if (*this == other)
        return *this;
    this->nume     = other.nume;
    this->consumKb = other.consumKb;
    this->status   = other.status;
}

bool Aplicatie::operator==(const Aplicatie& other) const
{
    return this->nume == other.nume && this->status == other.status && this->consumKb == other.consumKb;
}

std::ostream& operator<<(std::ostream& os, const Aplicatie& a)
{
    os << a.nume << " " << a.consumKb << " " << a.status;
    return os;
}
