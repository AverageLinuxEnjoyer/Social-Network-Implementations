#include "../include/retea.h"

Retea::Retea()
{
    createUsers();
    createPrietenii();
    createMesaje();
}

Retea::~Retea()
{
    
}

void Retea::addUser(const User &user) {
    List<User> users_ = users.toList();

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == user.getId()) {
            throw "Userul exista deja!";
        }
    }

    users.add(user);
}

void Retea::editUser(int id, const User &user) {
    List<User> users_ = users.toList();
    User* user_ = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id) {
            user_ = &users_.get(i);
        }
    }

    if (user_ != nullptr) {
        users.remove(*user_);
        users.add(user);
        return;
    } else {
        throw "Userul nu exista!";
    }


}

void Retea::removeUser(int id) {
    List<User> users_ = users.toList();
    User* user_ = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id) {
            user_ = &users_.get(i);
        }
    }

    if (user_ != nullptr) {
        users.remove(*user_);
        return;
    } else {
        throw "Userul nu exista!";
    }
}

void Retea::addPrietenie(int id1, int id2) {
    List<User> users_ = users.toList();
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id1) {
            user1 = &users_.get(i);
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id2) {
            user2 = &users_.get(i);
        }
    }

    for (int i = 0; i < prieteni.size(); i++) {
        if ((prieteni.get(i).getId1() == id1 && prieteni.get(i).getId2() == id2) || 
            (prieteni.get(i).getId1() == id2 && prieteni.get(i).getId2() == id1)) {
            throw "Prietenie exista deja!";
        }
    }

    if (user1 != nullptr && user2 != nullptr) {
        Prietenie prietenie(user1->getId(), user2->getId());
        prieteni.add(prietenie);
        return;
    } else {
        throw "Userii nu exista!";
    }
}

void Retea::removePrietenie(int id1, int id2) {
    List<User> users_ = users.toList();
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id1) {
            user1 = &users_.get(i);
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id2) {
            user2 = &users_.get(i);
        }
    }

    for (int i = 0; i < prieteni.size(); i++) {
        if ((prieteni.get(i).getId1() == id1 && prieteni.get(i).getId2() == id2) || 
            (prieteni.get(i).getId1() == id2 && prieteni.get(i).getId2() == id1)) {
            prieteni.remove(i);
            return;
        }
    }

    throw "Unul din utilizatori nu exista!";
}

void Retea::addMesaj(int id1, int id2, const std::string &text) {
    List<User> users_ = users.toList();
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id1) {
            user1 = &users_.get(i);
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id2) {
            user2 = &users_.get(i);
        }
    }

    if (user1 != nullptr && user2 != nullptr) {
        Mesaj mesaj(user1->getId(), user2->getId(), text);
        mesaje.add(mesaj);
        return;
    } else {
        throw "Userii nu exista!";
    }
}

void Retea::removeMesaje(int id1, int id2) {
    List<User> users_ = users.toList();
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id1) {
            user1 = &users_.get(i);
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id2) {
            user2 = &users_.get(i);
        }
    }

    if (user1 != nullptr && user2 != nullptr) {
        for (int i = 0; i < mesaje.size(); i++) {
            if ((mesaje.get(i).getId1() == id1 && mesaje.get(i).getId2() == id2) || 
                (mesaje.get(i).getId1() == id2 && mesaje.get(i).getId2() == id1)) {
                mesaje.remove(i);
            }
        }
        return;
    } else {
        throw "Userii nu exista!";
    }
}

List<User> Retea::getUsers() const {    
    return this->users.toList();
}

List<Prietenie> Retea::getPrietenii() const {
    return this->prieteni;
}

List<Mesaj> Retea::getMesaje(int id1, int id2) {
    List<User> users_ = users.toList();
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id1) {
            user1 = &users_.get(i);
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id2) {
            user2 = &users_.get(i);
        }
    }

    if (user1 != nullptr && user2 != nullptr) {
        List<Mesaj> mesaje_user;

        for (int i = 0; i < mesaje.size(); i++) {
            if ((mesaje.get(i).getId1() == id1 && mesaje.get(i).getId2() == id2) || 
                (mesaje.get(i).getId1() == id2 && mesaje.get(i).getId2() == id1)) {
                mesaje_user.add(mesaje.get(i));
            }
        }

        return mesaje_user;
    } else {
        throw "Userii nu exista!";
    }
}

User Retea::getUser(int id) const {
    List<User> users_ = users.toList();
    User* user = nullptr;

    for (int i = 0; i < users_.size(); i++) {
        if (users_.get(i).getId() == id) {
            user = &users_.get(i);
        }
    }

    if (user != nullptr) {
        return *user;
    } else {
        throw "Userul nu exista!";
    }
}

void Retea::createUsers() {
    this->addUser(User(1, "Ion", "ion@gmail.com"));
    this->addUser(User(2, "Maria", "maria@gmail.com"));
    this->addUser(User(3, "Mihai", "mihai@gmail.com"));
    this->addUser(User(4, "Vasile", "vasile@gmail.com"));
    this->addUser(User(5, "Cristina", "cristina@gmail.com"));
    this->addUser(User(6, "Iustin", "iustin@gmail.com"));
    this->addUser(User(7, "Alex", "alex@gmail.com"));
    this->addUser(User(8, "Paul", "paul@gmail.com"));
    this->addUser(User(9, "Andrei", "andrei@gmail.com"));
    this->addUser(User(10, "Alexandru", "alexandru@gmail.com"));
    this->addUser(User(11, "Mihaela", "mihaela@gmail.com"));
    this->addUser(User(12, "Ioana", "ioana@gmail.com"));
    this->addUser(User(13, "Daniel", "daniel@gmail.com"));
    this->addUser(User(14, "Daniela", "daniela@gmail.com"));
    this->addUser(User(15, "Vlad", "vlad@gmail.com"));
}

void Retea::createPrietenii() {
    this->addPrietenie(1, 2);
    this->addPrietenie(1, 3);
    this->addPrietenie(1, 13);
    this->addPrietenie(1, 14);
    this->addPrietenie(2, 4);
    this->addPrietenie(2, 5);
    this->addPrietenie(3, 6);
    this->addPrietenie(3, 7);
    this->addPrietenie(10, 13);
    this->addPrietenie(4, 8);
    this->addPrietenie(4, 9);
    this->addPrietenie(5, 10);
    this->addPrietenie(5, 11);
    this->addPrietenie(6, 12);
    this->addPrietenie(6, 13);
    this->addPrietenie(7, 14);
    this->addPrietenie(7, 15);
}

void Retea::createMesaje() {
    this->addMesaj(1, 2, "Salut!");
    this->addMesaj(2,1, "Buna!");
    this->addMesaj(1, 3, "Buna!");
    this->addMesaj(3, 1, "Buna!");
    this->addMesaj(1, 13, "Buna!");
    this->addMesaj(13, 1, "Salut!");
    this->addMesaj(1, 14, "Buna dimineata!");
    this->addMesaj(14, 1, "cf");
    this->addMesaj(2, 4, "Buna!");
    this->addMesaj(4, 2, "Buna!");
    this->addMesaj(2, 5, "Buna!");
    this->addMesaj(5, 2, "Buna!");
    this->addMesaj(3, 6, "Buna!");
    this->addMesaj(6, 3, "Buna!");
    this->addMesaj(3, 7, "Buna!");
    this->addMesaj(7, 3, "Buna!");
    this->addMesaj(10, 13, "Buna!");
    this->addMesaj(13, 10, "Buna!");
}

