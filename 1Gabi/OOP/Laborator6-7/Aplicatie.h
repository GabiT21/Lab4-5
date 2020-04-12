#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Aplicatie
{
private:
    std::string nume;
    int consumKb;
    std::string status;
    const int standardKb = 2000;

public:
    Aplicatie();
    Aplicatie(const std::string& nume, int consumKb, const std::string& status);
    Aplicatie(const Aplicatie&);
    ~Aplicatie();
    const std::string& getNume() const;
    int getConsumKb() const ;
    const std::string& getStatus() const ;
    void setNume(const std::string&);
    void setConsumKb(int);
    void setStatus(const std::string&);
    Aplicatie& operator=(const Aplicatie&);
    bool operator==(const Aplicatie&) const;
    friend std::ostream& operator<<(std::ostream& os, const Aplicatie& a);
};
