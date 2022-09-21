#include "../include/Retea.h"
#include <bits/types/FILE.h>
#include <vector>

bool Retea::existaUtilizator(int id) {
    return utilizatori.contains(Utilizator(id, "", "", "", "", false));
}


bool Retea::existaEveniment(int id) {
    return evenimente.contains(Eveniment(id, "", "", ""));
}


bool Retea::existaMesaj(int id) {
    return mesaje.contains(Mesaj(id, 0, 0, "", ""));
}

Retea::Retea()
    : fileManager("utilizatori.csv", "evenimente.csv", "prietenii.csv", "mesaje.csv", this)
{
    fileManager.loadFromFile();
}

Retea::~Retea()
{
    fileManager.saveToFile();
}

void Retea::adaugaUtilizator(Utilizator utilizator) {
    if (!existaUtilizator(utilizator.getId())) {
        utilizatori.add(utilizator);
    }
}

void Retea::adaugaEveniment(Eveniment eveniment) {
    if (!existaEveniment(eveniment.getId())) {
        evenimente.add(eveniment);
    }
}

void Retea::adaugaMesaj(Mesaj mesaj) {
    // check if users exists
    if (!existaUtilizator(mesaj.getId1()) || !existaUtilizator(mesaj.getId2())) {
        return;
    }

    if (!existaMesaj(mesaj.getId())) {
        mesaje.add(mesaj);
    }
}

void Retea::adaugaPrietenie(int id1, int id2) {
    // check if the users exist
    if (existaUtilizator(id1) && existaUtilizator(id2)) {
        // check if the users are already friends
        if (!prietenii.contains(Prietenie(id1, id2))) {
            prietenii.add(Prietenie(id1, id2));
        }
    }
}

void Retea::stergeUtilizator(int id) {
    if (existaUtilizator(id)) {
        utilizatori.remove(Utilizator(id, "", "", "", "", false));
    }

    // remove all the messages sent or received by the user
    for (int i = 0; i < mesaje.size(); i++) {
        if (mesaje.get(i).getId1() == id || mesaje.get(i).getId2() == id) {
            mesaje.remove(i);
            i--;
        }
    }

    // remove all the friendships with the user
    for (int i = 0; i < prietenii.size(); i++) {
        if (prietenii.get(i).getId1() == id || prietenii.get(i).getId2() == id) {
            prietenii.remove(i);
            i--;
        }
    }

}

void Retea::stergeEveniment(int id) {
    if (existaEveniment(id)) {
        evenimente.remove(Eveniment(id, "", "", ""));
    }
}

void Retea::stergeMesaj(int id) {
    if (existaMesaj(id)) {
        mesaje.remove(Mesaj(id, 0, 0, "", ""));
    }
}

void Retea::stergePrietenie(int id1, int id2) {
    if (prietenii.contains(Prietenie(id1, id2))) {
        prietenii.remove(Prietenie(id1, id2));
    }
}

void Retea::modificaUtilizator(Utilizator utilizator) {
    if (existaUtilizator(utilizator.getId())) {
        Utilizator utilizatorCurent = getUtilizator(utilizator.getId());

        if (utilizatorCurent.getId() == -1)
            return;

        utilizatorCurent.setNume(utilizator.getNume());
        utilizatorCurent.setPrenume(utilizator.getPrenume());
        utilizatorCurent.setEmail(utilizator.getEmail());
        utilizatorCurent.setParola(utilizator.getParola());
        utilizatorCurent.setStudent(utilizator.isStudent());
        utilizatori.remove(Utilizator(utilizator.getId(), "", "", "", "", false));
        utilizatori.add(utilizatorCurent);
    }
}

void Retea::modificaEveniment(Eveniment eveniment) {
    if (existaEveniment(eveniment.getId())) {
        Eveniment evenimentCurent = getEveniment(eveniment.getId());

        if (evenimentCurent.getId() == -1)
            return;

        evenimentCurent.setNume(eveniment.getNume());
        evenimentCurent.setLocatie(eveniment.getLocatie());
        evenimentCurent.setData(eveniment.getData());
        evenimente.remove(Eveniment(eveniment.getId(), "", "", ""));
        evenimente.add(evenimentCurent);
    }
}

Utilizator Retea::getUtilizator(int id) {
    std::vector<Utilizator> utilizatoriVector = utilizatori.to_vector();

    for (int i = 0; i < utilizatoriVector.size(); i++) {
        if (utilizatoriVector[i].getId() == id) {
            return utilizatoriVector[i];
        }
    }

    return Utilizator(-1, "", "", "", "", false);
}

Eveniment Retea::getEveniment(int id) {
    for (int i = 0; i < evenimente.size(); i++) {
        if (evenimente.get(i).getId() == id) {
            return evenimente.get(i);
        }
    }

    return Eveniment(-1, "", "", "");
}

Mesaj Retea::getMesaj(int id) {
    for (int i = 0; i < mesaje.size(); i++) {
        if (mesaje.get(i).getId() == id) {
            return mesaje.get(i);
        }
    }

    return Mesaj(-1, 0, 0, "", "");
}

Lista<Mesaj> Retea::getMesaje(int id1, int id2) {
    Lista<Mesaj> mesajeLista;
    for (int i = 0; i < mesaje.size(); i++) {
        if (mesaje.get(i).getId1() == id1 && mesaje.get(i).getId2() == id2) {
            mesajeLista.add(mesaje.get(i));
        }
        if (mesaje.get(i).getId1() == id2 && mesaje.get(i).getId2() == id1) {
            mesajeLista.add(mesaje.get(i));
        }
    }
    return mesajeLista;
}

Lista<Utilizator> Retea::getPrieteni(int id) {
    Lista<Utilizator> prieteniLista;
    for (int i = 0; i < prietenii.size(); i++) {
        if (prietenii.get(i).getId1() == id) {
            Utilizator utilizator = getUtilizator(prietenii.get(i).getId2());
            if (utilizator.getId() != -1) {
                prieteniLista.add(utilizator);
            }
        }
        if (prietenii.get(i).getId2() == id) {
            Utilizator utilizator = getUtilizator(prietenii.get(i).getId1());
            if (utilizator.getId() != -1) {
                prieteniLista.add(utilizator);
            }
        }
    }
    return prieteniLista;
}

Lista<Utilizator> Retea::getUtilizatori() {
    std::vector<Utilizator> vec = utilizatori.to_vector();

    Lista<Utilizator> utilizatoriLista;
    for (int i = 0; i < vec.size(); i++) {
        utilizatoriLista.add(vec[i]);
    }

    return utilizatoriLista;
}

Lista<Eveniment> Retea::getEvenimente() {
    return evenimente;
}

Lista<Mesaj> Retea::getMesaje() {
    return mesaje;
}

Lista<Prietenie> Retea::getPrietenii() {
    return prietenii;
}

