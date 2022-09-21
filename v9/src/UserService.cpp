#include "../include/UserService.h"
#include <fstream>
#include <random>

UserService::UserService()
{
    readUsersFromFile();

    std::vector<std::string> possible_messages = {
        "salut", "ce faci?", "buna", "neata", "buna ziua", "buna dimineata",
        "pa", "bine", "nu", "da", "nu stiu", "ok" 
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    auto users_vec = users.to_vector();

    for (int i = 0; i < users_vec.size(); i++) {
        for (int j = 0; j < users_vec.size(); j++) {
            int chance = 50;
            while (i != j && dis(gen) < chance) {
                this->sendMessage({
                    users_vec[i].getId(),
                    users_vec[j].getId(),
                    possible_messages[dis(gen) % possible_messages.size()]
                });
            }
        }
    };
}

UserService::~UserService()
{
    writeUsersToFile();
}

void UserService::addUser(User user) {
    vector<User> users_ = getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == user.getId()) {
            throw "Utilizatorul deja exista.";
        }
    }

    users.insert(user);
}


void UserService::updateUser(int id, User user) {
    this->removeUser(id);
    this->addUser(user);
}


void UserService::removeUser(int id) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == id) {
            users.remove(users_[i]);
            return;
        }
    }

    throw "Utilizator nu a fost gasit.";
}


User UserService::getUser(int id) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == id) {
            return users_[i];
        }
    }

    throw "Utilizator nu a fost gasit.";
}


vector<User> UserService::getUsers() {
    return users.to_vector();
}

void UserService::addFriend(int userId, int friendId) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            addFriendToUser(userId, friendId);
            return;
        }
    }

    throw "Utilizator nu a fost gasit.";
}

void UserService::removeFriend(int userId, int friendId) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            removeFriendFromUser(userId, friendId);
            return;
        }
    }

    throw "Utilizator nu a fost gasit.";
}

List<int> UserService::getFriends(int userId) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            return users_[i].getFriends();
        }
    }

    throw "Utilizator nu a fost gasit.";
}

void UserService::addEvent(int userId, int eventId) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            List<int> events = users_[i].getEvents();
            for (int j = 0; j < events.getSize(); j++) {
                if (events.get(j) == eventId) {
                    throw "Utilizatorul participa deja la acest eveniment.";
                }
            }
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            User user = users_[i];
            user.addEvent(eventId);

            this->updateUser(userId, user);
            return;
        }
    }

    throw "Utilizator nu a fost gasit.";
}

void UserService::removeEvent(int userId, int eventId) {
    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            User user = users_[i];
            user.removeEvent(eventId);

            this->updateUser(userId, user);
            return;
        }
    }

    throw "Utilizatorul sau evenimentul nu a fost gasit.";
}

List<int> UserService::getEvents(int userId) {
    return this->getUser(userId).getEvents();
}

void UserService::addFriendToUser(int userId, int friendId) {
    vector<User> users_ = this->getUsers();

    List<int> friends1;
    List<int> friends2;

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            friends1 = users_[i].getFriends();
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == friendId) {
            friends2 = users_[i].getFriends();
        }
    }

    for (int i = 0; i < friends1.getSize(); i++) {
        if (friends1.get(i) == friendId) {
            throw "Prietenia exista deja.";
        }
    }

    for (int i = 0; i < friends2.getSize(); i++) {
        if (friends2.get(i) == userId) {
            throw "Prietenia exista deja.";
        }
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            User user = users_[i];
            user.addFriend(friendId);
            
            users.remove(users_[i]);
            users.insert(user);
        }
        else if (users_[i].getId() == friendId) {
            User user = users_[i];
            user.addFriend(userId);
            
            users.remove(users_[i]);
            users.insert(user);

        }
    }
}

void UserService::removeFriendFromUser(int userId, int friendId) {
    vector<User> users_ = this->getUsers();

    bool found = false;

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == userId) {
            User user = users_[i];
            user.removeFriend(friendId);

            users.remove(users_[i]);
            users.insert(user);

            found = true;
        }
        else if (users_[i].getId() == friendId) {
            User user = users_[i];
            user.removeFriend(userId);

            users.remove(users_[i]);
            users.insert(user);
            found = true;
        }
    }

    if (!found) {
        throw "Utilizatorul sau prietenul nu a fost gasit.";
    }
}


List<Message> UserService::getMessages() const {
    return messages;
}

List<Message> UserService::getMessages(int user1Id, int user2Id) {
    vector<User> users_ = this->getUsers();

    bool user1found = false;
    bool user2found = false;

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == user1Id) {
            user1found = true;
        }
        else if (users_[i].getId() == user2Id) {
            user2found = true;
        }
    }

    if (!user1found || !user2found) {
        throw "Utilizator nu a fost gasit.";
    }

    List<Message> messages_;

    for (int i = 0; i < messages.getSize(); i++) {
        if (messages.get(i).senderId == user1Id && messages.get(i).receiverId == user2Id) {
            Message m = messages.get(i);
            messages_.add(m);
        }
        else if (messages.get(i).senderId == user2Id && messages.get(i).receiverId == user1Id) {
            Message m = messages.get(i);
            messages_.add(m);
        }
    }

    return messages_;

}

void UserService::setMessages(const List<Message> &messages_) {
    messages = messages_;
}

void UserService::sendMessage(Message message) {
    // check if users exist
    vector<User> users_ = this->getUsers();

    bool user1found = false;
    bool user2found = false;

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i].getId() == message.receiverId) {
            user1found = true;
        }
        if (users_[i].getId() == message.senderId) {
            user2found = true;
        }
    }

    if (!user1found) {
        throw "Utilizatorul 1 nu a fost gasit.";
    }
    if (!user2found) {
        throw "Utilizatorul 2 nu a fost gasit.";
    }

    messages.add(message);
}

void UserService::readUsersFromFile() {
    ifstream file;
    file.open("users.txt");

    if (!file.is_open()) {
        return;
    }

    int id;
    string name, email, password, phone, city, state;

    while (file >> id >> name >> email >> password >> phone >> city >> state) {
        User user(id, name, email, password, phone, city, state);
        users.insert(user);
    }
}

void UserService::writeUsersToFile() {
    ofstream file;
    file.open("users.txt");

    if (!file.is_open()) {
        return;
    }

    vector<User> users_ = this->getUsers();

    for (int i = 0; i < users_.size(); i++) {
        file << users_[i].getId() << " " << users_[i].getName() << " " << users_[i].getEmail() << " " << users_[i].getPassword() << " " << users_[i].getPhone() << " " << users_[i].getCity() << " " << users_[i].getState() << endl;
    }
}
