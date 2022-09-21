#ifndef RETEA_H
#define RETEA_H

#include <vector>
#include "../include/Utilizator.h"
#include "../include/Prietenie.h"
#include "../include/Lista.h"
#include "../include/Dictionar.h"
#include "../include/Mesaj.h"

class Retea {
public:
    Retea();
    ~Retea();
    Retea(const Retea& retea);
    Retea& operator=(const Retea& retea);
    void adauga_utilizator(Utilizator utilizator);
    void modifica_utilizator(Utilizator utilizator_vechi, Utilizator nou);
    void modifica_utilizator(string nume, Utilizator utilizator);
    void sterge_utilizator(Utilizator utilizator);
    Lista<Utilizator> get_utilizatori() const;
    void sterge_utilizator(string nume);
    Utilizator get_utilizator(string nume) const;
    void adauga_prietenie(Utilizator utilizator1, Utilizator utilizator2);
    void adauga_prietenie(string nume1, string nume2);
    void sterge_prietenie(Utilizator utilizator1, Utilizator utilizator2);
    void sterge_prietenie(string nume1, string nume2);
    Lista<Utilizator> get_prieteni(Utilizator utilizator) const;
    Lista<Utilizator> get_prieteni(string nume) const;
    Lista<Prietenie> get_toate_prieteniile() const;
    

    void adauga_mesaj(Mesaj mesaj);
    vector<Mesaj> get_mesaje(Utilizator utilizator1, Utilizator utilizator2);
    vector<Mesaj> get_mesaje(string nume1, string nume2); 

    void load_from_file(string nume_fisier);
    void save_to_file(string nume_fisier);

private:
    Lista<Utilizator> utilizatori;
    Lista<Prietenie> prieteni;
    Dictionar<Utilizator, Lista<Mesaj>> mesaje;
};

#endif // RETEA_H
