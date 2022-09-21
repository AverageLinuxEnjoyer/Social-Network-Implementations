#include "../include/Network.h"

Network::Network()
    : eventService("events.txt"),
      userService("users.txt")
{
   
}

Network::~Network()
{
    
}

void Network::addUser(const User &user) {
    if (userService.getUser(user.getId()) == User()) {
        userService.addUser(user);
        return;
    }

    throw std::string("User already exists");
}

void Network::addEvent(const Event &event) {
    if (eventService.getEvent(event.getId()) == Event()) {
        eventService.addEvent(event);
        return;
    }

    throw std::string("Event already exists");
}

void Network::addMessage(const Message &message) {
    this->messages.Insert(message);
}

void Network::addFriendship(const Friendship &friendship) {
    if (this->friendships.Find(friendship))
        return;
    else if (this->friendships.Find(Friendship(friendship.getUser1Id(), friendship.getUser2Id())))
        return;

    this->friendships.Insert(friendship);
}


void Network::removeUser(int id) 
{
    List<Message> messages = this->getMessages(id);
    for (int i = 0; i < messages.size(); i++) {
        this->removeMessage(messages[i].getId());
    }

    List<Friendship> friendships = this->getFriends(id);
    for (int i = 0; i < friendships.size(); i++) {
        this->removeFriendship(friendships[i].getUser1Id(), friendships[i].getUser2Id());
    }

    this->userService.removeUser(userService.getUser(id));
}

void Network::removeEvent(int id) {
    this->eventService.removeEvent(eventService.getEvent(id));
}

void Network::removeMessage(int id) {
    auto messages_vector = this->messages.ToVector();
    for (int i = 0; i < messages_vector.size(); i++) {
        if (messages_vector[i].getId() == id) {
            this->messages.Remove(messages_vector[i]);
        }
    }
}

void Network::removeFriendship(int id_user1, int id_user2) {
    auto friendships_vector = this->friendships.ToVector();
    for (int i = 0; i < friendships_vector.size(); i++) {
        if (friendships_vector[i].getUser1Id() == id_user1 && friendships_vector[i].getUser2Id() == id_user2) {
            this->friendships.Remove(friendships_vector[i]);
        }
        else if (friendships_vector[i].getUser1Id() == id_user2 && friendships_vector[i].getUser2Id() == id_user1) {
            this->friendships.Remove(friendships_vector[i]);
        }
    }
}

void Network::modifyUser(int id, const User &user) {
    if (this->userService.getUser(id).getId() == -1)
        return;

    this->userService.modifyUser(id, user);
}

void Network::modifyEvent(int id, const Event &event) {
    if (this->eventService.getEvent(id).getId() == -1)
        return;

    this->eventService.modifyEvent(id, event);
}

List<User> Network::getUsers() {
    return this->userService.getUsers();
}

List<Event> Network::getEvents() {
    return this->eventService.getEvents();
}

List<Message> Network::getMessages() {
    return this->messages.ToVector();
}

List<Message> Network::getMessages(int user_id) {
    List<Message> result;
    List<Message> messages = this->messages.ToVector();
    for (int i = 0; i < messages.size(); i++) {
        if (messages[i].getUser1Id() == user_id || messages[i].getUser2Id() == user_id) {
            result.push_back(messages[i]);
        }
    }
    
    return result;
}


List<Message> Network::getMessages(int user_id1, int user_id2) {
    List<Message> result;
    List<Message> messages = this->messages.ToVector();
    for (int i = 0; i < messages.size(); i++) {
        if (messages[i].getUser1Id() == user_id1 && messages[i].getUser2Id() == user_id2) {
            result.push_back(messages[i]);
        }
        else if (messages[i].getUser1Id() == user_id2 && messages[i].getUser2Id() == user_id1) {
            result.push_back(messages[i]);
        }
    }
    
    return result;
}

User Network::getUser(int id) {
    return this->userService.getUser(id);
}

Event Network::getEvent(int id) {
    return this->eventService.getEvent(id);
}

List<Friendship> Network::getFriendships() {
    return this->friendships.ToVector();
}

List<Friendship> Network::getFriends(int id_user) {
    List<Friendship> result;
    List<Friendship> friendships = this->friendships.ToVector();
    for (int i = 0; i < friendships.size(); i++) {
        if (friendships[i].getUser1Id() == id_user || friendships[i].getUser2Id() == id_user) {
            result.push_back(friendships[i]);
        }
    }
    return result;
}

void Network::subscribe(int user_id, int event_id) {
    User user = this->userService.getUser(user_id);
    Event event = this->eventService.getEvent(event_id);

    if (user.getId() == -1 || event.getId() == -1)
        throw std::string("User or event not found");

    for (int i = 0; i < eventSubscriptions.size(); i++) {
        if (eventSubscriptions[i].getUserId() == user_id && eventSubscriptions[i].getEventId() == event_id)
            throw std::string("User already subscribed to this event");
    }

    eventSubscriptions.push_back(EventSubscription(user_id, event_id));
}

void Network::unsubscribe(int user_id, int event_id) {
    for (int i = 0; i < eventSubscriptions.size(); i++) {
        if (eventSubscriptions[i].getUserId() == user_id && eventSubscriptions[i].getEventId() == event_id) {
            eventSubscriptions.erase(i);
            return;
        }
    }

    throw std::string("User not subscribed to this event");
}

List<User> Network::getSubscribers(int event_id) {
    List<User> result;
    for (int i = 0; i < eventSubscriptions.size(); i++) {
        if (eventSubscriptions[i].getEventId() == event_id) {
            result.push_back(this->userService.getUser(eventSubscriptions[i].getUserId()));
        }
    }
    return result;
}

List<Event> Network::getSubscriptions(int user_id) {
    List<Event> result;
    for (int i = 0; i < eventSubscriptions.size(); i++) {
        if (eventSubscriptions[i].getUserId() == user_id) {
            result.push_back(this->eventService.getEvent(eventSubscriptions[i].getEventId()));
        }
    }
    return result;
}
