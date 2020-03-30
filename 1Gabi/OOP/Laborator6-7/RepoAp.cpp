#include "RepoAp.h"
#include <string.h>

Repository::Repository()
{
    size = 0;
}

void Repository::addElem(Aplicatie a)
{
    elem[size++] = a;
}

Aplicatie* Repository::getAll()
{
    return elem;
}