#include <iostream>
#include "Aplicatie.h"
#include "Repo.h"
#include "Service.h"
#include "UI.h"
#include "RepoTest.h"
#include "Tests.h"
#include "ServiceTest.h"

void initService(Service& serv) {
	Repo repo;
	repo.loadFromFile("Aplicatie.txt");
	serv.setRepo(repo);
}

int main()
{
    testsRepo();
    tests();
    testService();
    std::cout<<"\n";
    Repo repo;
    Service serv(repo);
    initService(serv);
    UI consola(serv);
    consola.run();

}