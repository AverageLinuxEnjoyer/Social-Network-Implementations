#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "list.h"
#include "friendship.h"
#include "message.h"

class User {
public:
    User() = default;
    User(std::string username, int age, std::string email);

    std::string getUsername() const;
    void setUsername(const std::string &username_);

    int getAge() const;
    void setAge(int age_);

    std::string getEmail() const;
    void setEmail(const std::string &email_);

    std::vector<Friendship> getFriends() const;
    void addFriend(const User &user);
    void removeFriend(const User &user);

    // Trimite un mesaj catre user, returneaza true daca user e prieten si mesajul s-a trimis, false in caz contrar
    void sendMessage(User& user, const std::string& message);
    std::vector<Message> getMessages() const;

    bool operator==(const User &other) const;
    bool operator!=(const User &other) const;

    bool operator<(const User &other) const;
    bool operator>(const User &other) const;

private:
    std::string username;
    int age;
    std::string email;
    std::vector<Friendship> friends;
    std::vector<Message> messages;
};

#endif // USER_HPP
