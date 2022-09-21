#include "../include/Service.h"

// clasa Singleton UI
class UI {
public:
    ~UI() = default;

   /**
    * @brief  Metoda statica care returneaza singurul obiect de tip UI
    * @retval singura instanta a clasei UI
    */
    static UI& get_obiect();

    void run();

private:
   /**
    * @brief  Constructor fara parametrii
    * @note   facut privat, pentru a nu putea crea obiecte de tip UI din exterior, astfel permitand accesul la obiectul unic doar prin metoda statica get_obiect()
    */
    UI();

    // meniuri utilizator si eveniment
    void meniu_utilizator();
    void meniu_eveniment();

    // meniuri utilizator
    void afisare_utilizatori();
    void adaugare_utilizator();
    void modificare_utilizator();
    void stergere_utilizator();
    void adaugare_prietenie();
    void stergere_prietenie();
    void trimitere_mesaj();
    void afisare_mesaje();

    // meniuri eveniment
    void afisare_evenimente();
    void adaugare_eveniment();
    void modificare_eveniment();
    void stergere_eveniment();
    void adaugare_utilizator_interesat_in_eveniment();
    void afisare_utilizatori_interesati();

    Service service;
};