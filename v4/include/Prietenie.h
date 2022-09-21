#ifndef Prietenie_HPP
#define Prietenie_HPP

#include <vector>

class Utilizator;

class Prietenie {
public:
   /**
    * @brief  Constructor implicit
    */
    Prietenie();
    
   /**
    * @brief  Constructor de copiere
    * @param  &other: alta prietenie
    */
    Prietenie(const Prietenie &other);

   /**
    * @brief  Constructor cu parametrii 
    * @note   Creaza o prietenie intre 2 utilizatori
    * @param  *Utilizator1: primul utilizator
    * @param  *Utilizator2: al doilea utilizator
    */
    Prietenie(const Utilizator *Utilizator1, const Utilizator *Utilizator2);
    
   /**
    * @brief  Operator de atribuire (similar constructorului de copiere)
    * @param  &other: o alta prietenie
    * @retval returneaza prietenia (*this)
    */
    Prietenie& operator=(const Prietenie &other);

   /**
    * @brief  Destructor default (pentru ca nu face nimic special)
    */
    ~Prietenie() = default;

   /**
    * @brief  Getter utilizator 1
    * @retval primul utilizator
    */
    const Utilizator *getUtilizator1() const;

   /**
    * @brief  Getter utilizator 2
    * @retval al doilea utilizator
    */
    const Utilizator *getUtilizator2() const;

   /**
    * @brief  Operator de egalitate
    * @param  &other: o alta prietenie
    * @retval true daca utilziatorii celor 2 prietenii sunt aceeasi, false in caz contrar
    */
    bool operator==(const Prietenie &other) const;

   /**
    * @brief  Operator de inegalitate
    * @param  &other: o alta prietenie
    * @retval true daca utilziatorii celor 2 prietenii sunt diferiti, false in caz contrar
    */
    bool operator!=(const Prietenie &other) const;

private:
    const Utilizator *Utilizator1;
    const Utilizator *Utilizator2;
};

#endif // Prietenie_HPP
