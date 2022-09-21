#include "../include/service.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Service::Service(bool read_write_file)
    : read_write_file(read_write_file)
{
    if (read_write_file) {
        // citeste useri din fisiere
        std::ifstream file("users.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string username;
            int age;
            std::string email;
            ss >> username >> age >> email;
            users.add(username, User(username, age, email));
        }

        // citeste evenimente din fisier
        std::ifstream file2("events.txt");
        std::string line2;
        while (std::getline(file2, line2)) {
            std::stringstream ss(line2);
            std::string name;
            std::string location;
            std::string description;
            std::string date;
            ss >> std::quoted(name) >> std::quoted(location) >> std::quoted(description) >> date;
            events.push_back(Event(name, location, description, date));
        }

        // citeste friendship-uri din fisier
        std::ifstream file3("friendships.txt");
        std::string line3;
        while (std::getline(file3, line3)) {
            std::stringstream ss(line3);
            std::string username1;
            std::string username2;
            ss >> username1 >> username2;
            this->addFriendship(username1, username2);
        }

        // citeste mesaje din fisier
        std::ifstream file4("messages.txt");
        std::string line4;
        while (std::getline(file4, line4)) {
            std::stringstream ss(line4);
            std::string sender_username;
            std::string receiver_username;
            std::string message;
            ss >> sender_username >> receiver_username >> std::quoted(message);
            this->sendMessage(sender_username, receiver_username, message);
        }
    }

}

Service::~Service()
{
    if (read_write_file) {
        // scrie useri in fisier
        std::ofstream file("users.txt");
        for (auto &user : users) {
            file << user.getUsername() << " " << user.getAge() << " " << user.getEmail() << std::endl;
        }

        // scrie evenimente in fisier
        // if the variable has multiple words, use std::quoted()
        std::ofstream file2("events.txt");
        for (int i = 0; i < events.size(); i++) {
            file2 << std::quoted(events[i].getName()) << " " << std::quoted(events[i].getLocation()) << " " << std::quoted(events[i].getDescription()) << " " << events[i].getDate() << std::endl;
        }

        // adaugare prietenii intr-un vector
        std::ofstream file3("friendships.txt");
        std::vector<std::pair<std::string, std::string>> friendships;;
        for (auto &user : users) {
            for (auto &friendship : user.getFriends()) {
                friendships.push_back(std::make_pair(
                    friendship.getUser1()->getUsername(),
                     friendship.getUser2()->getUsername()
                ));
            }
        }

        // stergere prietenii duplicate
        for (int i = 0; i < friendships.size(); i++) {
            for (int j = i + 1; j < friendships.size(); j++) {
                if ((friendships[i].first == friendships[j].first && friendships[i].second == friendships[j].second) || 
                    (friendships[i].first == friendships[j].second && friendships[i].second == friendships[j].first)) {
                    friendships.erase(friendships.begin() + j);
                    j--;
                }
            }
        }

        // scriere prietenii in fisier
        for (auto &friendship : friendships) {
            file3 << friendship.first << " " << friendship.second << std::endl;
        }

        // adaugare mesaje intr-un vector
        std::ofstream file4("messages.txt");
        std::vector<Message> messages;;
        for (auto &user : users) {
            for (auto &message : user.getMessages()) {
                messages.push_back(message);
            }
        }

        // stergerea mesajelor duplicate
        for (int i = 0; i < messages.size(); i++) {
            for (int j = i + 1; j < messages.size(); j++) {
                if ((messages[i].sender->getUsername() == messages[j].sender->getUsername() && messages[i].receiver->getUsername() == messages[j].receiver->getUsername() && messages[i].content == messages[j].content) || (messages[i].sender->getUsername() == messages[j].receiver->getUsername() && messages[i].receiver->getUsername() == messages[j].sender->getUsername() && messages[i].content == messages[j].content)) {
                    messages.erase(messages.begin() + j);
                    j--;
                }
            }
        }

        // scrierea mesajelor in fisier
        for (auto &message : messages) {
            file4 << message.sender->getUsername() << " " << message.receiver->getUsername() << " " << std::quoted(message.content) << std::endl;
        }
    }
}

