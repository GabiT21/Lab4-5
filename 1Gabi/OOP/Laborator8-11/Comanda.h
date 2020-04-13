#pragma once
#include <iostream>

class Mancare
{
    private:
    std::string numeClient;
    std::string adresaClient;
    int pretTotal;

    public:
    Mancare();
    Mancare(const std::string numeClient, const std::string adresaClient, int pretTotal);
    Mancare(const Mancare&);
    ~Mancare();
    const std::string& getNumeClient() const;
    int getPretTotal() const;
    const std::string& getAdresaClient() const ;
    void setNumeClient(const std::string&);
    void setAdresaClient(const std::string&);
    void setPretTotal(int);;
    Mancare& operator=(const Mancare&);
    bool operator==(const Mancare&) const;
    friend std::ostream& operator<<(std::ostream& os, const Mancare& m);   
};