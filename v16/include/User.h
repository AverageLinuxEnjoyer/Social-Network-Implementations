#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User();
    User(int id, const std::string &name, const std::string &surname, const std::string &email, const std::string &password);
    User(const User &user);

    User& operator=(const User &user);

    std::string getName() const;
    std::string getSurname() const;
    std::string getEmail() const;
    std::string getPassword() const;
    int getId() const;

    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setEmail(const std::string &email);
    void setPassword(const std::string &password);
    void setId(const int &id);
    
    bool operator==(const User &user) const;
    bool operator!=(const User &user) const;
    bool operator<(const User &user) const;
    bool operator>(const User &user) const;
    
    bool isValid() const;

private:
    bool isValidEmail(const std::string &email) const;
    bool isValidPassword(const std::string &password) const;

    std::string name;
    std::string surname;
    std::string email;
    std::string password;
    int id = -1;
};

#endif // USER_H
