#pragma once
#include "Comanda.h"

class Mancare : public Comanda
{
private:
    std::string listaPreparate;

public:
    Mancare();
    Mancare(const std::string ,const std::string ,float, const std::string);
    Mancare(const Mancare&);
    Mancare(std::string, char);
    ~Mancare();
    const std::string getListaPreparate();
    void setListaPreparate(const std::string);

    Mancare& operator=(const Mancare&);
    bool operator==(const Mancare& other) const;
    friend std::istream& operator >>(std::istream&, Mancare&);
    friend std::ostream& operator <<(std::ostream&, Mancare);

    std::string toString();
    std::string toStringWithDelimiter(char);
    
};
