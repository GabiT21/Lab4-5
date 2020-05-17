#pragma once
#include "Service.h"

class UI {
private:
    Service service;
    User user;

public:
    UI(Service&);
    ~UI();

    int login();
    void logout();
    void add();
    void deletee();
    void update();
    void getAll();
    void cautareDupaNume();
    void printMenu();
};