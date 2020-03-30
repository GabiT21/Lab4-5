#pragma once
#include <iostream>

using namespace std;

class Aplicatie
{
private:
    char* nume;
    int consumKb;
    char* status;

public:
    Aplicatie();
    Aplicatie(const char*, int,const char*);
    Aplicatie(const Aplicatie&);
    ~Aplicatie();
    char* getNume();
    int getConsumKb();
    char* getStatus();
    void setNume(char*);
    void setConsumKb(int);
    void setStatus(char*);
    Aplicatie& operator=(const Aplicatie&);
    bool operator==(const Aplicatie&);
    public:
};
