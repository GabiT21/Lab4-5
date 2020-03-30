#include "TestsAp.h"
#include "Aplicatie.h"
#include <assert.h>
#include <cstring>


void testConstructor()
{
    Aplicatie a1;
    assert(a1.getNume() == NULL and a1.getConsumKb() == 0 and a1.getStatus() == NULL);
    cout<<"T1\n";

    char z1[10] = "swap";
    char z[5] = "a2";
    Aplicatie a2(z,10,z1);
    assert(a2.getConsumKb() == 10 and strstr(a2.getNume(), "a2"));
    cout<<"T2\n";
}

void testSetGet()
{
    Aplicatie* a = new Aplicatie();
    a->setNume((char*)"ap1");
    a->setConsumKb(10);
    a->setStatus((char*)"RAM");
    assert(strcmp(a->getNume(), "ap1") == 0);
    assert(a->getConsumKb() == 10);
    assert(strcmp(a->getStatus(), "RAM") == 0);
    if (a != NULL)
        delete a, a = NULL;

}