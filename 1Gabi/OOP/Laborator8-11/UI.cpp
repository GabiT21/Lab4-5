#include "UI.h"
#include <string>


UI::UI(Service& serv) : service(serv)
{}

int UI::login()
{
    std::string user;
    std::string pass;

    std::cout<<" User: \n";
    std::cin >> user;
    std::cout<<" Pass: \n";
    std::cin>> pass;
    return service.login(user, pass);
}

// void UI::logout()
// {
//     service.logout(user.getUserName(), user.getPassword());
//     std::cout<<"Logout ok!\n";
// }

void UI::add()
{
    std::string numeClient, adresaClient, lista, numeMagazin; 
    std::cout <<" Ce doriti sa adaugati?\n";
    std::cout <<" Mancare (0)\n";
    std::cout <<" Shopping (1)\n";
    int op;
    float pret;
    std::cout <<" Optiune: ";
    std::cin >> op;
    if( op == 0)
    {
        try {
            std::cout<< "Nume client: \n";
           // std::cin.ignore();
            getline(std::cin, numeClient);
            std::cout<<" Adresa client: \n";
            getline(std::cin, adresaClient);
            std::cout<<" Lista preparate: \n";
            getline(std::cin, lista);
            std::cout<<" Pret total: \n";
            std::cin >> pret;
            Mancare mancare(numeClient, adresaClient, lista, pret);
            Comanda* comanda = new Mancare(mancare);
            service.addElem(comanda);
            std::cout<< "Mancare adaugata cu succes! \n";

        }
        catch(...)
        {
            //exceptii
        }
    } 
    if( op == 1)
    {
        try {
            std::cout<< "Nume client: \n";
           // std::cin.ignore();
            getline(std::cin, numeClient);
            std::cout<<" Adresa client: \n";
            getline(std::cin, adresaClient);
            std::cout<<" Lista cumparaturi: \n";
            getline(std::cin, lista);
            std::cout<<" Pret total: \n";
            std::cin >> pret;
            std::cout<<" Nume magazin: \n";
            getline(std::cin, numeMagazin);
            Shopping shopping(numeClient, adresaClient, lista, pret, numeMagazin);
            Comanda* comanda = new Shopping(shopping);
            service.addElem(comanda);
            std::cout<< "Shopping adaugata cu succes! \n";
        }
        catch(...)
        {
            //exceptii
        }
    }
     
}

void UI::deletee()
{
    int pos;
    std::cout <<" Pozitia comenzii care doriti sa fie stearsa este: \n";
    std::cin >> pos;
    try
    {
        service.delElem(pos);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // std::cout << "Ce doriti sa stergeti? \n";
    // std::cout << "Mancare.\n";
    // std::cout << "Shopping.\n";

    // int op;
    // std::cout <<" Optiune: ";
    // std::cin >> op;
    // if( op == 1)
    // {
    //     Mancare mancare;
    //   //  std:: cin >> mancare;
    //     Comanda* comanda = new Mancare(mancare);
    //     service.delElem();

    // }


}


void UI::update()
{
    std::cout << "Ce doriti sa adaugati? \n";
    std::cout << "Mancare. (0)\n";
    std::cout << "Shopping. (1)\n";
    std::string numeClientNou, adresaClientNoua, listaNoua, numeMagazinNou;
    int op, pos;
    float pretNou;
    std::cout <<" Optiune: ";
    std::cin >> op;
    if( op == 0)
    {
        try
        {
            std::cout << "Pozitie: \n";
            std::cin >> pos;
            std::cin.ignore();
            std::cout<< " Nume client nou: \n";
            getline(std::cin, numeClientNou);
            std::cout << " Adresa client noua: \n";
            getline(std::cin, adresaClientNoua);
            std::cout << " Lista preparate noua: \n";
            getline(std::cin, listaNoua);
            std::cout << " Pret nou: \n";
            std::cin >> pretNou;
            Mancare mancare(numeClientNou, adresaClientNoua, listaNoua, pretNou);
            Comanda* comanda = new Mancare(mancare);
            service.updateElem(comanda, pos);  
            std::cout<< "Mancare modificata cu succes! \n";
        }      
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }

    if(op == 1)
    {
        try
        {
            std::cout << "Pozitie: \n";
            std::cin >> pos;
            std::cin.ignore();
            std::cout<< " Nume client nou: \n";
            getline(std::cin, numeClientNou);
            std::cout << " Adresa client noua: \n";
            getline(std::cin, adresaClientNoua);
            std::cout << " Lista shopping noua: \n";
            getline(std::cin, listaNoua);
            std::cout << " Pret nou: \n";
            std::cin >> pretNou;
            std::cout << " Nume magazin nou: \n";
            getline(std::cin,numeMagazinNou);
            Shopping shopping(numeClientNou, adresaClientNoua, listaNoua, pretNou, numeMagazinNou);
            Comanda* comanda = new Shopping(shopping);
            service.updateElem(comanda, pos);
            std::cout << " Shopping modificat cu succes! \n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

void UI::cautareDupaNume()
{
    std::string nume;
    std:: cout<<" Nume client: \n";
    std::cin >> nume;
    std::unordered_map<int, Comanda*> m = service.comandaDupaNumeClient(nume);
    std::unordered_map<int, Comanda*>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        std::cout<< it->first << ' ' << it->second->toString() <<std::endl;
}

void UI::getAll()
{
    auto storage = service.getAll();
    if (storage.empty())
    {
        std::cout << "The list is empty!\n";
        return;
    }
    for(const auto& it : storage)
    {
        std::cout<<" ID:";
        std::cout<< it.first<<'\n';
        std::cout<<it.second->toString()<<'\n';

    }
    std::cout<<"\n";
}



void UI::printMenu()
{
    bool ok = true;
   while(ok)
   {
    std::cout << "\n--- Selectati optiunea: ---" << '\n';
    std::cout<< "1. Adaugare  "         << '\n';
    std::cout<< "2. Afisare  "          << '\n';
    std::cout<< "3. Cautare dupa nume  "       << '\n';
    std::cout<< "4. Modificare  "       << '\n';
    std::cout<< "5. Stergere  "         << '\n';
    std::cout<< "7.  Exit  "                     << '\n';

            int op;
            std::cin>> op;
            if( op == 1)
                {
                    add();
                    continue;
                }

            if( op == 2)
                {
                    getAll();
                    continue;
                }
            
            if( op == 3)
                {
                    cautareDupaNume();
                    continue;
                }   
            
            if( op == 4)
                {
                    update();
                    continue;
                }
            
            if( op == 5)
                {
                    deletee();
                    continue;
                }
            
            if( op == 7)
                {
                    ok = false;
                }
            
    }
}