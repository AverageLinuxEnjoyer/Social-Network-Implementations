#include "../include/Network.h"
#include  <fstream>

Network::Network()
    : users(),
      friends(),
      events()
{
    loadUsersFromFile("useri.csv");
}

void Network::loadUsersFromFile(std::string filename) {
    std::ifstream f(filename);
    if (f.is_open()) {
        User user;
        while (loadFromCSV(f, user)) {
            this->users.add(user);
        }
    }
}

void Network::saveUsersToFile(std::string filename) {
    std::ofstream f(filename);
    auto users_vec = this->users.getAll();

    if (f.is_open()) {
        for (int i = 0; i < users_vec.size(); i++) {
            loadIntoCSV(f, *users_vec[i]);
        }
    }
}

Network& Network::getInstance() {
    static Network instance;
    return instance;    
}

Network::~Network()
{
    saveUsersToFile("useri.csv");
}


Set<User>& Network::getUsers() {
    return users;
}

Set<Event>& Network::getEvents() {
    return events;
}

MultiDictionary<User*, User*>& Network::getFriends() {
    return friends;
}

MultiDictionary<User*, Event*>& Network::getAttendedEvents() {
    return attended_events;
}

User* Network::findUser(std::string username) {
    std::vector<User*> users_vec = users.getAll();
    for (auto& user : users_vec) {
        if (user->getUsername() == username) {
            return user;
        }
    }

    return nullptr;
}

void Network::addUser(User* user) {
    users.add(*user);
}

Event* Network::findEvent(std::string event_name) {
    std::vector<Event*> events_vec = events.getAll();
    for (auto& event : events_vec) {
        if (event->getName() == event_name) {
            return event;
        }
    }

    return nullptr;
}

void Network::addEvent(Event* event) {
    events.add(*event);
}

void Network::addFriendship(User* user1, User* user2) {
    if (!friends.contains(user1, user2))
        friends.put(user1, user2);

    if (!friends.contains(user2, user1))
        friends.put(user2, user1);
}

void Network::addAttendance(User* user, Event* event) {
    if (!attended_events.contains(user, event))
        attended_events.put(user, event);
}

void Network::addMessage(Message message) {
    messages.push_back(message);
}

void Network::updateUser(User* user, User new_user) {
    user->setUsername(new_user.getUsername());
    user->setPassword(new_user.getPassword());
    user->setEmail(new_user.getEmail());
    user->setFirstName(new_user.getFirstName());
    user->setLastName(new_user.getLastName());
    user->setBio(new_user.getBio());
    user->setProfilePicture(new_user.getProfilePicture());
}

void Network::updateEvent(Event* event, Event new_event) {
    event->setName(new_event.getName());
    event->setDescription(new_event.getDescription());
    event->setStartDate(new_event.getStartDate());
    event->setEndDate(new_event.getEndDate());
    event->setLocation(new_event.getLocation());
}

void Network::removeUser(User* user) {
    auto friends_vec = friends.get(user);

    for (auto& friend_ptr : friends_vec) {
        friends.remove(friend_ptr, user);
    }

    auto attended_events_vec = attended_events.get(user);

    for (auto& event_ptr : attended_events_vec) {
        attended_events.remove(user, event_ptr);
    }

    attended_events.remove(user);

    users.remove(*user);
}

void Network::removeEvent(Event* event) {
    auto users_vec = users.getAll();

    for (auto& user : users_vec) {
        attended_events.remove(user, event);
    }

    events.remove(*event);
}

void Network::removeFriendship(User* user1, User* user2) {
    friends.remove(user1, user2);
    friends.remove(user2, user1);
}

void Network::removeAttendance(User* user, Event* event) {
    attended_events.remove(user, event);
}

std::vector<User*> Network::getFriendsOf(User* user) {
    return friends.get(user);
}

std::vector<User*> Network::getCommonFriends(User* user1, User* user2) {
    std::vector<User*> common_friends;

    std::vector<User*> friends_of_user1 = getFriendsOf(user1);
    std::vector<User*> friends_of_user2 = getFriendsOf(user2);

    for (auto& friend_ptr : friends_of_user1) {
        for (auto& friend_ptr2 : friends_of_user2) {
            if (friend_ptr == friend_ptr2) {
                common_friends.push_back(friend_ptr);
            }
        }
    }

    return common_friends;    
}

std::vector<Event*> Network::getEventsAttendedBy(User* user) {
    return attended_events.get(user);
}

std::vector<User*> Network::getUsersAttending(Event* event) {
    std::vector<User*> users_attending;

    auto users_vec = users.getAll();

    for (auto& user_ptr : users_vec) {
        auto events_vec = getEventsAttendedBy(user_ptr);

        for (auto& event_ptr : events_vec) {
            if (event_ptr == event) {
                users_attending.push_back(user_ptr);
            }
        }
    }

    return users_attending;
}

std::vector<Message> Network::getMessages(User* user) {
    std::vector<Message> user_messages;

    for (auto& message : messages) {
        if (message.getReceiver() == user || message.getSender() == user) {
            user_messages.push_back(message);
        }
    }

    return user_messages;
}

std::vector<Message> Network::getMessages(User* user1, User* user2) {
    std::vector<Message> user_messages;

    for (auto& message : messages) {
        if ((message.getReceiver() == user1 && message.getSender() == user2) || (message.getReceiver() == user2 && message.getSender() == user1)) {
            user_messages.push_back(message);
        }
    }

    return user_messages;
}
