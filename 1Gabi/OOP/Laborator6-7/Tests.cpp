#include "Tests.h"
#include "Aplicatie.h"
#include <iostream>
#include <assert.h>
#include <string>


void testConstructor()
{

    Aplicatie a2("a2",10,"swap");
    std::string nume = "a2";
    std::string getNume = a2.getNume();
    std::string getStatus = a2.getStatus();
    std::string status = "swap";
    int consum = 10;
    int getConsum = a2.getConsumKb();
    assert(getNume == nume and getStatus == status and getConsum == consum);
    
    //if(a1 != NULL)
     //   delete a1, a1 = NULL;
    std::cout<<"Teste constr\n";
}


void testSetGet()
{
    Aplicatie a;
    a.setNume((std::string)"ap1");
    a.setConsumKb(10);
    a.setStatus((std::string)"ram");
    std::string nume = "ap1";
    assert(nume == a.getNume());
    assert(a.getConsumKb() == 10);
    std::string status = "ram";
    assert(status == a.getStatus());
    status = "swap";
    assert(status != a.getStatus());
    std::cout<<"Tsetget\n";

    a = a;
    status = "ram";
    assert(nume == a.getNume());
    assert(a.getConsumKb() == 10);
    assert(status == a.getStatus());

}

void tests()
{
    testConstructor();
    testSetGet();
}