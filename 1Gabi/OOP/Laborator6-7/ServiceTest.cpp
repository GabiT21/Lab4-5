#include "ServiceTest.h"
#include "Service.h"
#include "Repo.h"
#include <assert.h>

void testService()
{
    AppRepo repo;
    Service serv(repo);
    assert(serv.dim() == 0);
    Aplicatie A1("ap1", 1000, "swap");
    Aplicatie A2("ap2", 100, "ram");
    std::string ap1 = "ap1";
    std::string ap2 = "ap2";
    std::string ap3 = "ap3";
    std::string ap4 = "ap4";
    std::string swap = "swap";
    std::string ram = "ram";
    int standard = 2000;
    serv.addAplicatie(ap1, 1000, swap);
    serv.addAplicatie(ap2, 100, ram);
    assert(serv.dim() == 2);
    
     serv.updateAplicatie(1,"ap1", 1000, "swap");
     assert(serv.getAll().at(1) == A1);

     serv.removeAplicatie(0);
     assert(serv.dim() == 1);
     try {
        repo.removeAplicatie(1337);
        assert(false);
    }
    catch (const std::string& err)
    {
        assert(err == "Inexisting element!\n");
    }
    serv.removeAplicatie(1);
    assert(serv.dim() == 0);

    Aplicatie A3("ap3", 1000, "ram");
    Aplicatie A4("ap4",500, "ram");
    serv.addAplicatie(ap3, 1000, ram);
    serv.addAplicatie(ap4, 500, ram);
    assert(serv.sumOfRam() == 1500);

    int sum = 0 ;
    sum = A3.getConsumKb() + A4.getConsumKb();
    assert(serv.sumOfRam() == sum);
    int suma = serv.sumOfRam();
    assert(suma == sum);


    std::string ap5 = "ap5";
    Aplicatie A5("ap5", 2001, "swap");
    try{
        serv.addAplicatie(ap5 ,2001, swap);
        assert(false);
    }
    catch(const std::string& err)
    {
        assert(err == "Consumul depaseste capacitatea!\n");
    }
    std::string ap6 = "ap6";
    Aplicatie A6("ap6", 1000, "ram");
    serv.addAplicatie(ap6,1000, ram);
    assert(A6.getStatus() == ram and A4.getStatus() == swap);
    serv.removeAplicatie(2);
    assert(A6.getStatus() == ram);
    assert(A6.getStatus() == A4.getStatus());

    std::cout<<"okk\n";
}