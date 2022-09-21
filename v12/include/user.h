#ifndef USER_H
#define USER_H

#include <iostream>
#include "list.h"

class User {
public:
    User();
    User(const User& other) = default;
    User(int code, std::string name, int age, std::string gender);
    ~User() = default;

    int getCode() const;
    void setCode(int code_);

    std::string getName() const;
    void setName(const std::string &name_);

    int getAge() const;
    void setAge(int age_);

    std::string getGender() const;
    void setGender(const std::string &gender_);

    bool operator==(const User& other) const;
    bool operator<(const User& other) const;
    bool operator>(const User& other) const;

    List<int> getFriends() const;
    void setFriends(const List<int> &friends_);
    void addFriend(int friend_);
    void removeFriend(int friend_);

    bool operator!=(const User& other) const;

private:
    int code;
    std::string name;
    int age;
    std::string gender;
    List<int> friends;
};

#endif // USER_H
