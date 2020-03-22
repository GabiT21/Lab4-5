#pragma once
#include <ostream>
using namespace std;

class GymExercise{
private:
    char* name;
    int noOfSeries, noOfReps;
    float weightKg;
public:
    GymExercise();
    GymExercise(const char*, int , int, float );
    GymExercise(const GymExercise&);
    ~GymExercise();
    char* getName();
    int getNoOfSeries();
    int getNoOfReps();
    float getWeightKg();
    void setName(char*);
    void setNoOfSeries(int);
    void setNoOfReps(int);
    void setWeightKg(float);
    GymExercise& operator=(const GymExercise&);
    bool operator==(const GymExercise&);
    friend ostream& operator<<(ostream& os, const GymExercise&);
};