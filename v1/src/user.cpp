#include "../include/user.h"

User::User(std::string username, int age, std::string email)
    : username(username),
      age(age),
      email(email)
{}

std::string User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username_) {
    username = username_;
}

int User::getAge() const {
    return age;
}

void User::setAge(int age_) {
    age = age_;
}

std::string User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email_) {
    email = email_;
}

std::vector<Friendship> User::getFriends() const { return friends; }

void User::addFriend(const User &user) {
    friends.push_back(Friendship(this, &user));
}

void User::removeFriend(const User &user) {
    for (int i = 0; i < friends.size(); i++) {
        if (friends[i].getUser1() == this && friends[i].getUser2() == &user) {
            friends.erase(friends.begin() + i);
            return;
        }
    }
}

void User::sendMessage(User& user, const std::string& content) {
    Message message = {
        .sender = this,
        .receiver = &user,
        .content = content
    };

    this->messages.push_back(message);
    user.messages.push_back(message);
}

std::vector<Message> User::getMessages() const {
    return messages;
}

bool User::operator==(const User &other) const {
    return username == other.username && age == other.age && email == other.email && friends == other.friends;
}

bool User::operator!=(const User &other) const {
    return !(*this == other);
}

bool User::operator<(const User &other) const {
    return username < other.username;
}

bool User::operator>(const User &other) const {
    return username > other.username;
}
