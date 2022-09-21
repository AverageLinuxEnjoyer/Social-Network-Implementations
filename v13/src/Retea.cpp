#include "../include/Retea.h"
#include <algorithm>
#include <fstream>

Retea::Retea()
{
    load_from_file("retea.txt");
}

Retea::~Retea()
{
    save_to_file("retea.txt");
}

Retea::Retea(const Retea& retea)
{
    this->utilizatori = retea.utilizatori;
    this->prieteni = retea.prieteni;
}

Retea& Retea::operator=(const Retea& retea) {
    this->utilizatori = retea.utilizatori;
    this->prieteni = retea.prieteni;
    return *this;
}

void Retea::adauga_utilizator(Utilizator utilizator) {
    try {
        this->get_utilizator(utilizator.get_nume());
    } catch (const char* mesaj) {
        this->utilizatori.adauga_element(utilizator);
        return;
    }

    throw "A fost deja creat un utilizator cu acest nume!";
}

void Retea::modifica_utilizator(Utilizator utilizator_vechi, Utilizator nou) {
    Utilizator* utilizator = nullptr;

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i) == utilizator_vechi) {
            utilizator = &this->utilizatori.get_element(i);
            break;
        }
    }

    if (utilizator) {
        *utilizator = nou;
        
        for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
            if (this->prieteni.get_element(i).get_utilizator1() == utilizator_vechi) {
                this->prieteni.get_element(i).set_utilizator1(nou);
            }
            else if (this->prieteni.get_element(i).get_utilizator2() == utilizator_vechi) {
                this->prieteni.get_element(i).set_utilizator2(nou);
            }
        }
    }
    else {
        throw "Utilizatorul nu exista!";
    }
}

void Retea::modifica_utilizator(string nume, Utilizator utilizator) {
    Utilizator* utilizator_vechi = nullptr;

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i).get_nume() == nume) {
            utilizator_vechi = &this->utilizatori.get_element(i);
            break;
        }
    }

    if (utilizator_vechi) {
        *utilizator_vechi = utilizator;
    }
    else {
        throw "Utilizatorul nu exista!";
    }
}

void Retea::sterge_utilizator(Utilizator utilizator) {
    int index = -1;

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i) == utilizator) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        this->utilizatori.sterge_element(index);

        for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
            if (this->prieteni.get_element(i).get_utilizator1() == utilizator || this->prieteni.get_element(i).get_utilizator2() == utilizator) {
                this->prieteni.sterge_element(i);
                i--;
            }
        }
    }
    else {
        throw "Utilizatorul nu exista!";
    }
}

Lista<Utilizator> Retea::get_utilizatori() const {
    return this->utilizatori;
}

void Retea::sterge_utilizator(string nume) {
    int index = -1;

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i).get_nume() == nume) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        this->utilizatori.sterge_element(index);

        for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
            if (this->prieteni.get_element(i).get_utilizator1().get_nume() == nume || this->prieteni.get_element(i).get_utilizator2().get_nume() == nume) {
                this->prieteni.sterge_element(i);
                i--;
            }
        }
    }
    else {
        throw "Utilizatorul nu exista!";
    }
}

Utilizator Retea::get_utilizator(string nume) const {
    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i).get_nume() == nume) {
            return this->utilizatori.get_element(i);
        }
    }

    throw "Utilizatorul nu exista!";
}

void Retea::adauga_prietenie(Utilizator utilizator1, Utilizator utilizator2) {
    if (utilizator1 == utilizator2) {
        throw "Utilizatorul nu poate fi prieten cu el insusi!";
    }

    for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
        if ((this->prieteni.get_element(i).get_utilizator1() == utilizator1 && this->prieteni.get_element(i).get_utilizator2() == utilizator2) ||
            (this->prieteni.get_element(i).get_utilizator1() == utilizator2 && this->prieteni.get_element(i).get_utilizator2() == utilizator1)) {
            throw "Exista deja o prietenie intre acesti utilizatori!";
        }
    }

    bool u1gasit = false;
    bool u2gasit = false;
    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i) == utilizator1) {
            u1gasit = true;
        }
        if (this->utilizatori.get_element(i) == utilizator2) {
            u2gasit = true;
        }
    }

    if (!u1gasit && !u2gasit) {
        throw "Utilizatorii nu exista!";
    } else if (!u1gasit) {
        throw "Utilizatorul 1 nu exista!";
    } else if (!u2gasit) {
        throw "Utilizatorul 2 nu exista!";
    }


    this->prieteni.adauga_element(Prietenie(utilizator1, utilizator2));
}

void Retea::adauga_prietenie(string nume1, string nume2) {
    Utilizator utilizator1 = this->get_utilizator(nume1);
    Utilizator utilizator2 = this->get_utilizator(nume2);

    this->adauga_prietenie(utilizator1, utilizator2);
}

void Retea::sterge_prietenie(Utilizator utilizator1, Utilizator utilizator2) {
    for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
        if (this->prieteni.get_element(i).get_utilizator1() == utilizator1 && this->prieteni.get_element(i).get_utilizator2() == utilizator2) {
            this->prieteni.sterge_element(i);
            break;
        }
        else if (this->prieteni.get_element(i).get_utilizator1() == utilizator2 && this->prieteni.get_element(i).get_utilizator2() == utilizator1) {
            this->prieteni.sterge_element(i);
            break;
        }
    }

    throw "Unul din utilizatori nu exista sau acestia nu sunt prieteni!";
}

