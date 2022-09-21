#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    User();
    User(int id, const string &name, const string &surname, const string &email, const string &password);
    User(const User &user);

    User& operator=(const User &user);

    string getName() const;
    string getSurname() const;
    string getEmail() const;
    string getPassword() const;
    int getId() const;

    void setName(const string &name);
    void setSurname(const string &surname);
    void setEmail(const string &email);
    void setPassword(const string &password);
    void setId(const int &id);
    
    bool operator==(const User &user) const;
    bool operator!=(const User &user) const;
    bool operator<(const User &user) const;
    bool operator>(const User &user) const;
    
    bool isValid() const;

private:
    bool isValidEmail(const string &email) const;
    bool isValidPassword(const string &password) const;

    string name;
    string surname;
    string email;
    string password;
    int id = -1;
};

#endif // USER_H
