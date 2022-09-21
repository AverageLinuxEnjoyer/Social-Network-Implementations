#include "Retea.h"

Retea::Retea()
{
    generare_utilizatori();
}

Retea::~Retea()
{
    
}

void Retea::generare_utilizatori() {

    inserare_user(User("Mihai", "Stefanescu", 20));
    inserare_user(User("Vlad", "Ionescu", 20));
    inserare_user(User("Ion", "Alexandrescu", 20));
    inserare_user(User("Andreea", "Muntean", 20));
    inserare_user(User("Mihaela", "Oltean", 20));


}

User Retea::get_user(string nume) {
    vector<User> users_ = get_users();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getNume() == nume) {
            return users_[i];
        }
    }
    return User();
}

vector<User> Retea::get_users() {
    return users.toVector();
}

vector<string> Retea::get_prieteni(string nume) {
    return prieteni.get(nume);
}

vector<Mesaj> Retea::get_mesaje(string nume) {
    return mesaje.get(nume);
}

void Retea::inserare_user(User user) {
    vector<User> users_ = users.toVector();
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getNume() == user.getNume()) {
            throw "Userul exista deja!";
        }
    }

    users.add(user);
}

void Retea::inserare_prietenie(Prietenie prietenie) {
    if (prieteni.search(prietenie.getNume_user1(), prietenie.getNume_user2())) {
        throw "Prietenia deja exista.";
    }

    prieteni.add(prietenie.getNume_user1(), prietenie.getNume_user2());
    prieteni.add(prietenie.getNume_user2(), prietenie.getNume_user1());
}

void Retea::inserare_mesaj(Mesaj mesaj) {
    mesaje.add(mesaj.getNume_user1(), mesaj);
    mesaje.add(mesaj.getNume_user2(), mesaj);
}

void Retea::update_user(string nume, User user) {
    vector<User> users_ = users.toVector();
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getNume() == nume) {
            users.update(users_[i], user);
            return;
        }
    }

    throw "Userul nu exista!";
}

void Retea::stergere_user(string nume) {
    vector<User> users_ = users.toVector();
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getNume() == nume) {

            // Sterge prietenii
            vector<string> prieteni_ = prieteni.get(nume);
            for (int j = 0; j < prieteni_.size(); j++) {
                prieteni.remove(nume, prieteni_[j]);
                prieteni.remove(prieteni_[j], nume);
            }

            // Sterge mesajele
            vector<Mesaj> mesaje_ = mesaje.get(nume);
            for (int j = 0; j < mesaje_.size(); j++) {
                mesaje.remove(nume, mesaje_[j]);
                mesaje.remove(mesaje_[j].getNume_user2(), mesaje_[j]);
            }

            users.remove(users_[i]);
            return;
        }
    }

    throw "Userul nu exista!";
}

void Retea::stergere_prietenie(Prietenie prietenie) {
    if (!prieteni.search(prietenie.getNume_user1(), prietenie.getNume_user2())) {
        throw "Prietenia nu exista!";
    }

    prieteni.remove(prietenie.getNume_user1(), prietenie.getNume_user2());
    prieteni.remove(prietenie.getNume_user2(), prietenie.getNume_user1());
}