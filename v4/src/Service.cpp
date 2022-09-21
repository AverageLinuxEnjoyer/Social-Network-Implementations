#include "../include/Service.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Service::Service(bool read_write_file)
    : read_write_file(read_write_file)
{
    if (read_write_file) {
        // citeste Utilizatori din fisiere
        std::ifstream file("Utilizatori.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string nume_utilizator;
            int varsta;
            std::string email;
            ss >> nume_utilizator >> varsta >> email;
            utilizatori.insert(Utilizator(nume_utilizator, varsta, email));
        }

        // citeste evenimente din fisier
        std::ifstream file2("evenimente.txt");
        std::string line2;
        while (std::getline(file2, line2)) {
            std::stringstream ss(line2);
            std::string name;
            std::string location;
            std::string description;
            std::string date;
            ss >> std::quoted(name) >> std::quoted(location) >> std::quoted(description) >> std::quoted(date);
            Eveniments.insert(Eveniments.size(), Eveniment(name, location, description, date));
        }
    }

}

Service::~Service()
{
    if (read_write_file) {
        // scrie Utilizatori in fisier
        std::ofstream file("Utilizatori.txt");
        for (auto &Utilizator : utilizatori) {
            file << Utilizator.getnume_utilizator() << " " << Utilizator.getvarsta() << " " << Utilizator.getEmail() << std::endl;
        }

        // scrie evenimente in fisier
        std::ofstream file2("evenimente.txt");
        for (int i = 0; i < Eveniments.size(); i++) {
            file2 << std::quoted(Eveniments[i].getNume()) << " " << std::quoted(Eveniments[i].getLocatie()) << " " << std::quoted(Eveniments[i].getDescriere()) << " " << std::quoted(Eveniments[i].getData())<< std::endl;
        }
    }
}

bool Service::addUtilizator(std::string nume_utilizator, int varsta, std::string email) {
    // verifica daca numele e unic
    for (auto& Utilizator : utilizatori)
        if (Utilizator.getnume_utilizator() == nume_utilizator)
            return false;

    utilizatori.insert(Utilizator(nume_utilizator, varsta, email));
    return true;
}

bool Service::updateUtilizator(std::string nume_utilizator, std::string nume_utilizator_nou, int varsta_noua, std::string email_nou) {

    for (auto& Utilizator : utilizatori)
    {
        if (Utilizator.getnume_utilizator() == nume_utilizator)
        {
            for(auto& Utilizator2 : utilizatori)
                if (Utilizator2.getnume_utilizator() == nume_utilizator_nou && Utilizator != Utilizator2)
                    return false;

            Utilizator.setnume_utilizator(nume_utilizator_nou);
            Utilizator.setvarsta(varsta_noua);
            Utilizator.setEmail(email_nou);
            return true;
        }
    }

    return false;
}

bool Service::removeUtilizator(std::string nume_utilizator) {
    // find Utilizator
    Utilizator* Utilizator = nullptr;
    for (auto& Utilizator2 : utilizatori)
        if (Utilizator2.getnume_utilizator() == nume_utilizator)
        {
            Utilizator = &Utilizator2;
            break;
        }

    if (Utilizator == nullptr)
        return false;

    // remove Prietenies of the Utilizator and its friends
    for (int j = 0; j < Utilizator->getFriends().size(); j++)
        removePrietenie(Utilizator->getnume_utilizator(), Utilizator->getFriends()[j].getUtilizator2()->getnume_utilizator());


    // remove the Utilizator
    for (auto &Utilizator2 : utilizatori)
        Utilizator2.removeFriend(*Utilizator);
    
    return true;
}

bool Service::addPrietenie(std::string nume_utilizator1, std::string nume_utilizator2) {
    // find utilizatori
    Utilizator *Utilizator1 = nullptr;
    Utilizator *Utilizator2 = nullptr;

    for (auto& Utilizator : utilizatori)
    {
        if (Utilizator.getnume_utilizator() == nume_utilizator1)
            Utilizator1 = &Utilizator;
        if (Utilizator.getnume_utilizator() == nume_utilizator2)
            Utilizator2 = &Utilizator;
    }

    // check if utilizatori exist
    if (Utilizator1 == nullptr || Utilizator2 == nullptr)
        return false;

    // check if Prietenie already exists
    for (int i = 0; i < Utilizator1->getFriends().size(); i++) {
        if (Utilizator1->getFriends()[i].getUtilizator1() == Utilizator1 && Utilizator1->getFriends()[i].getUtilizator2() == Utilizator2) {
            return false;
        }
    }

    // add Prietenie
    Utilizator1->addFriend(*Utilizator2);
    Utilizator2->addFriend(*Utilizator1);
    return true;
}