void Retea::sterge_prietenie(string nume1, string nume2) {
    Utilizator utilizator1 = this->get_utilizator(nume1);
    Utilizator utilizator2 = this->get_utilizator(nume2);

    this->sterge_prietenie(utilizator1, utilizator2);
}

Lista<Utilizator> Retea::get_prieteni(Utilizator utilizator) const {
    Lista<Utilizator> prieteni;

    for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
        if (this->prieteni.get_element(i).get_utilizator1() == utilizator) {
            prieteni.adauga_element(this->prieteni.get_element(i).get_utilizator2());
        }
        else if (this->prieteni.get_element(i).get_utilizator2() == utilizator) {
            prieteni.adauga_element(this->prieteni.get_element(i).get_utilizator1());
        }
    }

    if (prieteni.get_dimensiune() == 0) {
        throw "Acest utilizator nu are prieteni.";
    }

    return prieteni;
}

Lista<Utilizator> Retea::get_prieteni(string nume) const {
    Lista<Utilizator> prieteni;

    for (int i = 0; i < this->prieteni.get_dimensiune(); i++) {
        if (this->prieteni.get_element(i).get_utilizator1().get_nume() == nume || this->prieteni.get_element(i).get_utilizator2().get_nume() == nume) {
            if (this->prieteni.get_element(i).get_utilizator1().get_nume() == nume) {
                prieteni.adauga_element(this->prieteni.get_element(i).get_utilizator2());
            }
            else {
                prieteni.adauga_element(this->prieteni.get_element(i).get_utilizator1());
            }
        }
    }

    if (prieteni.get_dimensiune() == 0) {
        throw "Acest utilizator nu are prieteni.";
    }

    return prieteni;
}

Lista<Prietenie> Retea::get_toate_prieteniile() const {
    return this->prieteni;
}

void Retea::adauga_mesaj(Mesaj mesaj) {
    // check if users exist
    bool u1gasit = false;
    bool u2gasit = false;

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        if (this->utilizatori.get_element(i) == mesaj.get_expeditor()) {
            u1gasit = true;
        }
        if (this->utilizatori.get_element(i) == mesaj.get_destinatar()) {
            u2gasit = true;
        }
    }

    if (!u1gasit && !u2gasit) {
        throw "Utilizatorii nu exista!";
    } else if (!u1gasit) {
        throw "Utilizatorul 1 nu exista!";
    } else if (!u2gasit) {
        throw "Utilizatorul 2 nu exista!";
    }

    if (this->mesaje.contine_cheie(mesaj.get_expeditor())) {
        this->mesaje[mesaj.get_expeditor()].adauga_element(mesaj);
    }
    else {
        Lista<Mesaj> lista;
        lista.adauga_element(mesaj);
        this->mesaje.adaugare(mesaj.get_expeditor(), lista);
    }
}

vector<Mesaj> Retea::get_mesaje(Utilizator utilizator1, Utilizator utilizator2) {
    
    vector<Mesaj> mesaje_vec;

    for (int i = 0; i < this->mesaje[utilizator1].get_dimensiune(); i++) {
        if (this->mesaje[utilizator1].get_element(i).get_destinatar() == utilizator2) {
            mesaje_vec.push_back(this->mesaje[utilizator1].get_element(i));
        }
        if (this->mesaje[utilizator2].get_element(i).get_destinatar() == utilizator1) {
            mesaje_vec.push_back(this->mesaje[utilizator2].get_element(i));
        }
    }

    sort(mesaje_vec.begin(), mesaje_vec.end(), [](Mesaj m1, Mesaj m2) {
        return m1.get_nr() < m2.get_nr();
    });

    return mesaje_vec;
}

vector<Mesaj> Retea::get_mesaje(string nume1, string nume2) {
    Utilizator utilizator1 = this->get_utilizator(nume1);
    Utilizator utilizator2 = this->get_utilizator(nume2);

    return this->get_mesaje(utilizator1, utilizator2);
}

void Retea::load_from_file(string nume_fisier) {
    ifstream f(nume_fisier);

    if (!f.is_open()) {
        return;
    }
    
    string nume, prenume;
    Data data_nastere, data_inregistrare;

    while (f >> nume >> prenume >> data_nastere >> data_inregistrare) {
        Utilizator utilizator(nume, prenume, data_nastere);
        utilizator.set_data_inregistrarii(data_inregistrare);
        this->adauga_utilizator(utilizator);
    }
}

void Retea::save_to_file(string nume_fisier) {
    ofstream f(nume_fisier);

    if (!f.is_open()) {
        return;
    }

    for (int i = 0; i < this->utilizatori.get_dimensiune(); i++) {
        f << this->utilizatori.get_element(i).get_nume() << " " << this->utilizatori.get_element(i).get_prenume() << " " << this->utilizatori.get_element(i).get_data_nasterii() << " " << this->utilizatori.get_element(i).get_data_inregistrarii() << endl;
    }
}

