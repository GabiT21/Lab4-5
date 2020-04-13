#pragma once
#include "Mancare.h"
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
    void addAplicatie(const Mancare&);
    void updateAplicatie(Mancare&, int);
    void removeAplicatie(int);
    int dim();
    std::unordered_map<int, Mancare>& getAll();

};