#ifndef Mesaj_H
#define Mesaj_H

#include <string>

class Utilizator;

class Mesaj {
public:
   /**
    * @brief  Constructor implicit
    */
    Mesaj();

   /**
    * @brief  Constructor cu parametrii
    */
    Mesaj(Utilizator* expeditor, Utilizator* destinatar, std::string continut);

   /**
    * @brief  Getter expeditor
    * @retval expeditorul mesajului
    */
    const Utilizator* getExpeditor() const;

   /**
    * @brief  Setter expeditor
    * @param  expeditor: noul expeditor al mesajului
    */
    void setExpeditor(Utilizator* expeditor);

   /**
    * @brief  Getter destinatar
    * @retval destinatarul mesajului
    */
    const Utilizator* getDestinatar() const;

   /**
    * @brief  Setter destinatar
    * @param  destinatar: noul destinatar al mesajului
    */
    void setDestinatar(Utilizator* destinatar);

   /**
    * @brief  Getter continut
    * @retval continutul mesajului
    */
    std::string getContinut() const;

   /**
    * @brief  Setter continut
    * @param  &continut_: noul continut al mesajului
    */
    void setContinut(const std::string &continut_);

private:
    const Utilizator* expeditor;
    const Utilizator* destinatar;

    std::string continut;
};

#endif // Mesaj_H
