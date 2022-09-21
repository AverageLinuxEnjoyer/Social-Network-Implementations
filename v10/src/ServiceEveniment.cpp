#include "../include/ServiceEveniment.h"

ServiceEvenimente::ServiceEvenimente()
{
    this->multime_ordonata.inserare(Eveniment(1, "Untold", 2000, "Cluj"));
    this->multime_ordonata.inserare(Eveniment(2, "ElectricCastle", 800, "Cluj"));
    this->multime_ordonata.inserare(Eveniment(3, "MeciFotbal", 300, "Bucuresti"));
    this->multime_ordonata.inserare(Eveniment(4, "MeciBasket", 230, "Timisoara"));
    this->multime_ordonata.inserare(Eveniment(5, "StandUp", 120, "Mures"));
    this->multime_ordonata.inserare(Eveniment(6, "MeciTenis", 500, "Brasov"));
    this->multime_ordonata.inserare(Eveniment(7, "Film", 600, "Constanta"));
    this->multime_ordonata.inserare(Eveniment(8, "Teatru", 200, "Brasov"));
    this->multime_ordonata.inserare(Eveniment(9, "Festival", 300, "Bucuresti"));
    this->multime_ordonata.inserare(Eveniment(10, "AltMeciFotbal", 230, "Timisoara"));
}

void ServiceEvenimente::adaugareParticipant(int id_eveniment, int id_user) {
    Eveniment event = this->get(id_eveniment);
    event.adaugareParticipant(id_user);
    this->modificare(event.getId(), event);    
}

void ServiceEvenimente::stergereParticipant(int id_eveniment, int id_user) {
    Eveniment event = this->get(id_eveniment);
    event.stergereParticipant(id_user);
    this->modificare(event.getId(), event);
}

Lista<int> ServiceEvenimente::getParticipanti(int id_eveniment) 
{
    Eveniment event = this->get(id_eveniment);
    
    return event.getParticipanti();
}
