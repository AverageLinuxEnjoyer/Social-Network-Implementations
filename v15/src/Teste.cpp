#include "../include/Teste.h"
#include "../include/Lista.h"
#include "../include/MultiDictionar.h"
#include "../include/ServiceUtilizatori.h"
#include "../include/ServiceEvenimente.h"
#include "../include/Eveniment.h"

#include <iostream>
#include <cassert>

void test_lista();
void test_multidictionar();
void test_service_utilizator();
void test_service_eveniment();

void teste() {
    test_lista();
    test_multidictionar();
    test_service_utilizator();

    std::cout << "Testele au fost executate cu succes!" << std::endl;
}

void test_lista() {
    Lista<int> list;
    
    assert(list.isEmpty());

    list.push_back(6);
    assert(list.size() == 1);
    assert(list[0] == 6);

    list.push_back(4);
    assert(list.size() == 2);
    assert(list[0] == 6);
    assert(list[1] == 4);

    list.push_front(5);
    assert(list.size() == 3);
    assert(list[0] == 5);
    assert(list[1] == 6);
    assert(list[2] == 4);

    list.insert(1, 3);
    assert(list.size() == 4);
    assert(list[0] == 5);
    assert(list[1] == 3);
    assert(list[2] == 6);
    assert(list[3] == 4);

    list.pop_front();
    assert(list.size() == 3);
    assert(list[0] == 3);
    assert(list[1] == 6);
    assert(list[2] == 4);

    list.erase(1);
    assert(list.size() == 2);
    assert(list[0] == 3);
    assert(list[1] == 4);
    
    list.pop_back();
    assert(list.size() == 1);
    assert(list[0] == 3);

    assert(!list.isEmpty());

    list.clear();

    assert(list.isEmpty());
}

void test_multidictionar() {
    MultiDictionar<int, int> MultiDictionar;

    MultiDictionar.put(1, 1);
    assert(MultiDictionar.get(1)[0] == 1);
    assert(MultiDictionar.contains(1));
    
    MultiDictionar.put(1, 2);
    assert(MultiDictionar.get(1)[0] == 1);
    assert(MultiDictionar.get(1)[1] == 2);
    assert(MultiDictionar.contains(1));

    assert(MultiDictionar.get(2) == Lista<int>());

    MultiDictionar.remove(1, 1);
    assert(MultiDictionar.get(1)[0] == 2);

    MultiDictionar.remove(1);
    assert(MultiDictionar.get(1) == Lista<int>());

    assert(!MultiDictionar.contains(1));
}

