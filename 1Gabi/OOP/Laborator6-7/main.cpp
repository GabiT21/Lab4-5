#include <iostream>
#include "Aplicatie.h"
#include "Repo.h"
#include "RepoFile.h"
#include "Service.h"
#include "UI.h"
#include "RepoTest.h"
#include "Tests.h"
#include "ServiceTest.h"



int main()
{
    testsRepo();
    tests();
    testService();
    std::cout<<"\n";

    AppRepoFile repo("Aplicatie.txt");

    Service serv(repo);
    serv.setRepo(repo);

    UI consola(serv);
    consola.run();

} 