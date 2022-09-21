#include "User.h"

User::User()
{
    id = -1;
}

User::User(int id, const string &name, const string &surname, const string &email, const string &password)
    : name(name),
      surname(surname),
      email(email),
      password(password),
      id(id)
{
    
}

User::User(const User &user)
    : name(user.name),
      surname(user.surname),
      email(user.email),
      password(user.password),
      id(user.id)
{
    
}


User& User::operator=(const User &user)
{
    name = user.name;
    surname = user.surname;
    email = user.email;
    password = user.password;
    id = user.id;
    
    return *this;
}

string User::getName() const
{
    return name;
}

string User::getSurname() const
{
    return surname;
}

string User::getEmail() const
{
    return email;
}

string User::getPassword() const
{
    return password;
}

int User::getId() const
{
    return id;
}

void User::setName(const string &name)
{
    this->name = name;
}

void User::setSurname(const string &surname)
{
    this->surname = surname;
}

void User::setEmail(const string &email)
{
    this->email = email;
}

void User::setPassword(const string &password)
{
    this->password = password;
}

void User::setId(const int &id)
{
    this->id = id;
}

bool User::operator==(const User &user) const
{
    return (getEmail() == user.getEmail() &&
            getPassword() == user.getPassword());
}

bool User::operator!=(const User &user) const
{
    return (getEmail() != user.getEmail() ||
            getPassword() != user.getPassword());
}

bool User::operator<(const User &user) const
{
    return (getId() < user.getId());
}

bool User::operator>(const User &user) const
{
    return (getId() > user.getId());
}

bool User::isValid() const
{
    return isValidEmail(getEmail()) &&
           isValidPassword(getPassword());
}

bool User::isValidEmail(const string &email) const
{
    return (email.find('@') != string::npos &&
            email.find('.') != string::npos);
}


bool User::isValidPassword(const string &password) const {
    if (password.size() < 6) {
        return false;
    }
    
    int numOfDigits = 0;
    int numOfLowerCase = 0;
    int numOfUpperCase = 0;
    
    for (char c : password) {
        if (isdigit(c)) {
            numOfDigits++;
        } else if (islower(c)) {
            numOfLowerCase++;
        } else if (isupper(c)) {
            numOfUpperCase++;
        }
    }
    
    return (numOfDigits > 0 &&
            numOfLowerCase > 0 &&
            numOfUpperCase > 0);
}

