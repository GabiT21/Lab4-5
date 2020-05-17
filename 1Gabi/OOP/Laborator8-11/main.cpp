#include <iostream>
#include "Repo.h"
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileHTML.h"
#include "Service.h"
#include "TestRepo.h"
#include "Tests.h"
#include "SerializerComanda.h"
#include "UI.h"

int main()
{
    int op;
    tests();
    repoTest();
    std::cout<< "Teste trecute cu succes! \n";  

    std::cout << "Fisierul ales( CSV(0) / HTML(1) )\n";
    std::cin >> op;
    if( op == 0)
    {
        SerializerComanda* sc = new SerializerComanda;
        RepoFileCSV <Comanda*> repoC("Comanda.csv", sc);
        Service service(repoC);
        UI ui(service);
        ui.printMenu();
    }

    if( op == 1)
    {
        SerializerComanda* sc = new SerializerComanda;
        RepoFileCSV <Comanda*> repoH("Comanda.html", sc);
        Service service(repoH);
        UI ui(service);
        ui.printMenu();
    }

}
