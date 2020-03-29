#include "Operations.h"

void produsPesteX(RepositoryArray& repo, GymExercise found[], int x, int&j)
{
    j = 0;
    for(int i = 0 ; i < repo.dim(); i++)
    {
        GymExercise repoPos = repo.getItemFromPos(i);
        if(repoPos.getNoOfReps() * repoPos.getNoOfSeries() * repoPos.getWeightKg() > x)
            {
                found[j++] = repoPos;
            }
    }
}
void stergereSub5(RepositoryArray&);