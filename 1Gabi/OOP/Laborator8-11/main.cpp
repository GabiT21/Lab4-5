#include <iostream>
#include "TestRepo.h"
#include "Tests.h"
#include "Service.h"
#include "Repo.h"
#include "RepoFile.h"
#include "Validator.h"
#include "UI.h"
#include "User.h"
#include "Comanda.h"

int main()
{
    tests();
    repoTest();
    
    // Repo<Comanda> RC();
    // Repo<User> RU();

    // Service S(RC, RU);

    // UI ui(S);
    // ui.run();


}


//Clasa Serie e o clasa abstracta, nu se poate instantia.
//Da in acelasi repository se pot afla si Telefoane si Drone.
//
//Clasele Repo cu template nu au voie sa aiba import la clasele din model(Serie, Telefon, Drona) ca ar fi inutil sa fie generice in cazul ala.
//
//O solutie ar fi sa creezi o clasa Serializer<T> cu implementare class SerializerSerie : public Serializer<Serie> pe care sa il pasezi prin constructor la RepoCSV<T> si RepoHtml<T>(Serializer<T> ca si camp).Acel serializator va sti sa transforme stringul in ce obiect e nevoie si inapoi in String pentru scriere.Va fi folosit la citire si scriere din fisier.In acest fel, singura clasa care va trebui modificata cand apar noi tipuri de Serie(gen Tableta), va fi serializerul, toate restul nu se modifica.
//
//In programul principal vei declara Repo<Serie> si il instantiezi cu RepoCSV<Serie> sau RepoHtml<Serie> in functie de tipul de fisier ales.Pe parcursul rularii programului lucram doar cu fisierul de tipul ales, nu le combinam.
//
//Diagrama o poti face cu StarUML, nu sunt sigur exact ce genereaza VisualStudio, dar daca zici ca nu are toate elementele, nu e ce se cere.
//
//Apropo, nu a spus nimeni ca in fisier nu puteti salva si numele clasei printre parametrii din linie.