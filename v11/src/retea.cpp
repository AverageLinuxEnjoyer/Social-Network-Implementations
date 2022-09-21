#include "../include/retea.h"
#include <fstream>

Retea::Retea()
{
    citire_utilizatori_din_fisier();
    citire_evenimente_din_fisier();    
}

Retea::~Retea()
{
    scriere_utilizatori_in_fisier();
    scriere_evenimente_in_fisier();
}

Utilizator Retea::getDupaId(int id) {
    std::vector<Utilizator> utilizatori_vec = utilizatori.toVector();

    for (auto it = utilizatori_vec.begin(); it != utilizatori_vec.end(); ++it) {
        if (it->getId() == id) {
            return *it;
        }
    }

    Utilizator u;
    return u;
}

std::vector<Utilizator> Retea::getUtilizatori() {
    return utilizatori.toVector();
}

bool Retea::adaugareUtilizator(Utilizator user) {
    if (utilizatori.exista(user)) {
        return false;
    }

    utilizatori.adaugare(user);

    return true;
}

bool Retea::modificareUtilizator(int id, Utilizator user) {
    if (!utilizatori.exista(user)) {
        return false;
    }

    utilizatori.stergere(user);
    utilizatori.adaugare(user);

    return true;
}

bool Retea::stergereUtilizator(int id) {
    Utilizator user;
    user.setId(id);

    if (!utilizatori.exista(user)) {
        return false;
    }

    utilizatori.stergere(user);

    return true;
}

std::vector<Eveniment> Retea::getEvenimente() {
    return evenimente.toVector();
}

bool Retea::adaugareEveniment(Eveniment event) {
    if (evenimente.exista(event)) {
        return false;
    }

    evenimente.adaugare(event);

    return true;
}

bool Retea::modificareEveniment(int id, Eveniment event) {
    if (!evenimente.exista(event)) {
        return false;
    }

    evenimente.stergere(event);
    evenimente.adaugare(event);

    return true;
}

bool Retea::stergereEveniment(int id) {
    Eveniment event;
    event.setId(id);

    if (!evenimente.exista(event)) {
        return false;
    }

    evenimente.stergere(event);

    return true;
}

bool Retea::participareEveniment(int id_user, int id_eveniment) {
    Eveniment eveniment;
    eveniment.setId(id_eveniment);
    if (!evenimente.exista(eveniment)) {
        return false;
    }

    Utilizator user;
    user.setId(id_user);
    if (!utilizatori.exista(user)) {
        return false;
    }

    if (evenimente_participate.exista(id_user, id_eveniment)) {
        return false;
    }

    evenimente_participate.adauga(id_user, id_eveniment);

    return true;
}

bool Retea::anulareParticipare(int id_user, int id_eveniment) {
    Eveniment eveniment;
    eveniment.setId(id_eveniment);
    if (!evenimente.exista(eveniment)) {
        return false;
    }

    Utilizator user;
    user.setId(id_user);
    if (!utilizatori.exista(user)) {
        return false;
    }

    if (!evenimente_participate.exista(id_user, id_eveniment)) {
        return false;
    }

    evenimente_participate.sterge(id_user, id_eveniment);

    return true;
}

std::vector<Eveniment> Retea::getEvenimenteParticipate(int id_user) {
    std::vector<Eveniment> evenimente_participate_user;

    std::vector<int> evenimente_participate_ids = evenimente_participate.get(id_user);

    for (int i = 0; i < evenimente_participate_ids.size(); i++) {
        Eveniment eveniment;
        eveniment = evenimente.getById(evenimente_participate_ids[i]);

        evenimente_participate_user.push_back(eveniment);
    }

    return evenimente_participate_user;
}

bool Retea::adaugarePrietenie(int id_user1, int id_user2) {
    Utilizator user1;
    user1.setId(id_user1);
    if (!utilizatori.exista(user1)) {
        return false;
    }

    Utilizator user2;
    user2.setId(id_user2);
    if (!utilizatori.exista(user2)) {
        return false;
    }

    if (prieteni.exista(id_user1, id_user2)) {
        return false;
    }

    prieteni.adauga(id_user1, id_user2);
    prieteni.adauga(id_user2, id_user1);

    return true;
}

