#include "../include/UserService.h"
#include <fstream>

UserService::UserService(std::string fileName)
{
    this->fileName = fileName;
    std::ifstream file(fileName);

    int id;
    std::string name;   
    std::string surname;
    std::string email;
    std::string password;

    while (file >> id >> name >> surname >> email >> password) {
        User user(id, name, surname, email, password);
        users.push_back(user);
    }    
}

UserService::~UserService()
{
    std::ofstream file(fileName);

    for (int i = 0; i < users.size(); i++) {
        file << users[i].getId() << " " << users[i].getName() << " " << users[i].getSurname() << " " << users[i].getEmail() << " " << users[i].getPassword() << std::endl;
    }
}

List<User> UserService::getUsers() {
    return users;
}

User UserService::getUser(int id) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == id) {
            return users[i];
        }
    }
    
    return User();
}

void UserService::addUser(const User &user) {
    users.push_back(user);
}

void UserService::modifyUser(int id, const User &user) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == id) {
            users[i] = user;
        }
    }
}

void UserService::removeUser(const User &user) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == user.getId()) {
            users.erase(i);
        }
    }
}
