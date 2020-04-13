#pragma once
#include <iostream>

class Shopping
{
    private:
    std::string numeClient;
    std::string adresaClient;
    std::string listaCumparaturi;
    int pretTotal;
    std::string numeMagazin;

    public:
    Shopping();
    Shopping(const std::string numeClient, const std::string adresaClient,const std::string listaCumparaturi, int pretTotal, const std::string numeMagazin);
    Shopping(const Shopping&);
    ~Shopping();
    const std::string& getNumeClient() const;
    int getPretTotal() const;
    const std::string& getAdresaClient() const ;
    const std::string& getNumeMagazin() const ;
    const std::string& getListaCumparaturi() const;
    void setNumeClient(const std::string&);
    void setAdresaClient(const std::string&);
    void setListaCumparaturi(const std::string&);
    void setPretTotal(int);
    void setNumeMagazin(const std::string&);
    Shopping& operator=(const Shopping&);
    bool operator==(const Shopping&) const;
    friend std::ostream& operator<<(std::ostream& os, const Shopping& m);   
};