bool Service::addUser(std::string username, int age, std::string email) {
    // check if the usernames are unique
    if (users.contains(username))
        return false;

    users.add(username, User(username, age, email));
    return true;
}

bool Service::updateUser(std::string username, std::string newUsername, int newAge, std::string newEmail) {
    // find user
    if (!users.contains(username))
        return false;

    User* user = &users[username];
    
    for(auto& user2 : users)
        if (user2.getUsername() == newUsername && *user != user2)
            return false;

    users.changeKey(username, newUsername);
    user->setUsername(newUsername);
    user->setAge(newAge);
    user->setEmail(newEmail);
    return true;
}

bool Service::removeUser(std::string username) {
    // find user
    if (!users.contains(username))
        return false;

    User* user = &users[username];

    // remove friendships of the user and its friends
    for (int j = 0; j < user->getFriends().size(); j++)
        removeFriendship(user->getUsername(), user->getFriends()[j].getUser2()->getUsername());

    // remove the user
    for (auto &user2 : users)
        user2.removeFriend(*user);

    users.remove(username);
    
    return true;
}

bool Service::addFriendship(std::string username1, std::string username2) {
    // find users
    if (!users.contains(username1) || !users.contains(username2))
        return false;

    User *user1 = &users[username1];
    User *user2 = &users[username2];

    // check if friendship already exists
    for (int i = 0; i < user1->getFriends().size(); i++) {
        if (user1->getFriends()[i].getUser1() == user1 && user1->getFriends()[i].getUser2() == user2) {
            return false;
        }
    }

    // add friendship
    user1->addFriend(*user2);
    user2->addFriend(*user1);
    return true;
}

bool Service::removeFriendship(std::string username1, std::string username2) {
    // find users
    if (!users.contains(username1) || !users.contains(username2))
        return false;

    User *user1 = &users[username1];
    User *user2 = &users[username2];

    // check if friendship exists
    for (int i = 0; i < user1->getFriends().size(); i++) {
        if (user1->getFriends()[i].getUser1() == user1 && user1->getFriends()[i].getUser2() == user2) {
            user1->removeFriend(*user2);
            user2->removeFriend(*user1);
            return true;
        }
    }

    return false;
}

bool Service::sendMessage(std::string sender_username, std::string receiver_username, std::string message) {
    // find users
    if (!users.contains(sender_username) || !users.contains(receiver_username))
        return false;

    User *sender = &users[sender_username];
    User *receiver = &users[receiver_username];

    sender->sendMessage(*receiver, message);

    return true;
}

List<User*> Service::getUsers() {
    List<User*> list;
    for (auto& user : users)
        list.push_back(&user);

    return list;
}


bool Service::addEvent(std::string name, std::string location, std::string description, std::string date) {
    // check if the event names are unique
    for (int i = 0; i < events.size(); i++)
        if (events[i].getName() == name)
            return false;

    events.push_back(Event(name, location, description, date));

    return true;
}

List<Event> Service::getEvents() {
    return events;
}

bool Service::updateEvent(std::string name, std::string newName, std::string newLocation, std::string newDescription, std::string newDate) {
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == name)
        {
            // check if the event names are unique
            for (int j = 0; j < events.size(); j++)
                if (events[j].getName() == newName && i != j)
                    return false;
                    
            events[i].setName(newName);
            events[i].setLocation(newLocation);
            events[i].setDescription(newDescription);
            events[i].setDate(newDate);

            return true;
        }
    }

    return false;
}

bool Service::removeEvent(std::string name) {
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == name)
        {
            events.remove(i);
            return true;
        }
    }

    return false;
}

bool Service::addInterestedUser(std::string event_name, std::string username) {
    // find event
    Event *event = nullptr;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == event_name)
        {
            event = &events[i];
            break;
        }
    }
    // check if event exists
    if (event == nullptr)
        return false;

    // find user
    if (!users.contains(username))
        return false;

    User *user = &users[username];

    event->addInterested(user);

    return true;
}
