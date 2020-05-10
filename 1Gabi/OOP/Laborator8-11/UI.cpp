#include "UI.h"
#include <string>


UI::UI(Service& serv) : service(serv)
{}

void UI::menu1()
{
    std::cout << "1. Login\n";
    std::cout << "2. Operate\n";
    std::cout << "3. Logout\n";
}
void UI::menu2()
{
   std::cout << "\n--- Selectati optiunea: ---" << '\n';
   std::cout<< "1. Adaugare  "         << '\n';
   std::cout<< "2. Afisare  "          << '\n';
   std::cout<< "3. Modificare  "       << '\n';
   std::cout<< "4. Stergere  "         << '\n';
   std::cout<< "6.  Exit  "                     << '\n';
}
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

void UI::add()
{
    std::cout <<" Ce doriti sa adaugati?\n";
    std::cout <<" Mancare\n";
    std::cout <<" Shopping\n";
    int op;
    std::cout <<" Optiune: ";
    std::cin >> op;
    if( op == 1)
    {
        try {
            Mancare mancare;
            Comanda* comanda = new Mancare(mancare);
            service.addElem(*comanda);
            delete comanda;

        }
        catch(...)
        {
            //exceptii
        }
    } 
    else
    {
        try {
            Shopping shopping;
            Comanda* comanda = new Shopping(shopping);
            service.addElem(*comanda);
            delete comanda;
        }
        catch(...)
        {
            //exceptii
        }
    }
     
}

void UI::logout()
{
    service.logout();
}

void UI::showAll()
{
    
}

void UI::run()
{
    this->login();
    this->add();
}
