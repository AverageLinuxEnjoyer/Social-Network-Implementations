#include <iostream>
#include <cassert>

#include "../include/Tests.h"
#include "../include/Lista.h"
#include "../include/MultimeOrdonata.h"
#include "../include/Service.h"

#include "../include/Culori.h"

static Modifier::Modifier green(Modifier::FG_GREEN);
static Modifier::Modifier def(Modifier::FG_DEFAULT);

void test_Lista();
void test_multime_ordonata();

void test_Utilizator();
void test_service();

void teste() {
    test_Lista();
    test_multime_ordonata();
    test_Utilizator();
    test_service();

    std::cout << green << "Testele au fost trecute cu succes!" << std::endl << def;
}

void test_Lista() {
    Lista<int>* Lista1 = new Lista<int>();
    assert(Lista1->count == 0);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    Lista1->capacity = 20;

    Lista<int>* Lista2 = new Lista<int>(*Lista1);
    assert(Lista2->count == 0);
    assert(Lista2->capacity == 20);
    assert(Lista2->data != nullptr);

    Lista<int>* Lista3 = new Lista<int>(std::move(*Lista2));
    assert(Lista3->isEmpty());
    assert(Lista3->count == 0);
    assert(Lista3->capacity == 20);
    assert(Lista3->data != nullptr);

    assert(Lista2->capacity == 10);
    assert(Lista2->count == 0);
    assert(Lista2->data == nullptr);

    delete Lista2;
    delete Lista3;
    Lista1->capacity = 10;

    Lista1->insert(0, 6);
    assert(Lista1->count == 1);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 6);

    Lista1->insert(Lista1->size(), 4);
    assert(Lista1->count == 2);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 6);
    assert(Lista1->data[1] == 4);

    Lista1->insert(0, 5);
    assert(Lista1->count == 3);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 5);
    assert(Lista1->data[1] == 6);
    assert(Lista1->data[2] == 4);

    Lista1->insert(1, 3);
    assert(Lista1->count == 4);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 5);
    assert(Lista1->data[1] == 3);
    assert(Lista1->data[2] == 6);
    assert(Lista1->data[3] == 4);

    Lista1->remove(0);
    assert(Lista1->count == 3);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 3);
    assert(Lista1->data[1] == 6);
    assert(Lista1->data[2] == 4);

    Lista1->remove(1);
    assert(Lista1->count == 2);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 3);
    assert(Lista1->data[1] == 4);

    assert(!Lista1->isEmpty());

    Lista1->remove(Lista1->size() - 1);
    assert(Lista1->count == 1);
    assert(Lista1->capacity == 10);
    assert(Lista1->data != nullptr);
    assert(Lista1->data[0] == 3);

    Lista1->clear();
    assert(Lista1->count == 0);
    assert(Lista1->capacity == 10);
    assert(Lista1->data == nullptr);
    assert(Lista1->isEmpty());

    std::cout << green << "Testele Listaei au fost trecute cu succes." << std::endl << def;
}

void test_multime_ordonata() {
    MultimeOrdonata<int> multime_ordonata;

    multime_ordonata.insert(1);
    assert(multime_ordonata.contains(1));
    assert(*multime_ordonata.begin() == 1);
    assert(multime_ordonata.getSize() == 1);
    assert(!multime_ordonata.contains(2));

    assert(!multime_ordonata.isEmpty());

    multime_ordonata.insert(2);
    assert(multime_ordonata.contains(2));
    assert(multime_ordonata.getSize() == 2);
    auto it = multime_ordonata.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);

    multime_ordonata.remove(1);
    assert(!multime_ordonata.contains(1));
    assert(multime_ordonata.contains(2));
    assert(*multime_ordonata.begin() == 2);
    assert(multime_ordonata.getSize() == 1);

    multime_ordonata.remove(2);
    assert(!multime_ordonata.contains(1));
    assert(!multime_ordonata.contains(2));
    assert(multime_ordonata.begin() == multime_ordonata.end());

    assert(multime_ordonata.isEmpty());

    multime_ordonata.insert(5);
    multime_ordonata.insert(3);
    multime_ordonata.insert(-17);
    multime_ordonata.insert(-29);
    multime_ordonata.insert(13);
    multime_ordonata.insert(4);
    multime_ordonata.insert(1);

    assert(multime_ordonata.getSize() == 7);

    auto it2 = multime_ordonata.begin();
    assert(*it2 == -29);

    ++it2;
    assert(*it2 == -17);

    ++it2;
    assert(*it2 == 1);

    ++it2;
    assert(*it2 == 3);

    ++it2;
    assert(*it2 == 4);

    ++it2;
    assert(*it2 == 5);

    ++it2;
    assert(*it2 == 13);

    ++it2;
    assert(it2 == multime_ordonata.end());

    multime_ordonata.clear();

    assert(multime_ordonata.isEmpty());
    assert(multime_ordonata.begin() == multime_ordonata.end());
    assert(multime_ordonata.getSize() == 0);

    std::cout << green << "Testele multimii ordonate au fost trecute cu succes." << std::endl << def;
}

