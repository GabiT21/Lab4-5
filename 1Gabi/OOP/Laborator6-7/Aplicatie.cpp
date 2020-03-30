#include "Aplicatie.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <cstring>


using namespace std;

Aplicatie::Aplicatie()
{
    nume = NULL;
    consumKb = 0;
    status = 0;
}

Aplicatie::Aplicatie(const char* nume, int consumKb, const char* status) :consumKb(consumKb)
{
    this->nume = new char[strlen(nume) +1];
    strcpy(this->nume,nume);
    this->status = new char[strlen(status) +1];
    strcpy(this->status,status);
}

Aplicatie::Aplicatie(const Aplicatie& a)
{
    this->nume = new char[strlen(a.nume) +1];
    strcpy(this->nume,a.nume);
    this->consumKb = consumKb;
    this->status = new char[strlen(a.status) +1];
    strcpy(this->status,a.status);
}

Aplicatie::~Aplicatie()
{
    if(nume != NULL)
        delete[] nume;
    if(status != NULL)
        delete[] status;
    consumKb = -1;
}

char* Aplicatie::getNume()
{
    return this->nume;
}

int Aplicatie::getConsumKb()
{
    return this->consumKb;
}

char* Aplicatie::getStatus()
{
    return this->status;

}

void Aplicatie::setNume(char* n)
{
    if(nume != NULL)
        delete[] nume;
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);

}

void Aplicatie::setConsumKb(int consum)
{
    consumKb = consum;
}

void Aplicatie::setStatus(char* sts)
{
     if(status != NULL)
        delete[] status;
    status = new char[strlen(sts) + 1];
    strcpy(status, sts);
}

Aplicatie& Aplicatie::operator= (const Aplicatie& a)
{
    if(this == &a) return *this; // sa nu fie de ex e = e;
    if(nume) delete[] nume;
    nume = new char [strlen(a.nume) + 1];
    strcpy(nume, a.nume);
    consumKb = a.consumKb;
    if(status != NULL) delete[] status;
    status = new char [strlen(a.status) + 1];
    return *this;
}

bool Aplicatie::operator==(const Aplicatie& a)
{
    return(strcmp(nume,a.nume) == 0) and (consumKb == a.consumKb) and (strcmp(status, a.status) ==0);
}




