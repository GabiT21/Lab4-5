#pragma once
#include "Service.h"

class UI {
private:
    Service service;

public:
    UI(Service&);
    void menu1();
    int login();
    void logout();
    void menu2();
    void add();
    void showAll();
    void run();
    ~UI();
};