#include "ServiceTest.h"
#include "Service.h"
#include "Repo.h"
#include <assert.h>

void testService()
{
    Repo repo;
    Service serv(repo);
    assert(serv.dim() == 0);
    Aplicatie A1("ap1", 1000, "swap");
    Aplicatie A2("ap2", 100, "ram");
    serv.addAplicatie("ap1", 1000, "swap");
    serv.addAplicatie("ap2", 100, "ram");
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
    std::cout<<"okk\n";
}