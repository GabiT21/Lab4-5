#include "Tests.h"
#include "Gym.h"
#include <assert.h>
#include "RepositoryArray.h"
#include <iostream>
#include <string.h>

void testConstructor()
{ 
    GymExercise* e1 = new GymExercise("tricep extension", 10, 3, 10.0f); //constructorul implicit
    assert(e1->getNoOfReps() == 3 and e1->getNoOfSeries() == 10);

   
    GymExercise* e2;
    e2 = new GymExercise;
    assert(e2->getName() == NULL and e2->getWeightKg() == 0);

    
    //destructor
    if(e1 != NULL)
      delete e1, e1 = NULL;

    if(e2 != NULL)
      delete e2, e2 = NULL;

    /*
    STATIC
    GymExercise e1;
    assert(e1.getName() == NULL and e1-> getWeightKg() == -1);

    GymExercise e2("tricep extension", 10, 3 ,10);
    assert(e2.getNoOfReps() == 10 and e2.getNoOfSeries() == 3);
    */
    
}

void testSetGet()
{
      /*
      STATIC
      GymExercise e;
      e.setName("tricep extension");
      e.setNoOfReps(10);
      e.setNoOfSeries(3);
      e.setWeightKg(10);
      assert(e.getName() == "tricep extesion" and e.getNoOfReps() == 10 and e.getNoOfSeries() == 3 and e.getWeightKg() == 10);
      */

     GymExercise* e = new GymExercise();
     e->setName((char*)"tricep extension");
     e->setNoOfReps(10);
     e->setNoOfSeries(3);
     e->setWeightKg(10.0f);
     assert(strcmp(e->getName(), "tricep extension") == 0);
     assert(e->getNoOfReps() == 10);
     assert(e->getNoOfSeries() == 3);
     assert(e->getWeightKg() == 10.0f);
     if (e != NULL)
      delete e, e = NULL;
}

void testRepo()
{
      GymExercise e1("tricep extension", 10, 3, 10);
      GymExercise e2("tricep kickback", 9, 3, 3);
      RepositoryArray repo;
      assert(repo.dim() == 0);
      repo.addElem(e1);
      repo.addElem(e2);
      assert(repo.getAll()[repo.dim()-1] == e2);
      assert(repo.getAll()[0] == e1);
      repo.delElem(e2);
      assert(repo.dim() == 1);
      assert(repo.getAll()[repo.dim()-1] == e1);

      GymExercise e3("tricep back", 10, 10, 5);
      repo.addElem(e3);
      assert(repo.dim() == 2);
      repo.updateElem(e3,(char*)"tricep extension", 10, 3, 10);
      assert(repo.getAll()[1] == e1);
      repo.updateElem(e1, (char*)"tricep back", 10, 10 ,5 );
      assert(repo.getAll()[0] == e3);
      cout<<"Passed";

 //UI -> Service -> Repo
  

}