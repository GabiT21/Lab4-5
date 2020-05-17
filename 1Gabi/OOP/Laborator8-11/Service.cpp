#include "Service.h"
#include "User.h"

Service::~Service()
{}

Service::Service(Repo<Comanda*> repoC)
{
    // repo = repoC;
    // repoUser = repoU;
    this->repo = repoC;
    //this->repoUser = repoU;

    // User u1("Ion", "111");
    // User u2("Vasile", "112");
    // repoUser->addAplicatie(u1);
    // repoUser->addAplicatie(u2);
}

bool Service::login(std::string user, std::string pass)
{
    User us(user,pass);
    return repoUser->find(us) != -1;
}

// void Service::logout(std::string user, std::string pass)
// {
//     User us(user,pass);
//     int pos = repo->find(us);
//     repoUser->removeAplicatie(pos);
// }

int Service::dim()
{
    return repo.dim();
}

std::unordered_map<int, Comanda*> Service::getAll()
{	
    return repo.getAll();
}

void Service::addElem(Comanda* com)
{
    repo.addAplicatie(com);
}

void Service::delElem(int pos)
{
    repo.removeAplicatie(pos);
}

Comanda* Service::getItemFromPos(int pos)
{
    return repo.getItemFromPos(pos);
}
void Service::updateElem(Comanda*& com, int pos)
{
    repo.updateAplicatie(com,pos);
}

std::unordered_map<int, Comanda*> Service::comandaDupaNumeClient(std::string nume)
{
    int k = 0;
    std::unordered_map<int, Comanda*> rez;
    std::unordered_map<int, Comanda*> elems = repo.getAll();
    for( auto i = elems.begin(); i != elems.end(); i++)
    {
        std::string user = i->second->getNumeClient();
        if(user == nume) //user.compare(nume) == 0
            rez.insert(std::pair<int, Comanda*>(k++, i->second));
    }
    return rez;
}


