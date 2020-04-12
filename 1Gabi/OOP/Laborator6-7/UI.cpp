#include "UI.h"

UI::UI(Service& serv): serv(serv)
{}

UI::~UI()
{

}

void UI::menu()
{
   std::cout << "\n--- Selectati optiunea: ---" << '\n';
   std::cout<< "1. Adaugare aplicatie "         << '\n';
   std::cout<< "2. Afisare aplicatii "          << '\n';
   std::cout<< "3. Modificare aplicatie "       << '\n';
   // cout<< "4. Numar de aplicatii "      << '\n';
   std::cout<< "4. Stergere aplicatie "         << '\n';
   std::cout<< "6.  Exit  "                     << '\n';
}

void UI::addAplicatie()
{
    std::string nume;
    std::string consum;
    std::string status;
    std::cout << "Numele aplicatiei: ";
    std::cin >> nume;
    std::cout << "ConsumKb: ";
    std::cin >> consum;
    // std::cout << "Status: ";
    // std::cin >> status;
	
	int consumKb = 0;
	
	try{
		consumKb = std::stoi(consum);
	}
	catch (std::exception&)
	{
		throw std::string("Consum invalid!\n");
	}

	serv.addAplicatie(nume, consumKb, status);
}

void UI::removeAplicatie()
{
    std::string id;
    std::cout<<"Alegeti ID-ul: ";
    std::cin >> id;

    int ID = 0;

    try {
        ID = std::stoi(id);
    }
    catch (std::exception)
    {
        throw std::string("Invalid ID!\n");
    }

    serv.removeAplicatie(ID);
    

}

void UI::updateAplicatie()
{
    std::string id;
    std::string nume;
    std::string consum;
    std::string status;
    std::cout<<"Aplicatia cu ID ales se va modifica. ";
    std::cin>>id;
    std::cout << "Numele aplicatiei: ";
    std::cin >> nume;
    std::cout << "ConsumKb: ";
    std::cin >> consum;
    std::cout << "Status: ";
    std::cin >> status;


    int ID = 0;
    try {
        ID = std::stoi(id);
    }
    catch (std::exception)
    {
        throw std::string("Invalid ID!\n");
    }

    int consumKb = 0;
    try {
        consumKb = std::stoi(consum);
    }
    catch (std::exception)
    {
        throw std::string("Invalid consum!\n");
    }

    serv.updateAplicatie(ID,nume,consumKb,status);
}
 

void UI::getAll()
{
    auto storage = serv.getAll();
    if (storage.empty())
    {
        std::cout << "The list is empty!\n";
        return;
    }
    for(const auto& it : storage)
    {
        std::cout<<" ID:";
        std::cout<< it.first<<'\n';
        std::cout<<"(Nume, ConsumKb, Status): "<<it.second<<'\n';

    }
    std::cout<<"\n";
}

void UI::run()
{
    char optiune;
    int ok = 1;
    while(ok)
    {
        menu();
        std::cin >> optiune;
        
        if(optiune == '1')
            try {
                this->addAplicatie();
                std::cout << "Added Successfully!\n";
            }
            catch (const std::string & err)
            {
                std::cout << err;
            }

        if(optiune == '2')
            this->getAll();
        
        if(optiune == '3')
            try {
                this->updateAplicatie();
                std::cout << "Modified successfully!\n";
            }
            catch (const std::string & err)
            {
                std::cout << err;
            }
        if(optiune == '4')
            try {
                this->removeAplicatie();
                std::cout << "Aplicatia a fost stearsa cu succes!\n";
            }
            catch (const std::string & err)
            {
                std::cout << err;
            }
        if(optiune == '6')
           ok = 0;
    }
}
