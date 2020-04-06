#include "Service.h"

Service::Service(Repo& r) :repo(r)
{}

void Service::setRepo(const Repo& r)
{
	repo = r;
}

void Service::addAplicatie(const std::string& nume, int consum, const std::string& status)
{
    if(status != "ram" and status!= "swap")
		throw std::string("Invalid status!\n");
	
	if(nume.size() == 0)
		throw std::string("Invalid nume!\n");
	
	if(consum < 0)
		throw std::string("Invalid consum!\n");
	
	Aplicatie A(nume, consum, status);
	this->repo.addAplicatie(A);
}

void Service::updateAplicatie(int id, const std::string& nume, int consum, const std::string& status)
{
	if (status != "ram" and status != "swap")
		throw std::string("Invalid status!\n");

	if (nume.size() == 0)
		throw std::string("Invalid nume!\n");

	if (consum < 0)
		throw std::string("Invalid consum!\n");

	Aplicatie A(nume, consum, status);
	this->repo.updateAplicatie(A, id);
}

void Service::removeAplicatie(int pos)
{
    this->repo.removeAplicatie(pos);
}

const std::unordered_map<int, Aplicatie>& Service::getAll() const
{
    return this->repo.getAll();
}

int Service::dim() const
{
    return this->repo.dim();
}
// void Service::initService()
// {
// 	repo.loadFromFile("Aplicatie.txt");
// 	setRepo(repo);
// }

Service::~Service()
{

}