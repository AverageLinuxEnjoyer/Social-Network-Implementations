#include "UserService.h"
#include <fstream>

UserService::UserService(string fileName)
{
    this->fileName = fileName;
    ifstream file(fileName);

    int id;
    string name;   
    string surname;
    string email;
    string password;

    while (file >> id >> name >> surname >> email >> password) {
        User user(id, name, surname, email, password);
        users.push_back(user);
    }    
}

UserService::~UserService()
{
    ofstream file(fileName);

    for (int i = 0; i < users.size(); i++) {
        file << users[i].getId() << " " << users[i].getName() << " " << users[i].getSurname() << " " << users[i].getEmail() << " " << users[i].getPassword() << endl;
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
