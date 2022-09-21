#include "retea.h"

Retea::Retea()
{

}

Retea::~Retea()
{
    
}

void Retea::addUser(User user) {
    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == user.getId()) {
            return;
        }
    }

    this->users.add(user);
}

void Retea::updateUser(int id, User user) {
    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == id) {
            users.getAt(i) = user;
            return;
        }
    }
}

void Retea::removeUser(int id) {
    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == id) {
            users.remove(users.getAt(i));
            return;
        }
    }
}

std::vector<User> Retea::getUsers() {
    std::vector<User> users;
    for (int i = 0; i < this->users.size(); i++) {
        users.push_back(this->users.getAt(i));
    }
    return users;
}

void Retea::addEveniment(Eveniment eveniment) {
    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente.getAt(i).getId() == eveniment.getId()) {
            return;
        }
    }

    this->evenimente.add(eveniment);
}

void Retea::updateEveniment(int id, Eveniment eveniment) {
    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente.getAt(i).getId() == id) {
            evenimente.getAt(i) = eveniment;
            return;
        }
    }
}

void Retea::removeEveniment(int id) {
    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente.getAt(i).getId() == id) {
            evenimente.remove(evenimente.getAt(i));
            return;
        }
    }
}

std::vector<Eveniment> Retea::getEvenimente() {
    std::vector<Eveniment> evenimente;
    for (int i = 0; i < this->evenimente.size(); i++) {
        evenimente.push_back(this->evenimente.getAt(i));
    }
    return evenimente;
}

void Retea::addMesaj(Mesaj mesaj) {
    bool user1_gasit = false;
    bool user2_gasit = false;

    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == mesaj.getId_user_destinatar()) {
            user2_gasit = true;
        }
        if (users.getAt(i).getId() == mesaj.getId_user_expeditor()) {
            user1_gasit = true;
        }

    }

    if (user1_gasit && user2_gasit) {
        this->mesaje.add(mesaj);
    }
}

std::vector<Mesaj> Retea::getMesaje() {
    std::vector<Mesaj> mesaje;
    for (int i = 0; i < this->mesaje.size(); i++) {
        mesaje.push_back(this->mesaje.getAt(i));
    }
    return mesaje;
}

void Retea::addPrietenie(int id1, int id2) {
    bool user1_gasit = false;
    bool user2_gasit = false;

    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == id2) {
            user2_gasit = true;
        }
        if (users.getAt(i).getId() == id1) {
            user1_gasit = true;
        }
    }    

    if (user1_gasit && user2_gasit) {
        this->prietenii.adauga(id1, id2);
        this->prietenii.adauga(id2, id1);
    }
}

void Retea::removePrietenie(int id1, int id2) {
    bool user1_gasit = false;
    bool user2_gasit = false;

    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == id2) {
            user2_gasit = true;
        }
        if (users.getAt(i).getId() == id1) {
            user1_gasit = true;
        }
    }

    if (user1_gasit && user2_gasit) {
        this->prietenii.sterge(id1, id2);
        this->prietenii.sterge(id2, id1);
    }
}

std::vector<User> Retea::getPrieteni(int id) {
    std::vector<User> prieteni;

    std::vector<int> prieteni_id = this->prietenii.get(id);

    for (int i = 0; i < prieteni_id.size(); i++) {
        for (int j = 0; j < users.size(); j++) {
            if (users.getAt(j).getId() == prieteni_id.at(i)) {
                prieteni.push_back(users.getAt(j));
            }
        }
    }

    return prieteni;
}

User Retea::getUser(int id) {
    for (int i = 0; i < users.size(); i++) {
        if (users.getAt(i).getId() == id) {
            return users.getAt(i);
        }
    }

    User user;
    return user;
}
