#pragma once
#include <iostream>
#include <string>
#include <vector>

class Comanda{
protected:
    std::string numeClient;
    std::string adresaClient;
    float pretTotal;

public:
    Comanda();
    Comanda(const std::string& , const std::string& , float);
    Comanda(const Comanda&);
    Comanda(std::string, char);
    ~Comanda();

    void setNumeClient(const std::string&);
    void setAdresaClient(const std::string&);
    void setPretTotal(float);
    
    const std::string& getNumeClient() const;
    const std::string& getAdresaClient() const;
    float getPretTotal();

    Comanda& operator=(const Comanda&);
    bool operator==(const Comanda& other) const;
    friend std::ostream& operator<<(std::ostream&, Comanda);

    virtual std::string toString();
    virtual std::string toStringWithDelimiter(char);
};
