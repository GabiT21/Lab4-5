#include "Tests.h"
#include "assert.h"
#include "SerializerComanda.h"

void testMancare()
{

    Mancare m2("Vasile", "Lalelor,nr 15","lapte, oua", 25);
    Mancare m3(m2);

    m2 = m3;
    assert(m2 == m3);
    std::string nume = "Vasile";
    std::string getNume = m2.getNumeClient();
    std::string getAdresa = m2.getAdresaClient();
    std::string adresa = "Lalelor,nr 15";
    assert(nume == getNume);
    assert(getAdresa == adresa);
    std::cout<<"1\n";
}

void testComanda()
{
    Comanda c2("Popescu", "Lalelelor,nr 15",15);
    std::string numeC = "Popescu";
    std::string adresaC = "Lalelelor,nr 15";
    std::string getNumeC = c2.getNumeClient();
    std::string getAdresaC = c2.getAdresaClient();
    assert(numeC == getNumeC);
    assert(adresaC == getAdresaC);

    Comanda c1;
    c1.setNumeClient((std::string)"Ion");
    c1.setAdresaClient((std::string)"la");
    c1.setPretTotal(50);
    std::string numeC1 = "Ion";
    std::string adresaC1 = "la";
    assert(numeC1 == c1.getNumeClient());
    assert(adresaC1 == c1.getAdresaClient());
    std::cout<<"2\n";
}

void CSV()
{
    // const char* fname = "Comanda.csv";
    // SerializerComanda* s = new SerializerComanda();
}

void tests()
{
    testMancare();
    testComanda();
}