bool Retea::stergerePrietenie(int id_user1, int id_user2) {
    Utilizator user1;
    user1.setId(id_user1);
    if (!utilizatori.exista(user1)) {
        return false;
    }

    Utilizator user2;
    user2.setId(id_user2);
    if (!utilizatori.exista(user2)) {
        return false;
    }

    if (!prieteni.exista(id_user1, id_user2)) {
        return false;
    }

    prieteni.sterge(id_user1, id_user2);
    prieteni.sterge(id_user2, id_user1);

    return true;
}

std::vector<Utilizator> Retea::getPrieteni(int id_user) {
    std::vector<Utilizator> prieteni_user;

    std::vector<int> prieteni_ids = prieteni.get(id_user);

    for (int i = 0; i < prieteni_ids.size(); i++) {
        Utilizator user;
        user = utilizatori.getById(prieteni_ids[i]);

        prieteni_user.push_back(user);
    }

    return prieteni_user;
}

bool Retea::adaugareMesaj(Mesaj mesaj) {
    int id_user1 = mesaj.getIdUser1();
    Utilizator user1;
    user1.setId(id_user1);
    if (!utilizatori.exista(user1)) {
        return false;
    }

    int id_user2 = mesaj.getIdUser2();
    Utilizator user2;
    user2.setId(id_user2);
    if (!utilizatori.exista(user2)) {
        return false;
    }

    mesaje.push_back(mesaj);

    return true;
}

std::vector<Mesaj> Retea::getMesaje(int id_user1, int id_user2) {
    std::vector<Mesaj> mesaje_user;

    for (int i = 0; i < mesaje.size(); i++) {
        if ((mesaje[i].getIdUser1() == id_user1 && mesaje[i].getIdUser2() == id_user2) ||
            (mesaje[i].getIdUser1() == id_user2 && mesaje[i].getIdUser2() == id_user1)) {
            mesaje_user.push_back(mesaje[i]);
        }
    }

    return mesaje_user;
}

void Retea::citire_utilizatori_din_fisier() {
    std::ifstream fin("utilizatori.txt");
    if (!fin.is_open()) {
        return;
    }

    int id, varsta;
    std::string nume, prenume, adresa, telefon, email, parola;

    while (fin >> id >> nume >> prenume >> varsta >> adresa >> telefon >> email >> parola)
    {
        Utilizator user;
        user.setId(id)
        .setNume(nume)
        .setPrenume(prenume)
        .setVarsta(varsta)
        .setAdresa(adresa)
        .setTelefon(telefon)
        .setEmail(email)
        .setParola(parola);

        utilizatori.adaugare(user);
    }
}

void Retea::citire_evenimente_din_fisier() {
    std::ifstream fin("evenimente.txt");
    if (!fin.is_open()) {
        return;
    }

    int id;
    std::string nume, locatie, data, ora, tip, descriere;

    while (fin >> id >> nume >> locatie >> data >> ora >> tip >> descriere)
    {
        Eveniment eveniment;
        eveniment.setId(id)
        .setNume(nume)
        .setLocatie(locatie)
        .setData(data)
        .setOra(ora)
        .setTip(tip)
        .setDescriere(descriere);

        evenimente.adaugare(eveniment);
    }
}

void Retea::scriere_utilizatori_in_fisier() {
    std::ofstream fout("utilizatori.txt");
    if (!fout.is_open()) {
        return;
    }

    std::vector<Utilizator> u_vec = utilizatori.toVector();

    for (int i = 0; i < u_vec.size(); i++) {
        fout << u_vec[i].getId() << " " << u_vec[i].getNume() << " " << u_vec[i].getPrenume() << " " << u_vec[i].getVarsta() << " " << u_vec[i].getAdresa() << " " << u_vec[i].getTelefon() << " " << u_vec[i].getEmail() << " " << u_vec[i].getParola() << std::endl;
    }
}

void Retea::scriere_evenimente_in_fisier() {
    std::ofstream fout("evenimente.txt");
    if (!fout.is_open()) {
        return;
    }

    std::vector<Eveniment> e_vec = evenimente.toVector();

    for (int i = 0; i < e_vec.size(); i++) {
        fout << e_vec[i].getId() << " " << e_vec[i].getNume() << " " << e_vec[i].getLocatie() << " " << e_vec[i].getData() << " " << e_vec[i].getOra() << " " << e_vec[i].getTip() << " " << e_vec[i].getDescriere() << std::endl;
    }
}

