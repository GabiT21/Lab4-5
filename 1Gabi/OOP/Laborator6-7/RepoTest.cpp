#include "Aplicatie.h"
#include "Repo.h"
#include "Service.h"
#include "RepoTest.h"
#include <assert.h>


void testAdd()
{
    Repo repo;
    assert(repo.dim() == 0);
    Aplicatie A("ap1", 1000, "swap");
    repo.addAplicatie(A);
    assert(repo.dim() == 1);
    try {
        repo.addAplicatie(A);
        assert(false);
    }
    catch (const std::string& err)
    {
        assert(err == "Existing element!\n");
    }
    assert(repo.dim() == 1);
    Aplicatie A2("ap2", 100, "ram");
    repo.addAplicatie(A2);
    assert(repo.dim() == 2);
    std::cout<<"ok\n";
}

void testUpdate()
{
    Repo repo;
    assert(repo.dim() == 0);
    Aplicatie A1("ap1", 1000, "swap");
    Aplicatie A2("ap2", 100, "ram");
    repo.addAplicatie(A1);
    repo.addAplicatie(A2);
    
    const std::unordered_map<int, Aplicatie> elems = repo.getAll();
    assert(elems.at(0) == A1);
    assert(elems.at(1) == A2);

    Aplicatie A3("ap3", 1336, "ram");
    repo.updateAplicatie(A3, 0);
    assert(repo.getAll().at(0) == A3);

    try {
        repo.updateAplicatie(A1, 3);
        assert(false);
    }
    catch (const std::string & err)
    {
        assert(err == "Inexisting element!\n");
    }
    
}

void testDelete()
{
    Repo repo;
    assert(repo.dim() == 0);
    Aplicatie A1("ap1", 1000, "swap");
    Aplicatie A2("ap2", 100, "ram");
    repo.addAplicatie(A1);
    repo.addAplicatie(A2);
    assert(repo.dim() == 2);
    repo.removeAplicatie(0);
    assert(repo.dim() == 1);
    repo.removeAplicatie(1);
    assert(repo.dim() == 0);
    std::cout<<"ok2\n";

    try {
        repo.removeAplicatie(1337);
        assert(false);
    }
    catch (const std::string& err)
    {
        assert(err == "Inexisting element!\n");
    }

}


void testsRepo()
{
    testAdd();
    testDelete();
    testUpdate();
}