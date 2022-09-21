#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "service.h"
#include "Utilizator.h"
#include "Mesaj.h"

class ServiceUtilizatori : public Service<Utilizator> {
public:
    ServiceUtilizatori();

    void adaugareMesaj(int id1, int id2, std::string message);
    Lista<Mesaj> getMesage(int id1, int id2);
    void stergereMesaje(int id1, int id2);

    void adaugarePrieten(int id1, int id2);
    void stergerePrieten(int id1, int id2);
    Lista<Utilizator> getPrieteni(int id1);
    void stergerePrieteni(int id1);

private:
    Lista<Mesaj> messages;
};

#endif // USER_SERVICE_H
