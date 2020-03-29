#include "Service.h"


Service::Service()
{
  this->repo;
}

Service::Service(RepositoryArray repoServ)
{
    repoServ = repo;
}

Service::Service(const Service& serv)
{
    repo = serv.repo;
}

Service::~Service()
{
}

void Service::addElemServ(GymExercise& e)
{

    repo.addElem(e);
}

void Service::delElemServ(GymExercise e)
{
    repo.delElem(e);
}

void Service::updateElemServ(GymExercise& e, char* name, int nos,int nor, float weightKg)
{
    repo.updateElem(e, name, nos, nor ,weightKg);
}

GymExercise Service::getItemFromPosServ(int pos)
{
    return repo.getItemFromPos(pos);
}

GymExercise Service::findElemByNameServ(char* name)
{
    return repo.findElemByName(name);
}

GymExercise* Service::getAllServ()
{
    return repo.getAll();
}

int Service::dimServ()
{
    return repo.dim();
}



void Service::produsPesteX(GymExercise found[], int x, int& j)
{
	j = 0;
    for(int i = 0 ; i < repo.dim(); i++)
    {
        GymExercise servPos = repo.getItemFromPos(i);
        if(servPos.getNoOfReps() * servPos.getNoOfSeries() * servPos.getWeightKg() > x)
            {
                found[j++] = servPos;
            }
    }
}

void Service::stergereSub5()
{
    for(int i = 0 ; i < repo.dim(); i++)
    {
        GymExercise servPos = repo.getItemFromPos(i);
        if(servPos.getWeightKg() * servPos.getNoOfReps() < 5)
        {
            repo.delElem(repo.getItemFromPos(i));
            i--;
        }
    }
}   



