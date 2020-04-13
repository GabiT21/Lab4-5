#include "Tests.h"
#include "Mancare.h"
#include <iostream>
#include <assert.h>
#include <string>


void testConstructor()
{

    Mancare a2("m2","str1",50, "Mega");
    std::string numeClient = "a2";
    std::string getNume = a2.getNumeClient();
    std::string adresaClient = "str1";
    std::string getAdresaClient = a2.getAdresaClient();
    std::string getNumeMagazin = a2.getNumeMagazin();
    std::string numeMagazin = "Mega";
    int pretTotal = 50;
    int getPret = a2.getPretTotal();
    assert(getNume == numeClient and getAdresaClient == adresaClient and getPret == pretTotal and getNumeMagazin == numeMagazin);
    
    //if(a1 != NULL)
     //   delete a1, a1 = NULL;
    std::cout<<"Teste constr\n";
}


void testSetGet()
{
    Mancare a;
    a.setNumeClient((std::string)"ap1");
    a.setAdresaClient((std::string)"str1");
    a.setPretTotal(30);
    a.setNumeMagazin((std::string)"Mega");
    std::string nume = "ap1";
    int pretTotal = 30;
    assert(nume == a.getNumeClient());
    assert(a.getPretTotal() == pretTotal);
    std::string numeMagazin = "Mega";
    assert(numeMagazin == a.getNumeMagazin());
    numeMagazin = "Kauf";
    assert(numeMagazin != a.getNumeMagazin());
    std::cout<<"Tsetget\n";


    a = a;
    assert(nume == a.getNumeClient());
    assert(a.getPretTotal() == 30);
    assert(numeMagazin == a.getNumeMagazin());

}

void tests()
{
    testConstructor();
    testSetGet();
}