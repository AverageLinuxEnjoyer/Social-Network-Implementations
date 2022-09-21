#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
public:
    User() = default;
    User(int id, const std::string &username, const std::string &email);

    int getId() const;
    void setId(int id_);
    
    std::string getUsername() const;
    void setUsername(const std::string &username_);

    std::string getEmail() const;
    void setEmail(const std::string &email_);

    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& is, User& user);

    bool operator<(const User& user) const;
    bool operator>(const User& user) const;

private:
    int id;
    std::string username;
    std::string email;

};

#endif // USER_H
