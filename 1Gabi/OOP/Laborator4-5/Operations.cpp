#include "Operations.h"


void produsPesteX(RepositoryArray &repo, GymExercise found[],int x, int &j)
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

void stergereSub5(RepositoryArray& repo)
{
    for(int i = 0 ; i < repo.dim(); i++)
    {
        GymExercise repoPos = repo.getItemFromPos(i);
        if(repoPos.getWeightKg() * repoPos.getNoOfReps() < 5)
        {
            repo.delElem(repo.getItemFromPos(i));
            i--;
        }
    }   
}



/*
void repoSTLDeleteProjectsWithZeroBranchesOrCommits(RepositorySTL& projects)
{
	for (int i = 0; i < projects.dim(); i++)
	{
		Project crrProject = projects.getItemFromPos(i);
		if (crrProject.getNoOfBranches() == 0 or crrProject.getTotalNoOfCommits() == 0)
		{
			projects.delElem(projects.getItemFromPos(i));
			i--;
		}
	}
}

void repoArrayFindProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray &projects, \
	int k, int l, Project found[], int& m)
{
	m = 0;
	for (int i = 0; i < projects.dim(); i++)
	{
		Project crrProject = projects.getItemFromPos(i);
		if (crrProject.getNoOfBranches() >= k and crrProject.getTotalNoOfCommits() >= l)
		{
			found[m]=crrProject;
			m++;
		}
	}
}
*/