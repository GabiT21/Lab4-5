#pragma once
#include "User.h"
#include "Repo.h"
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileHTML.h"
#include "Mancare.h"
#include "Shopping.h"


class Service
{
private:
    Repo<Comanda*> repo;
    Repo<User>* repoUser;

public:
    Service();
    Service(Repo<Comanda*>);
    bool login(std::string ,std::string);
   // bool loggedIn();
    void logout(std::string,std::string);
    void addElem(Comanda*);
    void delElem(int);
    void updateElem(Comanda*&, int);
    Comanda* getItemFromPos(int);
    int dim();
    std::unordered_map<int, Comanda*> comandaDupaNumeClient(std::string);
    std::unordered_map<int,Comanda*> getAll();
    ~Service();
};