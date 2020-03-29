#include "Service.h"
#include "ServiceTests.h"
#include <assert.h>
#include <iostream>

void testAddDeleteElem()
{
      GymExercise e1("tricep extension", 10, 3, 10);
      GymExercise e2("tricep kickback", 9, 3, 3);
      Service serv;
      assert(serv.dimServ() ==0);
      serv.addElemServ(e1);
      serv.addElemServ(e2);
      assert(serv.getAllServ()[serv.dimServ()-1] == e2);
      assert(serv.getAllServ()[0] == e1);
      serv.delElemServ(e2);
      assert(serv.dimServ() == 1);
      assert(serv.getAllServ()[serv.dimServ()-1] == e1);
      std::cout<<"PassedAD\n";
}

void testUpdateElem()
{
      GymExercise e1("tricep extension", 10, 3, 10);
      GymExercise e2("tricep kickback", 9, 3, 3);
      Service serv;
      serv.addElemServ(e1);
      serv.addElemServ(e2);
      assert(serv.dimServ() == 2);
      serv.updateElemServ(e1,(char*)"tricep kickback", 9, 3, 3); 
      assert(serv.getAllServ()[0] == e2);
      std::cout<<"PassedU\n";
}


void testProdusPesteX()
{
      int j = 0;
      GymExercise found[25];
      GymExercise e1("tricep extension", 5, 1, 5);
      GymExercise e2("tricep kickback", 9, 3, 3);
      GymExercise e3("tricep ", 1, 2, 10);
      Service serv;
      serv.addElemServ(e1);
      serv.addElemServ(e2);
      serv.produsPesteX(found, 26,j);
      assert(found[0] == e2 and j == 1);
      std::cout <<"PassedX\n";
      

}

void testSub5()
{
      Service serv;
      GymExercise e1("tricep extension", 5, 10, 5);
      GymExercise e2("tricep kickback", 9, 3, 3);
      GymExercise e3("tricep ",1, 1, 4);
      serv.addElemServ(e1);
      serv.addElemServ(e2);
      serv.addElemServ(e3);
      assert(serv.dimServ() == 3);
      serv.stergereSub5();
      assert(serv.dimServ() == 2);
      assert(serv.getAllServ()[0] == e1 and serv.getAllServ()[1] == e2);
}