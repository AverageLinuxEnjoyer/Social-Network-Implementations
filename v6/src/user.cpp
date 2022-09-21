#include "../include/user.h"

User::User(int id, const std::string &username, const std::string &email)
{
    this->id = id;
    this->username = username;
    this->email = email;
}

int User::getId() const 
{ 
    return id; 
}

void User::setId(int id_) 
{ 
    id = id_; 
}

std::string User::getUsername() const 
{ 
    return username; 
}

void User::setUsername(const std::string &username_) 
{ 
    username = username_; 
}

std::string User::getEmail() const 
{ 
    return email; 
}

void User::setEmail(const std::string &email_) 
{ 
    email = email_; 
}

bool User::operator<(const User& user) const {
    return username < user.username;
}

bool User::operator>(const User& user) const {  
    return username > user.username;
}


std::ostream& operator<<(std::ostream& os, const User& user) 
{
    os << "User(id=" << user.id << ", username=" << user.username << ", email=" << user.email << ")";
    return os;
}

std::istream& operator>>(std::istream& is, User& user) 
{
    std::cout << "id=";
    is >> user.id;

    std::cout << "username=";
    is >> user.username;

    std::cout << "email=";
    is >> user.email;

    return is;
}