void test_service_utilizator() {
    Repo<Utilizator> repo;
    ServiceUtilizatori service(repo);

    assert(service.getAll().size() == 0);

    service.addUtilizator(
        Utilizator(1, "nume1", "prenume1", 20, "email1", "parola1")
    );

    Utilizator utilizator = service.getUtilizator(1);

    assert(service.getAll().size() == 1);
    assert(repo.getSize() == 1);
    assert(utilizator.getId() == 1);
    assert(utilizator.getNume() == "nume1");
    assert(utilizator.getPrenume() == "prenume1");
    assert(utilizator.getVarsta() == 20);
    assert(utilizator.getEmail() == "email1");
    assert(utilizator.getParola() == "parola1");

    service.updateUtilizator(
        utilizator.getId(),
        Utilizator(1, "nume2", "prenume2", 21, "email2", "parola2")
    );

    utilizator = service.getUtilizator(1);

    assert(service.getAll().size() == 1);
    assert(repo.getSize() == 1);
    assert(utilizator.getId() == 1);
    assert(utilizator.getNume() == "nume2");
    assert(utilizator.getPrenume() == "prenume2");
    assert(utilizator.getVarsta() == 21);
    assert(utilizator.getEmail() == "email2");
    assert(utilizator.getParola() == "parola2");

    service.deleteUtilizator(1);

    assert(service.getAll().size() == 0);
    assert(repo.getSize() == 0);

    service.addUtilizator(Utilizator(1, "nume1", "prenume1", 20, "email1", "parola1"));
    service.addUtilizator(Utilizator(2, "nume2", "prenume2", 21, "email2", "parola2"));

    assert(service.getAll().size() == 2);
    assert(repo.getSize() == 2);

    service.adaugarePrieten(1, 2);

    Utilizator u1 = service.getUtilizator(1);
    Utilizator u2 = service.getUtilizator(2);

    assert(u1.getPrieteni().size() == 1);
    assert(u2.getPrieteni().size() == 1);

    service.participareEveniment(1, 1);
    service.participareEveniment(1, 3);

    u1 = service.getUtilizator(1);
    u2 = service.getUtilizator(2);

    assert(u1.getEvenimente().size() == 2);
    assert(u1.getEvenimente()[0] == 1);    
    assert(u1.getEvenimente()[1] == 3);

    assert(service.getPrieteni(1).size() == 1);
    assert(service.getEvenimenteParticipate(1).size() == 2);

    service.trimiteMesaj(1, 2, "salut");
    service.trimiteMesaj(2, 1, "buna");
    service.trimiteMesaj(1, 2, "ce faci?");
    service.trimiteMesaj(2, 1, "bine");

    u1 = service.getUtilizator(1);
    u2 = service.getUtilizator(2);

    assert(service.getMesaje(1, 2).size() == 4);
    assert(service.getMesaje(1, 2)[0].getText() == "salut");
    assert(service.getMesaje(1, 2)[1].getText() == "buna");
    assert(service.getMesaje(1, 2)[2].getText() == "ce faci?");
    assert(service.getMesaje(1, 2)[3].getText() == "bine");

    assert(service.getMesaje(2, 1).size() == 4);
    assert(service.getMesaje(2, 1)[0].getText() == "salut");
    assert(service.getMesaje(2, 1)[1].getText() == "buna");
    assert(service.getMesaje(2, 1)[2].getText() == "ce faci?");
    assert(service.getMesaje(2, 1)[3].getText() == "bine");
}

void test_service_eveniment() {
    Repo<Eveniment> repo;

    ServiceEvenimente service(repo);

    assert(service.getAll().size() == 0);

    service.addEveniment(Eveniment(1, "denumire1", "data1", "locatie1", 50));

    Eveniment eveniment = service.getEveniment(1);

    assert(service.getAll().size() == 1);
    assert(repo.getSize() == 1);
    assert(eveniment.getId() == 1);
    assert(eveniment.getDenumire() == "denumire1");
    assert(eveniment.getData() == "data1");
    assert(eveniment.getLocatie() == "locatie1");
    assert(eveniment.getBileteRamase() == 50);
    assert(eveniment.getParticipanti().size() == 0);

    service.updateEveniment(
        eveniment.getId(),
        Eveniment(1, "denumire2", "data2", "locatie2", 51)
    );

    eveniment = service.getEveniment(1);

    assert(service.getAll().size() == 1);   
    assert(repo.getSize() == 1);
    assert(eveniment.getId() == 1);
    assert(eveniment.getDenumire() == "denumire2");
    assert(eveniment.getData() == "data2");
    assert(eveniment.getLocatie() == "locatie2");
    assert(eveniment.getBileteRamase() == 51);  
    assert(eveniment.getParticipanti().size() == 0);

    service.deleteEveniment(1);

    assert(service.getAll().size() == 0);
    assert(repo.getSize() == 0);

    service.addEveniment(Eveniment(1, "denumire1", "data1", "locatie1", 50));
    service.addEveniment(Eveniment(2, "denumire2", "data2", "locatie2", 51));

    assert(service.getAll().size() == 2);
    assert(repo.getSize() == 2);

    service.adaugareParticipant(1, 1);
    service.adaugareParticipant(1, 2);
    service.adaugareParticipant(2, 1);

    eveniment = service.getEveniment(1);
    auto eveniment2 = service.getEveniment(2);

    assert(eveniment.getParticipanti().size() == 2);
    assert(eveniment.getParticipanti()[0] == 1);
    assert(eveniment.getParticipanti()[1] == 2);
    assert(eveniment.getBileteRamase() == 48);

    assert(eveniment2.getParticipanti().size() == 1);
    assert(eveniment2.getParticipanti()[0] == 1);
    assert(eveniment2.getBileteRamase() == 49);

    assert(service.getParticipanti(1).size() == 2);
}

