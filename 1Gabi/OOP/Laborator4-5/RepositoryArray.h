#pragma once
#include "Gym.h"

class RepositoryArray{
private:
    GymExercise elem[20];
    int size;

public:
    RepositoryArray();
    void addElem(GymExercise);
    int findElem(GymExercise);
    GymExercise findElemByName(char* name);
    GymExercise getItemFromPos(int);
    void delElem(GymExercise);
    void updateElem(GymExercise,char*, int, int, float);
    GymExercise* getAll();
    int getElem();
    int dim();
    ~RepositoryArray();

};
