#include "../include/retea.h"

class UserInterface {
public:
    UserInterface(Retea &user_service);
    ~UserInterface() = default;

    void run();

    void meniu_useri();
    void meniu_evenimente();

    void afisiare_useri();
    void meniu_adaugare_utilizator();
    void meniu_update_utilizator();
    void meniu_stergere_utilizator();
    void meniu_adaugare_prietenie();
    void meniu_stergere_prietenie();
    void afisare_prietenii();
    void meniu_trimitere_mesaj();
    void afisare_mesaje();

    void afisare_meniu_evenimente();
    void meniu_adaugare_eveniment();
    void meniu_update_eveniment();
    void meniu_stergere_eveniment();
    void meniu_adaugare_utilizator_interesat();
    void afisare_utilizatori_interesati();

private:
    Retea& userService;
};