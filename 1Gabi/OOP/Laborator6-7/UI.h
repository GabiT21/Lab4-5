#pragma once
#include "Repo.h"
#include "Aplicatie.h"
#include "Service.h"
#include <string>

class UI
{
private:
    Service& serv;

public:
    UI(Service& serv);
    void addAplicatie();
    void removeAplicatie();
    void updateAplicatie();
    void getAll();
    void run();
    void menu();
    ~UI();
};