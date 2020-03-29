#include <iostream>
#include "UI.h"
#include "Tests.h"
#include "ServiceTests.h"

using namespace std;

int main()
{
    UI run;
    testConstructor();
    testSetGet();
    testRepo();
    testAddDeleteElem();
    testUpdateElem();
    testProdusPesteX();
    testSub5();
    run.printMenu();
    
}