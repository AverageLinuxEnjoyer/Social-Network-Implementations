#include "../include/ServiceEveniment.h"
#include <fstream>

ServiceEveniment::ServiceEveniment()
{
    load_from_file("evenimente.txt");
}

ServiceEveniment::~ServiceEveniment()
{
    save_to_file("evenimente.txt");
}

ServiceEveniment::ServiceEveniment(const ServiceEveniment& service)
{
    this->evenimente = service.evenimente;
}

ServiceEveniment& ServiceEveniment::operator=(const ServiceEveniment& service) {
    this->evenimente = service.evenimente;

    return *this;
}

void ServiceEveniment::adauga_eveniment(Eveniment eveniment) {
    this->evenimente.adauga_element(eveniment);
}

void ServiceEveniment::modifica_eveniment(Eveniment eveniment_vechi, Eveniment nou) {
    Eveniment* eveniment = nullptr;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i) == eveniment_vechi) {
            eveniment = &this->evenimente.get_element(i);
            break;
        }
    }

    if (eveniment) {
        *eveniment = nou;
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

void ServiceEveniment::sterge_eveniment(Eveniment eveniment) {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i) == eveniment) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        this->evenimente.sterge_element(index);
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

void ServiceEveniment::sterge_eveniment(string titlu) {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i).get_titlu() == titlu) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        this->evenimente.sterge_element(index);
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

void ServiceEveniment::adauga_utilizator_participant(Eveniment eveniment, Utilizator utilizator) {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i) == eveniment) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        this->evenimente.get_element(index).adauga_utilizator_participant(utilizator);
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

Eveniment ServiceEveniment::get_eveniment(string titlu) {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i).get_titlu() == titlu) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        return this->evenimente.get_element(index);
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

Lista<Eveniment> ServiceEveniment::get_evenimente() const {
    return this->evenimente;
}

Lista<Utilizator> ServiceEveniment::get_participanti(Eveniment eveniment) const {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i) == eveniment) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        return this->evenimente.get_element(index).get_utilizatori_participanti();
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

Lista<Utilizator> ServiceEveniment::get_participanti_evenimente(string titlu) const {
    int index = -1;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        if (this->evenimente.get_element(i).get_titlu() == titlu) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        return this->evenimente.get_element(index).get_utilizatori_participanti();
    }
    else {
        throw "Evenimentul nu exista!";
    }
}

void ServiceEveniment::load_from_file(string file_name) {   
    ifstream file(file_name);

    if (!file.is_open())
        return;

    string titlu, descriere, locatie;
    Data data;

    while (file >> titlu >> descriere >> data >> locatie) {
        Eveniment eveniment(titlu, descriere, data, locatie);
        this->evenimente.adauga_element(eveniment);
    }

}

void ServiceEveniment::save_to_file(string file_name) {
    ofstream file(file_name);

    if (!file.is_open())
        return;

    for (int i = 0; i < this->evenimente.get_dimensiune(); i++) {
        file << this->evenimente.get_element(i).get_titlu() << " " << this->evenimente.get_element(i).get_descriere() << " " << this->evenimente.get_element(i).get_data() << " " << this->evenimente.get_element(i).get_locatie() << endl;
    }
}


