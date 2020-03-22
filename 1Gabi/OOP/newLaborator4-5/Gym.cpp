#include "Gym.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <cstring>


using namespace std;

GymExercise::GymExercise()
{
    name = NULL;
    noOfSeries = 0;
    noOfReps = 0;
    weightKg = 0;
}

GymExercise::GymExercise(const char* name, int noOfSeries, int noOfReps,float weightKg)
    :noOfSeries(noOfSeries), noOfReps(noOfReps),weightKg(weightKg)
{
    this->name = new char[strlen(name) +1];
    strcpy(this->name,name);
    //strcpy_s(this->name, sizeof name, name);
  /*this->noOfReps = noOfReps;
    this->noOfSeries = noOfSeries;
    this->weightKg = weightKg;*/
}

GymExercise::GymExercise(const GymExercise &e)
{
    this->name = new char[strlen(e.name) +1];
    strcpy(this->name,e.name);
    //strcpy_s(this->name, sizeof name, name);
    this->noOfReps = e.noOfReps;
    this->noOfSeries = e.noOfSeries;
    this->weightKg = e.weightKg;
}

GymExercise::~GymExercise()
{
    if(name != NULL) 
        delete[] name;
    name = NULL;
    noOfReps = -1;
    noOfSeries = -1;
    weightKg = -1;

}

char* GymExercise::getName()
{
    return this->name;
}

int GymExercise::getNoOfReps()
{
    return this->noOfReps;
}

int GymExercise::getNoOfSeries()
{
    return this->noOfSeries;
}

float GymExercise::getWeightKg()
{
    return this->weightKg;
}

void GymExercise::setName(char* n)
{
    if(name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name,n);
    //strcpy_s(this->name, strlen(name) +1, name);
}

void GymExercise::setNoOfReps(int nor){
    //this->noOfReps = nor;
    noOfReps = nor;
}

void GymExercise::setNoOfSeries(int nos)
{
    //this->noOfSeries = nos;
    noOfSeries = nos;
}

void GymExercise::setWeightKg(float wk)
{
    weightKg = wk;
}

GymExercise& GymExercise::operator= (const GymExercise& e)
{
    if(this == &e) return *this; // sa nu fie de ex e = e;
    if(name) delete[] name;
    name = new char [strlen(e.name) + 1];
    strcpy(name, e.name);
    noOfReps = e.noOfReps;
    noOfSeries = e.noOfSeries;
    weightKg = e.weightKg;
    return *this;
}

bool GymExercise::operator==(const GymExercise& e)
{
    return(strcmp(name,e.name) == 0 ) and (noOfReps == e.noOfReps) and (noOfSeries == e.noOfSeries) and (weightKg == e.weightKg);
}

ostream& operator<<(ostream& os, const GymExercise& e)
{
    os<<e.name<<" "<<e.noOfReps<<" "<<e.noOfSeries<<" "<<e.weightKg;
    return os;
}


