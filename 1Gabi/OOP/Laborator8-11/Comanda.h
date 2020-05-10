#pragma once
#include <iostream>
#include <string>

class Comanda{
protected:
    std::string numeClient;
    std::string adresaClient;
    float pretTotal;

public:
    Comanda();
    Comanda(const std::string& numeClient, const std::string& adresaClient, float);
    Comanda(const Comanda&);
    ~Comanda();

    void setNumeClient(const std::string&);
    const std::string& getNumeClient() const;
    void setAdresaClient(const std::string&);
    const std::string& getAdresaClient() const;
    float getPretTotal();
    void setPretTotal(float);

    Comanda& operator=(const Comanda&);
    bool operator==(const Comanda& other) const;
    friend std::ostream& operator<<(std::ostream&, Comanda);

    virtual std::string toString();
    virtual std::string toStringWithDelimiter(char);
};
