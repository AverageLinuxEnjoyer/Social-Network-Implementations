#include "../include/user.h"

User::User()
{
    this->code = -1;
    this->name = "";
    this->age = -1;
    this->gender = "";
}

User::User(int code, std::string name, int age, std::string gender)
{
    this->code = code;
    this->name = name;
    this->age = age;
    this->gender = gender;
}

int User::getCode() const { return code; }

void User::setCode(int code_) { code = code_; }

std::string User::getName() const { return name; }

void User::setName(const std::string &name_) { name = name_; }

int User::getAge() const { return age; }

void User::setAge(int age_) { age = age_; }

std::string User::getGender() const { return gender; }

void User::setGender(const std::string &gender_) { gender = gender_; }

bool User::operator==(const User& other) const { return this->code == other.code; }

bool User::operator<(const User& other) const { return this->name < other.name; }

bool User::operator>(const User& other) const { return this->name > other.name; }

List<int> User::getFriends() const { return friends; }

void User::setFriends(const List<int> &friends_) { friends = friends_; }

void User::addFriend(int friend_) { friends.push_back(friend_); }

void User::removeFriend(int friend_) {
    for (int i = 0; i < friends.getSize(); i++) {
        if (friends[i] == friend_) {
            friends.erase(i);
            break;
        }
    }
}

bool User::operator!=(const User& other) const { return !(*this == other); }
