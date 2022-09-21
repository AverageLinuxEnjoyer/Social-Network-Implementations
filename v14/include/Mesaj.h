#ifndef MESAJ_H
#define MESAJ_H

#include <string>
#include <iostream>

class Mesaj {
private:
    std::string nume_expeditor;
    std::string nume_destinatar;
    std::string content_mesaj;

public:
    Mesaj();
    Mesaj(std::string nume_expeditor, std::string nume_destinatar, std::string content_mesaj);
    ~Mesaj();
    std::string getNumeExpeditor();
    std::string getNumeDestinatar();
    std::string getContentMesaj();
    void setNumeExpeditor(std::string nume_expeditor);
    void setNumeDestinatar(std::string nume_destinatar);
    void setContentMesaj(std::string content_mesaj);
    bool operator==(const Mesaj& other);

    friend std::ostream& operator<<(std::ostream& os, const Mesaj& m);
    friend std::istream& operator>>(std::istream& is, Mesaj& m);
};

#endif // MESAJ_H
