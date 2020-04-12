#include "Repo.h"
#include <string.h>
#include "RepoFile.h"

bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

AppRepoFile::AppRepoFile()
	:fis(nullptr)
{
}

AppRepoFile::AppRepoFile(const char* fileName)
	: fis(fileName)
{}

void AppRepoFile::loadFromFile(const char * fileName)
{
	elems.clear();
	base_id = 0;

	fis = fileName;
	std::ifstream f(fis);

	if (is_empty(f))
	{
		f.close();
		return;
	}

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


void AppRepoFile::saveToFile()
{
	std::ofstream f(fis);
	for(const auto& it : elems )
 	{
		f << it.second<<"\n";
	}
	f.close();
}

void AppRepoFile::addAplicatie(const Aplicatie& T)
{
	this->loadFromFile(fis);
	AppRepo::addAplicatie(T);
	this->saveToFile();
}

void AppRepoFile::updateAplicatie(Aplicatie& T, int pos)
{
	this->loadFromFile(fis);
	AppRepo::updateAplicatie(T, pos);
	this->saveToFile();
}

void AppRepoFile::removeAplicatie(int pos)
{
	this->loadFromFile(fis);
	AppRepo::removeAplicatie(pos);
	this->saveToFile();
}

int AppRepoFile::dim()
{
	this->loadFromFile(fis);
	return AppRepo::dim();

}

std::unordered_map<int, Aplicatie>& AppRepoFile::getAll()
{
	this->loadFromFile(fis);
	return AppRepo::getAll();
}


