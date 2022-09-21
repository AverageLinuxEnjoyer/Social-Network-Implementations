#include  "../include/ServiceEvenimente.h"
#include <fstream>

ServiceEvenimente::ServiceEvenimente(Repo<Eveniment>& repo, std::string messages_file_name)
    : repo(repo), messages_file_name(messages_file_name)
{
    loadParticipantsFromFile();
}

ServiceEvenimente::~ServiceEvenimente()
{   
    saveParticipantsToFile();
}

void ServiceEvenimente::addEveniment(const Eveniment& eveniment) {
    auto evenimente = repo.getAll();

    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == eveniment.getId()) {
            throw std::runtime_error("Exista deja un eveniment cu acest id.");
        }
    }

    repo.addElem(eveniment);
}

void ServiceEvenimente::updateEveniment(int id, const Eveniment& eveniment) {
    auto& evenimente = repo.getAll();

    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == eveniment.getId() && evenimente[i].getId() != id) {
            throw std::runtime_error("Exista deja un eveniment cu acest id.");
        }
    }
    
    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == id) {
            evenimente[i].setDenumire(eveniment.getDenumire());
            evenimente[i].setBileteRamase(eveniment.getBileteRamase());
            evenimente[i].setData(eveniment.getData());
            evenimente[i].setLocatie(eveniment.getLocatie());
            return;
        }
    }

    throw std::runtime_error("Evenimentul nu a fost gasit.");
}

void ServiceEvenimente::deleteEveniment(int id) {
    auto evenimente = repo.getAll();

    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == id) {
            repo.delElem(evenimente[i]);
            return;
        }
    }

    throw std::runtime_error("Evenimentul nu a fost gasit.");
}

Eveniment ServiceEvenimente::getEveniment(int id) {
    auto evenimente = repo.getAll();

    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == id) {
            return evenimente[i];
        }
    }

    throw std::runtime_error("Evenimentul nu a fost gasit.");
}

Lista<Eveniment>& ServiceEvenimente::getAll() {
    return repo.getAll();
}

void ServiceEvenimente::adaugareParticipant(int id_eveniment, int id_participant) {
    auto& evenimente = repo.getAll();
    for (int i = 0; i < evenimente.size(); i++)
    {
        if (evenimente[i].getId() == id_eveniment)
        {
            for (int j = 0; j < evenimente[i].getParticipanti().size(); j++)
            {
                if (evenimente[i].getParticipanti()[j] == id_participant)
                {
                    throw std::runtime_error("Participantul este deja inscris la acest eveniment.");
                }
            }

            std::cout << "User " << id_participant << " added to event " << id_eveniment << std::endl;
            evenimente[i].adaugaParticipant(id_participant);
            evenimente[i].setBileteRamase(evenimente[i].getBileteRamase() - 1);
            return;
        }
    }

    throw std::runtime_error("Evenimentul nu a fost gasit.");
}

Lista<int> ServiceEvenimente::getParticipanti(int id_eveniment) {
    auto evenimente = repo.getAll();

    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente[i].getId() == id_eveniment) {
            return evenimente[i].getParticipanti();
        }
    }

    throw std::runtime_error("Evenimentul nu a fost gasit.");
}

void ServiceEvenimente::loadParticipantsFromFile() {
    std::ifstream file(messages_file_name);
    if (!file.is_open()) {
        return;
    }

    int id_eveniment, id_participant;
    while (file >> id_eveniment >> id_participant) {
        adaugareParticipant(id_eveniment, id_participant);
    }
}

void ServiceEvenimente::saveParticipantsToFile() {  
    std::ofstream file(messages_file_name);
    if (!file.is_open()) {
        return;
    }

    auto evenimente = repo.getAll();
    for (int i = 0; i < evenimente.size(); i++) {
        for (int j = 0; j < evenimente[i].getParticipanti().size(); j++) {
            file << evenimente[i].getId() << " " << evenimente[i].getParticipanti()[j] << std::endl;
        }
    }
}

