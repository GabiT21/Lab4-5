#include "UI.h"
#include <iostream>



void UI::menu()
{
   cout<< " Selectati optiunea: "<< endl;
   cout<< "1. Adaugare exercitiu "<< endl;
   cout<< "2. Afisare exercitii "<< endl;
   cout<< "3. Modificare exercitiu "<< endl;
   cout<< "4. Numar de exercitii "<< endl;
   cout<< "5. Stergere exercitiu "<< endl;
   cout<< "6. Exercitii cu nos*nor*wg > x"<< endl;
   cout<< "7. Stergere exercitiu cu wg * nor < 5"<< endl;
   cout<< "8.  Exit : "<<endl;
}

void UI::printMenu()
{
   char name[25];
   int noOfReps {}, noOfSeries {};
   float weightKg {};
   int ok = 1;
   int j = 0;
   int x;
   Service serv;
   //RepositoryArray repo;
   GymExercise e1("tricep", 10, 3, 10);
   GymExercise e2("extension", 9, 3, 3);
   serv.addElemServ(e1);
   serv.addElemServ(e2);

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
         serv.addElemServ(e);
         cout << endl;
         cout << "Exercitiu adaugat cu succes "<<'\n';
         cout << endl;
      }
      
      else if (optiune == 2)
		{
			for (int i = 0; i < serv.dimServ(); i++)
			{
            cout<< endl;
            cout << "Nume: ";
            cout << serv.getAllServ()[i].getName() << endl;
            cout << "NoOfReps: ";
            cout << serv.getAllServ()[i].getNoOfReps() << endl;
            cout << "NoOfSeries: ";
            cout << serv.getAllServ()[i].getNoOfSeries() << endl;
            cout << "WeightKg: ";
            cout << serv.getAllServ()[i].getWeightKg() << endl;
			}
			cout << endl;
         continue;

		}

      else if(optiune == 3)
      {
          char exercitiu[30];
          cout << "Ce exercitiu doriti sa modificati?\n";
          cin >> exercitiu;
          GymExercise temp = serv.findElemByNameServ(exercitiu);
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
              serv.updateElemServ(temp, name, noOfSeries, noOfReps, weightKg);
              //repo.updateElem(repo.findElemByName(exercitiu), name, noOfSeries, noOfReps, weightKg);
          }
          else {
              cout<< endl;
              cout << "Elementul nu exista\n";
              cout << endl;
          }
	  }

      else if(optiune == 4)
      {
         cout << "Numarul de exercitii pana in prezent este:  " << serv.dimServ() << endl;
         cout << endl;
      }

      else if(optiune == 5)
      {
          char exercitiu[30];
          cout << "Ce exercitiu doriti sa stergeti?\n";
          cin >> exercitiu;
          GymExercise temp = serv.findElemByNameServ(exercitiu);
          if (temp.getName() != NULL)
          {
              serv.delElemServ(temp);
          }
          else
          {
              cout << "Element inexistent!\n";
          }
      }

      else if(optiune == 6)
      {
          GymExercise found[25];
          cout << "x = ";
          cin >> x;
          serv.produsPesteX(found,x, j);
          for(int i = 0 ; i <j; i ++)
            {
                cout <<" Introduceti nume: " << found[i].getName() << endl;
                cout <<" Introduceti numar de serii: " << found[i].getNoOfSeries() << endl;
                cout <<" Introduceti numar de repetari: "<< found[i].getNoOfReps() << endl;
                cout <<" Introduceti greutate " << found[i].getWeightKg() << endl;
                cout << endl;
            }
      }

      else if(optiune == 7)
        {
            GymExercise found[25];
            serv.stergereSub5();
        }
      

      else if(optiune == 8)
         ok = 0;
   }
}


