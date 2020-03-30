#pragma once
#include "Aplicatie.h"
#include <map>
#include <iostream>


class Repository{
private:
    Aplicatie elem[20];
    map<int,Aplicatie > el;
    int size;


public:
    Repository();
    void addElem(Aplicatie);
    Aplicatie* getAll();
};