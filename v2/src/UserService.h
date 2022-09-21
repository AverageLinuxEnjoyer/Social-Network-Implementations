#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "User.h"
#include "List.h"
using namespace std;

class UserService {
public:
    UserService(string fileName);
    ~UserService();

    List<User> getUsers();
    User getUser(int id);
    void addUser(const User &user);
    void modifyUser(int id, const User &user);
    void removeUser(const User &user);

private:
    List<User> users;
    string fileName;
};

#endif // USERSERVICE_H
