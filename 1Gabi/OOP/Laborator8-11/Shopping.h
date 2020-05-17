#pragma once
#include "Comanda.h"

class Shopping : public Comanda
{
private:
    std::string listaCumparaturi;
    std::string numeMagazin;

public:
    Shopping();
    Shopping(const std::string, const std::string, const std::string, float, const std::string);
    Shopping(const Shopping&);
    Shopping(std::string, char);
    ~Shopping();

    const std::string getListaCumparaturi();
    const std::string getNumeMagazin();

    void setListaCumparaturi(const std::string);
    void setNumeMagazin(const std::string);

    Shopping& operator=(const Shopping&);
    bool operator==(const Shopping&) const;
    
    std::string toStringWithDelimiter(char);

    friend std::ostream& operator<<(std::ostream&, Shopping&);
};