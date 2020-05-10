#pragma once
#include "User.h"
#include "Repo.h"
#include "RepoFile.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Comanda.h"


class Service
{
private:
    Repo<Comanda> repo;
    Repo<User> repoUser;
    User loggedInUser;

public:

    Service(const Repo<Comanda>&, const Repo<User>&);
    bool login(std::string ,std::string);
    bool loggedIn();
    void logout();
    void addElem(Comanda&);
    void delElem(int);
    void updateElem(Comanda&, int);
    int dim();
    std::unordered_map<int,Comanda> getAll();
    ~Service();
};