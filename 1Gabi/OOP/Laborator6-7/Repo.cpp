#include "Repo.h"
#include <string.h>

Repo::Repo()
	: base_id(0), fis(NULL)
{}




Repo::Repo(const char* fileName)
{
	base_id = 0;
	fis = fileName;
	std::ifstream f(fis);

	std::string nume;
    int consumKb;
    std::string status;

	while (!f.eof()) {
		f >> nume >> consumKb >> status;
		if (!nume.empty()) {
			Aplicatie A(nume, consumKb, status);
			elems.insert({base_id, A});
		}
	}
	f.close();
}

void Repo::loadFromFile(const char * fileName)
{
	elems.clear();
	base_id = 0;

	fis = fileName;
	std::ifstream f(fis);

	std::string nume;
    int consumKb;
    std::string status;

	while (!f.eof()) {
		f >> nume >> consumKb >> status;
		if(!nume.empty()){
			Aplicatie A(nume, consumKb, status);
			elems.insert({base_id++, A});
		}
	}
	
	f.close();
}


void Repo::addAplicatie(const Aplicatie& a)
{
	for( auto& it : elems )
	{
		if( it.second == a)
		{
			throw std::string("Existing element!\n");
		}
	}
    elems.insert({base_id++, a});
	saveToFile();
}

void Repo::updateAplicatie(Aplicatie& a, int pos)
{
	//elems[pos]==a;
    /*this->removeAplicatie(pos);
	this->addAplicatie(a);*/
	auto it = elems.find(pos);
	if (it == elems.end())
		throw std::string("Inexisting element!\n");
	it->second = a;
	saveToFile();
}

void Repo::removeAplicatie(int pos)
{
	auto it = elems.find(pos);
	if( it == elems.end() )
		throw std::string("Inexisting element!\n");
    elems.erase(pos);
	saveToFile();
}

const std::unordered_map<int, Aplicatie>& Repo::getAll() const
{
    return this->elems;
}
int Repo::dim() const
{
    return this->elems.size();
}

void Repo::saveToFile()
{
	std::ofstream f(fis);
	for(const auto& it : elems )
 	{
		f << it.second<<"\n";
	}
	f.close();
}



Repo::~Repo()
{
    base_id = 0;
}


