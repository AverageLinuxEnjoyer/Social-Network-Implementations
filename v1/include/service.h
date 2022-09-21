#ifndef SERVICE_H
#define SERVICE_H

#include "user.h"
#include "event.h"
#include "dictionary.h"
#include <string>

class Service {
public:
    Service(bool read_write_file = false);
    ~Service();

    // constructor de copiere si operator de atribuire sterse
    // service-ul nu trebuie copiat
    Service(const Service &other) = delete;
    Service &operator=(const Service &other) = delete;

    // adauga un user in lista de useri
    // username-ul trebuie sa fie unic
    // returneaza true daca userul a fost adaugat, false in caz contrar
    bool addUser(std::string username, int age, std::string email);

    // updateaza informatiile unui user
    // returneaza true daca userul a fost gasit si update-ul s-a efectuat, false in caz contrar
    bool updateUser(std::string username, std::string newUsername, int newAge, std::string newEmail);

    // sterge un user din lista de useri
    // returneaza true daca userul a fost sters
    // false daca userul nu exista
    bool removeUser(std::string username);

    // returneaza true daca friendship-ul a fost creat
    // false in cazul in care user1 sau user2 nu exista sau friendship-ul exista deja
    bool addFriendship(std::string username1, std::string username2);

    // returneaza true daca friendship-ul a fost sters
    // false in cazul in care friendship-ul nu exista
    bool removeFriendship(std::string username1, std::string username2);

    // trimite un mesaj catre user, returneaza true daca mesajul s-a trimis, false in caz contrar
    bool sendMessage(std::string sender_username, std::string receiver_username, std::string message);

    List<User*> getUsers();

    bool addEvent(std::string name, std::string location, std::string description, std::string date);

    bool updateEvent(std::string name, std::string newName, std::string newLocation, std::string newDescription, std::string newDate);

    bool removeEvent(std::string name);

    bool addInterestedUser(std::string event_name, std::string username);

    List<Event> getEvents();

private:
    Dictionary<std::string, User> users;
    List<Event> events;

    bool read_write_file;
};

#endif // USER_SERVICE_H
