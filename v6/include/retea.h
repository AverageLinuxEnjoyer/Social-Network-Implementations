#ifndef RETEA_H
#define RETEA_H

#include "list.h"
#include "multime_ordonata.h"
#include "prietenie.h"
#include "user.h"
#include "mesaj.h"

class Retea {
public:
    Retea();
    ~Retea();

    void addUser(const User &user);
    void editUser(int id, const User &user);
    void removeUser(int id);
    void addPrietenie(int id1, int id2);
    void removePrietenie(int id1, int id2);
    void addMesaj(int id1, int id2, const std::string &text);
    void removeMesaje(int id1, int id2);

    List<User> getUsers() const;
    List<Prietenie> getPrietenii() const;
    List<Mesaj> getMesaje(int id1, int id2);
    User getUser(int id) const;

private:
    void createUsers();
    void createPrietenii();
    void createMesaje();

    MultimeOrdonata<User> users;
    List<Prietenie> prieteni;
    List<Mesaj> mesaje;
};

#endif // RETEA_H
