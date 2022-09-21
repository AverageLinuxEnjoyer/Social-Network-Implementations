#include "../include/User.h"

User::User()
{
    id = -1;
}

User::User(int id, const std::string &name, const std::string &surname, const std::string &email, const std::string &password)
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

std::string User::getName() const
{
    return name;
}

std::string User::getSurname() const
{
    return surname;
}

std::string User::getEmail() const
{
    return email;
}

std::string User::getPassword() const
{
    return password;
}

int User::getId() const
{
    return id;
}

void User::setName(const std::string &name)
{
    this->name = name;
}

void User::setSurname(const std::string &surname)
{
    this->surname = surname;
}

void User::setEmail(const std::string &email)
{
    this->email = email;
}

void User::setPassword(const std::string &password)
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

bool User::isValidEmail(const std::string &email) const
{
    return (email.find('@') != std::string::npos &&
            email.find('.') != std::string::npos);
}


bool User::isValidPassword(const std::string &password) const {
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

