#include <iostream>
#include "TestRepo.h"
#include "Tests.h"
#include "Service.h"
#include "Repo.h"
#include "RepoFile.h"
#include "Validator.h"
#include "UI.h"
#include "User.h"
#include "Comanda.h"

int main()
{
    tests();
    repoTest();
    
    // Repo<Comanda> RC();
    // Repo<User> RU();

    // Service S(RC, RU);

    // UI ui(S);
    // ui.run();

}
