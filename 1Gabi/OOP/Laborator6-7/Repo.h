#pragma once
#include "Aplicatie.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Repo
{
private:
    std::unordered_map < int, Aplicatie> elems;
	int base_id;
    const char* fis;

public:
    Repo();
    Repo(const char* fileName);
    void loadFromFile(const char* fileName);
    void addAplicatie(const Aplicatie&);
    void updateAplicatie(Aplicatie&, int);
    void removeAplicatie(int);
    int dim() const;
    const std::unordered_map<int, Aplicatie>& getAll() const;
    void saveToFile();
   // void capacitate(Aplicatie[], int, int&);
    //void clearFile();
    ~Repo();

};