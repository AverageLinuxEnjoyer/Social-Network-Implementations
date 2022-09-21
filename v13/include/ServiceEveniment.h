#ifndef SERVICEEVENIMENT_H
#define SERVICEEVENIMENT_H

#include "Lista.h"
#include "Utilizator.h"
#include "Eveniment.h"

class ServiceEveniment {
public:
    ServiceEveniment();
    ~ServiceEveniment();
    ServiceEveniment(const ServiceEveniment& service);
    ServiceEveniment& operator=(const ServiceEveniment& service);
    void adauga_eveniment(Eveniment eveniment);
    void modifica_eveniment(Eveniment eveniment_vechi, Eveniment nou);
    void modifica_eveniment (string titlu, Eveniment nou);
    void sterge_eveniment(Eveniment eveniment);
    void sterge_eveniment(string titlu);
    void adauga_utilizator_participant(Eveniment eveniment, Utilizator utilizator);
    Eveniment get_eveniment(string titlu);
    Lista<Eveniment> get_evenimente() const;
    Lista<Utilizator> get_participanti(Eveniment eveniment) const;
    Lista<Utilizator> get_participanti_evenimente(string titlu) const;

    void load_from_file(string file_name);
    void save_to_file(string file_name);

private:
    Lista<Eveniment> evenimente;
};

#endif // SERVICEEVENIMENT_H
