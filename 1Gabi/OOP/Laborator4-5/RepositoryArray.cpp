#include "RepositoryArray.h"

#include <string.h>

RepositoryArray::RepositoryArray()
{
    size = 0;
}

void RepositoryArray::addElem(GymExercise s)
{
    elem[size++] = s;
}

int RepositoryArray::findElem(GymExercise e)
{
     int i = 0;
     while( i < size)
     {
         if(elem[i] == e)
            return i;
         i++;
     }
     return -1;
}
GymExercise RepositoryArray::findElemByName(char* name)
{
    int i = 0;
    while (i < size)
    {
        if (strcmp(elem[i].getName(), name) == 0)
            return elem[i];
        i++;
    }
    return GymExercise();
}


 void RepositoryArray::delElem(GymExercise e)
 {
     int i = findElem(e);
     if( i != -1)
     {  
         elem[i] = elem[size - 1];
         size --;
     }
 }

void RepositoryArray::updateElem(GymExercise e,char* n, int nos, int nor, float wk)
{
    int i = findElem(e);
    if (i != -1)
    {
        elem[i].setName(n);
        elem[i].setNoOfReps(nor);
        elem[i].setNoOfSeries(nos);
        elem[i].setWeightKg(wk);
    }
}

GymExercise* RepositoryArray::getAll()
{
    return elem;
}

int RepositoryArray::dim()
{
    return size;
}

RepositoryArray::~RepositoryArray()
{
    // este gol deoarece in constuctor nu am deschis baze de date, alocare dinamica, fisiere
    // nu facem actiuni, dar ea trebuie definita
}

GymExercise RepositoryArray::getItemFromPos(int i)
{
    return elem[i];
}



  
