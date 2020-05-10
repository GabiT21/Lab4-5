#include <assert.h>
#include <iostream>
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Repo.h"
#include "RepoFile.h"


void repoTest()
{
    Repo<Comanda*> repo;
    Comanda* comanda1 = new Mancare("Ion", "Victoriei,nr 15", 15,"apa banane");
    repo.addAplicatie(comanda1);
    try {
        repo.addAplicatie(comanda1);
        assert(false);
    }
    catch (const std::string& err)
    {
        assert(err == "Existing element!\n");
    }
    assert(repo.dim() == 1);

    Comanda* comanda2 = new Mancare("Vasile", "Victoriei,nr 15", 5,"lapte");
    repo.addAplicatie(comanda2);
    try {
        repo.addAplicatie(comanda2);
        assert(false);
    }
    catch (const std::string& err)
    {
        assert(err == "Existing element!\n");
    }
    assert(repo.dim() == 2);

    const std::unordered_map<int, Comanda*> elems = repo.getAll();

    Comanda* comanda3 = new Mancare("Dorin", "Abator,nr 9", 5,"lapte oua");
    repo.updateAplicatie(comanda3, 0);
  //  assert(repo.getAll.at(0) == comanda3);
    
    std::cout<<"Minune\n";
    
}