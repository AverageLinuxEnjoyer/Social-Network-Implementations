#include "../include/ServiceUtilizator.h"

ServiceUtilizatori::ServiceUtilizatori()
{
    this->multime_ordonata.inserare(Utilizator(1, "Ion", 23, "invat"));
    this->multime_ordonata.inserare(Utilizator(2, "Andrei", 25, "dnd"));
    this->multime_ordonata.inserare(Utilizator(3, "Maria", 22, "asdlkaskl"));
    this->multime_ordonata.inserare(Utilizator(4, "Mihai", 21, "dfdafj"));
    this->multime_ordonata.inserare(Utilizator(5, "Cristina", 19, "asdasd"));
    this->multime_ordonata.inserare(Utilizator(6, "Vasile", 18, "asdasd"));
    this->multime_ordonata.inserare(Utilizator(7, "Ioana", 16, "asdasd"));
    this->multime_ordonata.inserare(Utilizator(8, "Alex", 15, "asdasd"));
    this->multime_ordonata.inserare(Utilizator(9, "Mihaela", 14, "asdasd"));
    this->multime_ordonata.inserare(Utilizator(10, "Diana", 13, "asdasd"));
}

void ServiceUtilizatori::adaugarePrieten(int id1, int id2) {
    Utilizator user = this->get(id1);
    user.adaugarePrieten(id2);
    this->modificare(user.getId(), user);

    Utilizator friend_user = this->get(id2);
    friend_user.adaugarePrieten(id1);
    this->modificare(friend_user.getId(), friend_user);
}

void ServiceUtilizatori::stergerePrieten(int id1, int id2) {
    Utilizator user = this->get(id1);
    user.stergerePrieten(id2);
    this->modificare(user.getId(), user);

    Utilizator friend_user = this->get(id2);
    friend_user.stergerePrieten(id1);
    this->modificare(friend_user.getId(), friend_user);
}

Lista<Utilizator> ServiceUtilizatori::getPrieteni(int id1) {
    Utilizator user = this->get(id1);
    Lista<Utilizator> user_friends;

    for (int i = 0; i < user.getPrieteni().getNrElems(); i++) {
        user_friends.inserare_sfarsit(this->get(user.getPrieteni()[i]));
    }

    return user_friends;
}

void ServiceUtilizatori::stergerePrieteni(int id1) {
    Utilizator user = this->get(id1);
    Lista<int> user_friends = user.getPrieteni();

    for (int i = 0; i < user_friends.getNrElems(); i++) {
        Utilizator friend_user = this->get(user_friends[i]);
        friend_user.stergerePrieten(id1);
        this->modificare(friend_user.getId(), friend_user);
    }
}

void ServiceUtilizatori::adaugareMesaj(int id1, int id2, std::string message) {
    messages.inserare_sfarsit(Mesaj(id1, id2, message));
}

Lista<Mesaj> ServiceUtilizatori::getMesage(int id1, int id2) {
    Lista<Mesaj> user_messages;

    for (int i = 0; i < messages.getNrElems(); i++) {
        if (messages[i].getId1() == id1 && messages[i].getId2() == id2 || messages[i].getId1() == id2 && messages[i].getId2() == id1) {
            user_messages.inserare_sfarsit(messages[i]);
        }
    }

    return user_messages;
}

void ServiceUtilizatori::stergereMesaje(int id1, int id2) {
    for (int i = 0; i < messages.getNrElems(); i++) {
        if (messages[i].getId1() == id1 && messages[i].getId2() == id2 || messages[i].getId1() == id2 && messages[i].getId2() == id1) {
            messages.stergere(i);
            break;
        }
    }
}

