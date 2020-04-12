#pragma once
#include "Aplicatie.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>

template <typename T>
class Repo
{
protected:
    std::unordered_map < int, T> elems;
	int base_id;

public:
    Repo() : base_id(0) {};
	virtual void addAplicatie(const T&);
	virtual void updateAplicatie(T&, int);
	virtual void removeAplicatie(int);
	virtual int dim() const;
	virtual std::unordered_map<int, T>& getAll();
    
    ~Repo();

};


template <typename T>
void Repo<T>::addAplicatie(const T& a)
{
	for (auto& it : elems)
	{
		if (it.second == a)
		{
			throw std::string("Existing element!\n");
		}
	}
	elems.insert({ base_id++, a });
}

template <typename T>
void Repo<T>::updateAplicatie(T& a, int pos)
{
	//elems[pos]==a;
	/*this->removeAplicatie(pos);
	this->addAplicatie(a);*/
	auto it = elems.find(pos);
	if (it == elems.end())
		throw std::string("Inexisting element!\n");
	it->second = a;

}

template <typename T>
void Repo<T>::removeAplicatie(int pos)
{
	auto it = elems.find(pos);
	if (it == elems.end())
		throw std::string("Inexisting element!\n");
	elems.erase(pos);

}

template <typename T>
std::unordered_map<int, T>& Repo<T>::getAll()
{
	return this->elems;
}

template <typename T>
int Repo<T>::dim() const
{
	return this->elems.size();
}

template <typename T>
Repo<T>::~Repo()
{
	base_id = 0;
}


class AppRepo : public Repo<Aplicatie>
{};


