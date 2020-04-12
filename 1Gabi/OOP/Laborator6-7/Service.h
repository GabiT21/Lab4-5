#pragma once
#include "Aplicatie.h"
#include "RepoFile.h"

class Service
{
private:
    AppRepo& repo;
    const int standardKb = 2000;

public:
    Service(AppRepo& r);
    Service(const Service&) = delete;
    ~Service();
    void setRepo(const AppRepo&);
    void addAplicatie(std::string& nume, int consum, std::string& status);
    int dim() const;
    void updateAplicatie(int id, const std::string& nume, int consum, const std::string& status);
    void removeAplicatie(int);
    int sumOfRam();
    void changeRamToSwap(int);
    void changeSwapToRam(int);
    const std::unordered_map<int,Aplicatie>& getAll() const;
};