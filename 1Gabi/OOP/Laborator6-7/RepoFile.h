#pragma once
#include "Aplicatie.h"
#include "Repo.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include "Repo.h"

class AppRepoFile : public AppRepo
{
private:
    const char* fis;

public:
    AppRepoFile();
    AppRepoFile(const char* fileName);
    void loadFromFile(const char* fileName);
    void saveToFile();
    void addAplicatie(const Aplicatie&);
    void updateAplicatie(Aplicatie&, int);
    void removeAplicatie(int);
    int dim();
    std::unordered_map<int, Aplicatie>& getAll();

};