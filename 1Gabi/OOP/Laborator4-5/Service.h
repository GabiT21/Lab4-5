#pragma once
#include "RepositoryArray.h"
#include "Gym.h"

class Service {
private:
    RepositoryArray repo;
    
public:
    Service();
    Service(RepositoryArray);
    Service(const Service&);
    ~Service();
    void addElemServ(GymExercise&);
    GymExercise* getAllServ();
    void delElemServ(GymExercise);
    void updateElemServ(GymExercise& e, char*, int, int, float);
    int dimServ();
    GymExercise getItemFromPosServ(int);
    GymExercise findElemByNameServ(char* name);
    void produsPesteX(GymExercise [],int , int&);
    void stergereSub5();
    //void stergereSub5(Service& , int&);
};


