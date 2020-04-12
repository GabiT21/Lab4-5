#include "Service.h"

Service::Service(AppRepo& r) :repo(r)
{}

void Service::setRepo(const AppRepo& r)
{
	repo = r;
}

void Service::addAplicatie(std::string& nume, int consum, std::string& status)
{		
	if(nume.size() == 0)
		throw std::string("Invalid nume!\n");
	
	if(consum < 0)
		throw std::string("Invalid consum!\n");

	if(consum > standardKb)
		throw std::string("Consumul depaseste capacitatea!\n");

	if(sumOfRam() + consum < this->standardKb){
		status = std::string("ram");
	}else{
		status = std::string("ram");
		changeRamToSwap(consum);
	}

	// if(status != "ram" and status!= "swap")
	// 	throw std::string("Invalid status!\n");
	
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

	std::string status = this->repo.getAll().find(pos)->second.getStatus();

	if(status == "ram"){
		int consumNou = this->repo.getAll().find(pos)->second.getConsumKb();
		changeSwapToRam(consumNou);
	}

    this->repo.removeAplicatie(pos);
}

const std::unordered_map<int, Aplicatie>& Service::getAll() const
{	
    return this->repo.getAll();
}

int Service::sumOfRam()
{	
	int sum = 0;
	for( auto& it : this->repo.getAll())
		if(it.second.getStatus() == "ram")
			sum += it.second.getConsumKb();

	return sum;
}

void Service::changeRamToSwap(int consumNou)
{
	int sum = 0;
	for( auto& it : this->repo.getAll())
		if(it.second.getStatus() == "ram")
			if(consumNou > this->standardKb - sumOfRam()){
				it.second.setStatus("swap");
			}
}

void Service::changeSwapToRam(int consumNou)
{
	int sum = 0;
	for( auto& it : this->repo.getAll())
		if(it.second.getStatus() == "swap")
			if(consumNou > this->standardKb - sumOfRam()){
				it.second.setStatus("ram");
			}
}

int Service::dim() const
{
	return repo.dim();
}
Service::~Service()
{

}