void test_Utilizator() {
    Utilizator Utilizator1("Ion", 19, "creangaion@gmail.com");

    assert(Utilizator1.getnume_utilizator() == "Ion");    
    assert(Utilizator1.getvarsta() == 19);
    assert(Utilizator1.getEmail() == "creangaion@gmail.com");
    assert(Utilizator1.getFriends().empty());

    Utilizator Utilizator2("Maria", 20, "maria@yahoo.com");

    assert(Utilizator2.getnume_utilizator() == "Maria");
    assert(Utilizator2.getvarsta() == 20);
    assert(Utilizator2.getEmail() == "maria@yahoo.com");
    assert(Utilizator2.getFriends().empty());

    Utilizator1.addFriend(Utilizator2);
    Utilizator2.addFriend(Utilizator1);
    
    auto Utilizator1friends = Utilizator1.getFriends();
    assert(Utilizator1friends.size() == 1);

    auto Utilizator2friends = Utilizator2.getFriends();
    assert(Utilizator2friends.size() == 1);

    Utilizator1.sendMesaj(Utilizator2, "hello");
    assert(Utilizator1.getMesaje().size() == 1);
    assert(Utilizator2.getMesaje().size() == 1);

    auto Mesaj1 = Utilizator1.getMesaje()[0];
    assert(Mesaj1.getExpeditor() == &Utilizator1);
    assert(Mesaj1.getDestinatar() == &Utilizator2);
    assert(Mesaj1.getContinut() == "hello");

    auto Mesaj2 = Utilizator2.getMesaje()[0];
    assert(Mesaj2.getExpeditor() == &Utilizator1);
    assert(Mesaj2.getDestinatar() == &Utilizator2);
    assert(Mesaj2.getContinut() == "hello");

    Utilizator Utilizator3("Mihai", 25, "mihai@gmail.com");
    Utilizator Utilizator4("Vasile", 17, "vasile@gmail.com");

    Utilizator3.sendMesaj(Utilizator4, "vi la un lol?");
    assert(Utilizator3.getMesaje().size() == 1);
    assert(Utilizator4.getMesaje().size() == 1);

    std::cout << green << "Testele clasei utilizator au fost trecute cu succes!" << std::endl << def;
}

inline void test_service() {
    Service service;

    service.addUtilizator("Ion", 19, "creangaion@gmail.com");
    assert(service.getUtilizatori().size() == 1);
    
    service.addUtilizator("Maria", 20, "maria@yahoo.com");
    assert(service.getUtilizatori().size() == 2);

    Lista<Utilizator*> utilizatori = service.getUtilizatori();

    assert(utilizatori[0]->getnume_utilizator() == "Ion");
    assert(utilizatori[0]->getvarsta() == 19);
    assert(utilizatori[0]->getEmail() == "creangaion@gmail.com");
    assert(utilizatori[0]->getFriends().empty());

    assert(utilizatori[1]->getnume_utilizator() == "Maria");
    assert(utilizatori[1]->getvarsta() == 20);
    assert(utilizatori[1]->getEmail() == "maria@yahoo.com");
    assert(utilizatori[1]->getFriends().empty());

    service.updateUtilizator("Ion", "Creanga", 25, "business@amintiricopilarie.com");
    utilizatori = service.getUtilizatori();

    assert(service.getUtilizatori().size() == 2);
    assert(utilizatori[0]->getnume_utilizator() == "Creanga");
    assert(utilizatori[0]->getvarsta() == 25);
    assert(utilizatori[0]->getEmail() == "business@amintiricopilarie.com");
    assert(utilizatori[0]->getFriends().empty());

    service.addPrietenie("Creanga", "Maria");

    assert(service.getUtilizatori()[0]->getFriends().size() == 1);
    assert(service.getUtilizatori()[1]->getFriends().size() == 1);

    service.trimiteMesaj("Creanga", "Maria", "buna ce faci");
    utilizatori  = service.getUtilizatori();
    assert(utilizatori[0]->getMesaje().size() == 1);
    assert(utilizatori[1]->getMesaje().size() == 1);
    
    Mesaj Mesaj = utilizatori[0]->getMesaje()[0];
    utilizatori  = service.getUtilizatori();
    assert(Mesaj.getExpeditor() == utilizatori[0]);
    assert(Mesaj.getDestinatar() == utilizatori[1]);
    assert(Mesaj.getContinut() == "buna ce faci");

    std::cout << green << "Testele clasei service au fost trecute cu succes." << std::endl << def;
}
