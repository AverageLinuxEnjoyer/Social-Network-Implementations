#ifndef USER_H
#define USER_H

#include <string>
#include "Message.h"
#include "List.h"
using namespace std;

class User {
public:
    User();
    User(const User &user);
    User(int id, string name, string email, string password, string phone, string city, string state);
    ~User();

    int getId() const;
    void setId(int id_);

    string getName() const;
    void setName(const string &name_);

    string getEmail() const;
    void setEmail(const string &email_);

    string getPassword() const;
    void setPassword(const string &password_);

    string getPhone() const;
    void setPhone(const string &phone_);

    string getCity() const;
    void setCity(const string &city_);

    string getState() const;
    void setState(const string &state_);

    List<int> getFriends() const;
    void setFriends(const List<int> &friends_);
    void addFriend(int friendId);
    void removeFriend(int friendId);

    List<int> getEvents() const;
    void setEvents(const List<int> &events_);
    void addEvent(int eventId);
    void removeEvent(int eventId);

    bool operator<(const User &rhs) const;
    bool operator>(const User &rhs) const;
    bool operator==(const User &rhs) const;
    bool operator!=(const User &rhs) const;
    
private:
    int id;
    string name;
    string email;
    string password;
    string phone;
    string city;
    string state;
    List<int> friends;
    List<int> events;
};

#endif // USER_H
