#ifndef SERVICE_H
#define SERVICE_H

#include "Utilizator.h"
#include "Eveniment.h"
#include "MultimeOrdonata.h"
#include <string>

class Service {
public:
    Service(bool read_write_file = false);
    ~Service();

    // constructor de copiere si operator de atribuire sterse
    // service-ul nu trebuie copiat
    Service(const Service &other) = delete;
    Service &operator=(const Service &other) = delete;

   /**
    * @brief  Adauga un nou utilizator
    * @note   
    * @param  nume_utilizator: numele utilizatorului, trebuie sa fie unic
    * @param  varsta: varsta utilizatorului
    * @param  email: email-ul utilizatorului
    * @retval true daca a fost adaugat cu succes, false in caz contrar
    */
    bool addUtilizator(std::string nume_utilizator, int varsta, std::string email);

   /**
    * @brief  Modifica un utilizator existent
    * @note   
    * @param  nume_utilizator: numele utilizatorului, trebuie sa fie unic
    * @param  nume_utilizator_nou: numele nou (trebuie sa nu existe deja)
    * @param  varsta_noua: varsta noua
    * @param  email_nou: email-ul nou
    * @retval true daca a fost modificat cu succes, false in caz contrar
    */
    bool updateUtilizator(std::string nume_utilizator, std::string nume_utilizator_nou, int varsta_noua, std::string email_nou);

   /**
    * @brief  Sterge un utilizator
    * @note   
    * @param  nume_utilizator: numele utilizatorului sters
    * @retval true daca a fost sters, false in caz contrar (daca utilizatorul nu exista)
    */
    bool removeUtilizator(std::string nume_utilizator);

   /**
    * @brief  Creeaza o relatie de prietenie intre doi utilizatori
    * @note   
    * @param  nume_utilizator1: numele unuia dintre utilizatori
    * @param  nume_utilizator2: numele celuilalt utilizator
    * @retval true daca prietenie a fost creata, false in caz contrar (daca unul din utilziatori nu exista, sau prietenia exista deja)
    */
    bool addPrietenie(std::string nume_utilizator1, std::string nume_utilizator2);

   /**
    * @brief  Sterge relatia de prietenie dintre 2 utilizatori
    * @note   
    * @param  nume_utilizator1: numele unuia dintre utilizatori
    * @param  nume_utilizator2: numele celuilalt
    * @retval true daca prietenia a fost stearga, false in caz contrar (daca unul din utilizatori sau prietenia nu exista)
    */
    bool removePrietenie(std::string nume_utilizator1, std::string nume_utilizator2);

   /**
    * @brief  Trimite un mesaj de la un utilizator la altul
    * @note   
    * @param  expeditor_nume_utilizator: numele utilizatorului expeditor
    * @param  destinatar_nume_utilizator: numele utilizatorului destinatar
    * @param  Mesaj: continutul mesajului
    * @retval returneaza true daca mesajul s-a trimis, false in caz contrar
    */
    bool trimiteMesaj(std::string expeditor_nume_utilizator, std::string destinatar_nume_utilizator, std::string Mesaj);

   /**
    * @brief  Getter utilizatori
    * @retval returneaza lista cu utilizatorii
    */
    Lista<Utilizator*> getUtilizatori();

   /**
    * @brief  Creeaza un eveniment
    * @note   
    * @param  name: nume eveniment (trebuie sa fie unic)
    * @param  location: locatie eveniment
    * @param  description: descriere eveniment
    * @param  date: data eveniment
    * @retval true daca evneimentul a fost adaugat, false in caz contrar (daca exista deja)
    */
    bool addEveniment(std::string name, std::string location, std::string description, std::string date);

   /**
    * @brief  Modifica un eveniment existent
    * @note   
    * @param  name: nume eveniment (trebuie sa fie unic)
    * @param  newName: noul nume al evenimentului (trebuie sa nu existe deja)
    * @param  newLocation: locatia noua
    * @param  newDescription: descrierea noua
    * @param  newDate: data noua
    * @retval true daca evenimentul a fost modificat, false in caz contrar (daca nu exista, sau daca numele nou exista deja)
    */
    bool updateEveniment(std::string name, std::string newName, std::string newLocation, std::string newDescription, std::string newDate);

   /**
    * @brief  Sterge un eveniment existent
    * @param  name: numele evenimentului
    * @retval true daca evenimentul a fost sters, false in caz contrar (daca nu exista)
    */
    bool removeEveniment(std::string name);

   /**
    * @brief  Adauga un utilizator ca fiind interesat intr-un eveniment
    * @note   
    * @param  nume_eveniment: numele evenimentuului 
    * @param  nume_utilizator: numele utilizatorului
    * @retval true daca utilizatorul a fost adaugat cu succes, false in caz contrar (daca evenimentul sau utilizatorul nu exista, sau daca era deja adaugat)
    */
    bool addInterestedUtilizator(std::string nume_eveniment, std::string nume_utilizator);

   /**
    * @brief  Getter lista de evenimente
    * @retval lista evenimentelor
    */
    Lista<Eveniment> getEvenimente();

private:
    // functie ajutatoare pentru citirea din fisiere
    void readUtilizatorsFromFile();

    MultimeOrdonata<Utilizator> utilizatori;
    Lista<Eveniment> Eveniments;

    bool read_write_file;
};

#endif // Utilizator_SERVICE_H