bool Service::removePrietenie(std::string nume_utilizator1, std::string nume_utilizator2) {
    // find utilizatori
    Utilizator *Utilizator1 = nullptr;
    Utilizator *Utilizator2 = nullptr;
    for (auto& Utilizator : utilizatori)
    {
        if (Utilizator.getnume_utilizator() == nume_utilizator1)
            Utilizator1 = &Utilizator;
        if (Utilizator.getnume_utilizator() == nume_utilizator2)
            Utilizator2 = &Utilizator;
    }

    // check if utilizatori exist
    if (Utilizator1 == nullptr || Utilizator2 == nullptr) {
        return false;
    }

    // check if Prietenie exists
    for (int i = 0; i < Utilizator1->getFriends().size(); i++) {
        if (Utilizator1->getFriends()[i].getUtilizator1() == Utilizator1 && Utilizator1->getFriends()[i].getUtilizator2() == Utilizator2) {
            Utilizator1->removeFriend(*Utilizator2);
            Utilizator2->removeFriend(*Utilizator1);
            return true;
        }
    }

    return false;
}

bool Service::trimiteMesaj(std::string expeditor_nume_utilizator, std::string destinatar_nume_utilizator, std::string Mesaj) {
    // find utilizatori
    Utilizator *expeditor = nullptr;
    Utilizator *destinatar = nullptr;
    for (auto& Utilizator : utilizatori)
    {
        if (Utilizator.getnume_utilizator() == expeditor_nume_utilizator)
            expeditor = &Utilizator;
        if (Utilizator.getnume_utilizator() == destinatar_nume_utilizator)
            destinatar = &Utilizator;
    }

    // check if utilizatori exist
    if (expeditor == nullptr || destinatar == nullptr)
        return false;

    expeditor->sendMesaj(*destinatar, Mesaj);

    return true;
}

Lista<Utilizator*> Service::getUtilizatori() {
    Lista<Utilizator*> Lista;
    for (auto& Utilizator : utilizatori)
        Lista.insert(Lista.size(), &Utilizator);


    return Lista;
}


bool Service::addEveniment(std::string name, std::string location, std::string description, std::string date) {
    // check if the Eveniment names are unique
    for (int i = 0; i < Eveniments.size(); i++)
        if (Eveniments[i].getNume() == name)
            return false;

    Eveniments.insert(Eveniments.size(), Eveniment(name, location, description, date));

    return true;
}

Lista<Eveniment> Service::getEvenimente() {
    return Eveniments;
}

bool Service::updateEveniment(std::string name, std::string newName, std::string newLocation, std::string newDescription, std::string newDate) {
    for (int i = 0; i < Eveniments.size(); i++)
    {
        if (Eveniments[i].getNume() == name)
        {
            // check if the Eveniment names are unique
            for (int j = 0; j < Eveniments.size(); j++)
                if (Eveniments[j].getNume() == newName && i != j)
                    return false;
                    
            Eveniments[i].setNume(newName);
            Eveniments[i].setLocatie(newLocation);
            Eveniments[i].setDescriere(newDescription);
            Eveniments[i].setData(newDate);

            return true;
        }
    }

    return false;
}

bool Service::removeEveniment(std::string name) {
    for (int i = 0; i < Eveniments.size(); i++)
    {
        if (Eveniments[i].getNume() == name)
        {
            Eveniments.remove(i);
            return true;
        }
    }

    return false;
}

bool Service::addInterestedUtilizator(std::string nume_eveniment, std::string nume_utilizator) {
    // find Eveniment
    Eveniment *Eveniment = nullptr;
    for (int i = 0; i < Eveniments.size(); i++)
    {
        if (Eveniments[i].getNume() == nume_eveniment)
        {
            Eveniment = &Eveniments[i];
            break;
        }
    }

    // find Utilizator
    Utilizator *Utilizator = nullptr;
    for (auto& Utilizator2 : utilizatori) {
        if (Utilizator2.getnume_utilizator() == nume_utilizator)
        {
            Utilizator = &Utilizator2;
            break;
        }
    }

    // check if Eveniment and Utilizator exist
    if (Eveniment == nullptr || Utilizator == nullptr)
        return false;

    Eveniment->addUtilizatorInteresat(Utilizator);

    return true;
}
