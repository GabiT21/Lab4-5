#pragma once
#include "Aplicatie.h"
#include "Repo.h"

class Service
{
private:
    Repo& repo;

public:
    Service(Repo& r);
    Service(const Service&) = delete;
    ~Service();
    void setRepo(const Repo&);
    void addAplicatie(const std::string& nume, int consum, const std::string& status);
    int dim() const;
    void updateAplicatie(int id, const std::string& nume, int consum, const std::string& status);
    void removeAplicatie(int);
    const std::unordered_map<int,Aplicatie>& getAll() const;
};