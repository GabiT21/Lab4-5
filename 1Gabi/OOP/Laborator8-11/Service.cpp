#include "Service.h"
#include "User.h"

Service::~Service()
{}

Service::Service(const Repo<Comanda>& repoC, const Repo<User>& repoU) 
{
    repo = repoC;
    repoUser = repoU;
}

bool Service::login(std::string user, std::string pass)
{
    this->loggedInUser.setUserName(user);
    this->loggedInUser.setPassword(pass);
    return ! this->loggedInUser.getUserName().empty();
}

bool Service::loggedIn()
{
    return ! this->loggedInUser.getUserName().empty();
}

void Service::logout()
{
    this->loggedInUser.setUserName("");
    this->loggedInUser.setPassword("");
}

int Service::dim()
{
    return repo.dim();
}

std::unordered_map<int, Comanda> Service::getAll()
{	
    return repo.getAll();
}

void Service::addElem(Comanda& com)
{
    repo.addAplicatie(com);
}

void Service::delElem(int pos)
{
    repo.removeAplicatie(pos);
}

void Service::updateElem(Comanda& com, int pos)
{
    repo.updateAplicatie(com,pos);
}




