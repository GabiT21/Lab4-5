#pragma once
#include <iostream>

class Mancare
{
    private:
    std::string numeClient;
    std::string adresaClient;
    int pretTotal;
    std::string numeMagazin; 

    public:
    Mancare();
    Mancare(const std::string numeClient, const std::string adresaClient, int pretTotal, const std::string numeMagazin);
    Mancare(const Mancare&);
    ~Mancare();
    const std::string& getNumeClient() const;
    int getPretTotal() const;
    const std::string& getAdresaClient() const ;
    const std::string& getNumeMagazin() const ;
    void setNumeClient(const std::string&);
    void setAdresaClient(const std::string&);
    void setPretTotal(int);
    void setNumeMagazin(const std::string&);
    Mancare& operator=(const Mancare&);
    bool operator==(const Mancare&) const;
    friend std::ostream& operator<<(std::ostream& os, const Mancare& m);   
};