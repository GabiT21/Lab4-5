#include "Gym.h"
#include "Tests.h"
#include "ServiceTests.h"
#include "Service.h"
#include "RepositoryArray.h"
#include <iostream>



void menu()
{
   cout<< " Selectati optiunea: "<< endl;
   cout<< "1. Adaugare exercitiu "<< endl;
   cout<< "2. Afisare exercitii "<< endl;
   cout<< "3. Modificare exercitiu "<< endl;
   cout<< "4. Numar de exercitii "<< endl;
   cout<< "5. Stergere exercitiu "<< endl;
   cout<< "6.  Exit : "<<endl;
}

void printMenu()
{
   char name[25];
   int noOfReps {}, noOfSeries {};
   float weightKg {};
   int ok = 1;
   RepositoryArray repo;
   GymExercise e1("tricep", 10, 3, 10);
   GymExercise e2("extension", 9, 3, 3);
   repo.addElem(e1);
   repo.addElem(e2);
   while(ok == 1)
   {
      menu();
      int optiune;
      cin >> optiune;
      if(optiune == 1)
      {
         cout << "Introduceti name: ";
         cin >> name;
         cout << "Introduceti noOfSeries: ";
         cin >> noOfSeries;
         cout << "Introduceti noOfReps: ";
         cin >> noOfReps;
         cout << "Introduceti weightKg: ";
         cin >> weightKg;

         GymExercise e(name, noOfSeries, noOfReps, weightKg);
         repo.addElem(e);
         cout << endl;
         cout << "Exercitiu adaugat cu succes "<<'\n';
         cout << endl;
      }
      
      else if (optiune == 2)
		{
			for (int i = 0; i < repo.dim(); i++)
			{
            cout<< endl;
            cout << "Nume: ";
            cout << repo.getAll()[i].getName() << endl;
            cout << "NoOfReps: ";
            cout << repo.getAll()[i].getNoOfReps() << endl;
            cout << "NoOfSeries: ";
            cout << repo.getAll()[i].getNoOfSeries() << endl;
            cout << "WeightKg: ";
            cout << repo.getAll()[i].getWeightKg() << endl;
			}
			cout << endl;
         continue;

		}

      else if(optiune == 3)
      {
          char exercitiu[30];
          cout << "Ce exercitiu doriti sa modificati?\n";
          cin >> exercitiu;
          GymExercise temp = repo.findElemByName(exercitiu);
          if (temp.getName() != NULL)
          {
		      cout << "\n Introduceti numele: ";
		      cin >> name;
		      cout << " Introduceti nr.de serii: ";
		      cin >> noOfSeries;
		      cout << " Introduceti nr. de repetari:  ";		
		      cin >> noOfReps;
		      cout << " Introduceti greutatea: ";
		      cin >> weightKg;
		      cout << endl;
              repo.updateElem(repo.findElemByName(exercitiu), name, noOfSeries, noOfReps, weightKg);
          }
          else {
              cout<< endl;
              cout << "Elementul nu exista\n";
              cout << endl;
          }
	  }

      else if(optiune == 4)
      {
         cout << "Numarul de exercitii pana in prezent este:  " << repo.dim() << endl;
         cout << endl;
      }

      else if(optiune == 5)
      {
          char exercitiu[30];
          cout << "Ce exercitiu doriti sa stergeti?\n";
          cin >> exercitiu;
          GymExercise temp = repo.findElemByName(exercitiu);
          if (temp.getName() != NULL)
          {
              repo.delElem(temp);
          }
          else
          {
              cout << "Element inexistent!\n";
          }

      }
      

      else if(optiune == 6)
         ok = 0;
   }
}
int main()
{
   testConstructor();
   testSetGet();
   testRepo();
   //testAddDeleteElem();
   printMenu();

}