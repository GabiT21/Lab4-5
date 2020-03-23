#include "Service.h"
#include "ServiceTests.h"
#include <assert.h>

void testAddElem()
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
}