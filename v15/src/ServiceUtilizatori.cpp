#include "../include/ServiceUtilizatori.h"
#include <stdexcept>

ServiceUtilizatori::ServiceUtilizatori(Repo<Utilizator>& repo, std::string messages_file_name)
    : repo(repo), mesaje(), messages_file_name(messages_file_name)
{
    if (messages_file_name != "")
        loadMessagesFromFile();
}

ServiceUtilizatori::~ServiceUtilizatori()
{
    if (messages_file_name != "")
        saveMessagesToFile();
}

void ServiceUtilizatori::addUtilizator(const Utilizator& utilizator) {
    auto utilizatori = repo.getAll();

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == utilizator.getId()) {
            throw std::runtime_error("Exista deja un utilizator cu acest id.");
        }
    }

    repo.addElem(utilizator);
}

void ServiceUtilizatori::updateUtilizator(int id, const Utilizator& utilizator) {
    auto& utilizatori = repo.getAll();

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == utilizator.getId() && utilizatori[i].getId() != id) {
            throw std::runtime_error("Exista deja un utilizator cu acest id.");
        }
    }

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id) {
            utilizatori[i].setNume(utilizator.getNume());
            utilizatori[i].setPrenume(utilizator.getPrenume());
            utilizatori[i].setEmail(utilizator.getEmail());
            utilizatori[i].setVarsta(utilizator.getVarsta());
            utilizatori[i].setParola(utilizator.getParola());
            return;
        }
    }

    throw std::runtime_error("Utilizatorul nu a fost gasit.");
}

void ServiceUtilizatori::deleteUtilizator(int id) {
    auto utilizatori = repo.getAll();

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id) {
            repo.delElem(utilizatori[i]);
            return;
        }
    }

    throw std::runtime_error("Utilizatorul nu a fost gasit.");
}

Utilizator ServiceUtilizatori::getUtilizator(int id) {
    auto utilizatori = repo.getAll();

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id) {
            return utilizatori[i];
        }
    }
    
    throw std::runtime_error("Utilizatorul nu a fost gasit.");
}

Lista<Utilizator>& ServiceUtilizatori::getAll() {
    return repo.getAll();
}

void ServiceUtilizatori::adaugarePrieten(int id_utilizator, int id_prieten) {
    auto &utilizatori = repo.getAll();
    int index_utilizator = -1;
    int index_prieten = -1;
    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id_utilizator) {
            index_utilizator = i;
        }
        if (utilizatori[i].getId() == id_prieten) {
            index_prieten = i;
        }
    }

    if (index_utilizator == -1) {
        throw std::runtime_error("Utilizatorul nu a fost gasit.");
    }
    if (index_prieten == -1) {
        throw std::runtime_error("Prietenul nu a fost gasit.");
    }

    repo.getElem(index_utilizator).adaugaPrieten(id_prieten);
    repo.getElem(index_prieten).adaugaPrieten(id_utilizator);
}

Lista<int> ServiceUtilizatori::getPrieteni(int id_utilizator) {
    auto &utilizatori = repo.getAll();

    int index_utilizator = -1;
    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id_utilizator) {
            index_utilizator = i;
        }
    }

    if (index_utilizator == -1) {
        throw std::runtime_error("Utilizatorul nu a fost gasit.");
    }

    return repo.getElem(index_utilizator).getPrieteni();
}

void ServiceUtilizatori::participareEveniment(int id_utilizator, int id_eveniment) {
    auto &utilizatori = repo.getAll();
    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id_utilizator) {
            for (int j = 0; j < utilizatori[i].getEvenimente().size(); j++) {
                if (utilizatori[i].getEvenimente()[j] == id_eveniment) {
                    throw std::runtime_error("Utilizatorul este deja inscris ca participant la acest eveniment.");
                }
            }

            utilizatori[i].adaugaEveniment(id_eveniment);
            return;
        }
    }

    throw std::runtime_error("Utilizatorul nu a fost gasit.");
}

Lista<int> ServiceUtilizatori::getEvenimenteParticipate(int id_utilizator) {
    auto &utilizatori = repo.getAll();

    int index_utilizator = -1;
    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id_utilizator) {
            index_utilizator = i;
        }
    }

    if (index_utilizator == -1) {
        throw std::runtime_error("Utilizatorul nu a fost gasit.");
    }

    return repo.getElem(index_utilizator).getEvenimente();
}

void ServiceUtilizatori::trimiteMesaj(int utilizator1, int utilizator2, const std::string& mesaj) {
    auto &utilizatori = repo.getAll();

    int index_utilizator1 = -1;
    int index_utilizator2 = -1;

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == utilizator1) {
            index_utilizator1 = i;
        }
        if (utilizatori[i].getId() == utilizator2) {
            index_utilizator2 = i;
        }
    }

    if (index_utilizator1 == -1) {
        throw std::runtime_error("Utilizatorul 1 nu a fost gasit.");
    }
    if (index_utilizator2 == -1) {
        throw std::runtime_error("Utilizatorul 2 nu a fost gasit.");
    }

    mesaje.put(
        Pereche(utilizator1, utilizator2),
        Mesaj(utilizator1, utilizator2, mesaj)    
    );
}

Lista<Mesaj> ServiceUtilizatori::getMesaje(int id_utilizator1, int id_utilizator2) {
    auto &utilizatori = repo.getAll();

    int index_utilizator1 = -1;
    int index_utilizator2 = -1;

    for (int i = 0; i < utilizatori.size(); i++) {
        if (utilizatori[i].getId() == id_utilizator1) {
            index_utilizator1 = i;
        }
        if (utilizatori[i].getId() == id_utilizator2) {
            index_utilizator2 = i;
        }
    }

    if (index_utilizator1 == -1) {
        throw std::runtime_error("Utilizatorul 1 nu a fost gasit.");
    }
    if (index_utilizator2 == -1) {
        throw std::runtime_error("Utilizatorul 2 nu a fost gasit.");
    }

    Lista<Mesaj> lista_mesaje;
    if (!mesaje.contains(Pereche(id_utilizator1, id_utilizator2))) {
        return lista_mesaje;
    }
    else {
        return mesaje.get(Pereche(id_utilizator1, id_utilizator2));
    }
}

void ServiceUtilizatori::loadMessagesFromFile() {
    std::ifstream f("mesaje.txt");

    Mesaj mesaj;

    while (f >> mesaj) {
        mesaje.put(
            Pereche(mesaj.receiverId(), mesaj.senderId()),
            mesaj
        );
    } 
}

void ServiceUtilizatori::saveMessagesToFile() {
    std::ofstream f("mesaje.txt");

    const auto &mesaje_lista = this->mesaje.getAll();

    for (int i = mesaje_lista.size() -1 ; i >= 0; i--) {
        f << mesaje_lista[i].second << '\n';
    }
}
