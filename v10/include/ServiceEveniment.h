#ifndef EVENT_SERVICE_H
#define EVENT_SERVICE_H

#include "service.h"
#include "Eveniment.h"

class ServiceEvenimente : public Service<Eveniment> {
public:
    ServiceEvenimente();

    void adaugareParticipant(int id_eveniment, int id_user);
    void stergereParticipant(int id_eveniment, int id_user);
    Lista<int> getParticipanti(int id_eveniment);
};

#endif // EVENT_SERVICE_H
