#ifndef Eveniment_H
#define Eveniment_H

#include <string>
#include "Lista.h"
#include "Utilizator.h"

class Eveniment {
public:
   /**
    * @brief Constructor implicit
    */
    Eveniment();

   /**
    * @brief Constructor cu parametrii
    */
    Eveniment(std::string nume, std::string locatie, std::string descriere, std::string data);

   /**
    * @brief Getter nume
    * @retval numele evenimenului
    */
    std::string getNume() const;

   /**
    * @brief  Setter nume
    * @param  &nume_: noul nume
    */
    void setNume(const std::string &nume_);

   /**
    * @brief  Getter locatie
    * @retval locatia evenimentului
    */
    std::string getLocatie() const;

   /**
    * @brief  Setter locatie
    * @param  &locatie_: noua locatie
    */
    void setLocatie(const std::string &locatie_);

   /**
    * @brief  Getter descriere
    * @retval descrierea evenimentului
    */
    std::string getDescriere() const;

   /**
    * @brief  Setter descreire
    * @param  &descriere_: noua descriere
    */
    void setDescriere(const std::string &descriere_);

   /**
    * @brief  Getter data
    * @retval data evenimentului
    */
    std::string getData() const;

   /**
    * @brief  Setter data
    * @param  &data_: noua data
    */
    void setData(const std::string &data_);

   /**
    * @brief  Getter lista de utilizatori interesat in eveniment
    * @retval lista cu utilizatorii interesati
    */
    const Lista<Utilizator*>& getUtilizatoriInteresati() const;

   /**
    * @brief  Adauga un utilizator in lista utilizatorilor interesati
    * @param  Utilizator: utilizatorul adaugat
    */
    void addUtilizatorInteresat(Utilizator* Utilizator);

private:
    std::string nume;
    std::string locatie;
    std::string descriere;
    std::string data;
    Lista<Utilizator*> utilizatori_interesati;
};

#endif // Eveniment_H
