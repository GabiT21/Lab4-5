#include "Service.h"


Service::Service(){
    this->repo;
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

GymExercise* Service::getAllServ()
{
    return repo.getAll();
}

int Service::dimServ()
{
    return repo.dim();
}



// void Service::produsPesteX(Service &repo, GymExercise found[],int x, int &j)
// {
// 	j = 0;
//     for(int i = 0 ; i < repo.dim(); i++)
//     {
//         GymExercise repoPos = repo.getItemFromPos(i);
//         if(repoPos.getNoOfReps() * repoPos.getNoOfSeries() * repoPos.getWeightKg() > x)
//             {
//                 found[j++] = repoPos;
//             }
//     }
// }

// void Service::stergereSub5(RepositoryArray& repo)
// {
//     for(int i = 0 ; i < repo.dim(); i++)
//     {
//         GymExercise repoPos = repo.getItemFromPos(i);
//         if(repoPos.getWeightKg() * repoPos.getNoOfReps() < 5)
//         {
//             repo.delElem(repo.getItemFromPos(i));
//             i--;
//         }
//     }   



