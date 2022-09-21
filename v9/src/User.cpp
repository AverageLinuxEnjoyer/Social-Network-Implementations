#include "../include/User.h"

User::User()
{
    
}

User::User(const User &user)
{
    id = user.id;
    name = user.name;
    email = user.email;
    password = user.password;
    phone = user.phone;
    city = user.city;
    state = user.state;
    friends = user.friends;
    events = user.events;
}

User::User(int id, string name, string email, string password, string phone, string city, string state)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
    this->phone = phone;
    this->city = city;
    this->state = state;
}

User::~User()
{
    
}

int User::getId() const { 
    return id; 
}

void User::setId(int id_) { 
    id = id_; 
}

string User::getName() const { 
    return name; 
}


void User::setName(const string &name_) { 
    name = name_; 
}

string User::getEmail() const { 
    return email; 
}

void User::setEmail(const string &email_) { 
    email = email_; 
}

string User::getPassword() const { 
    return password; 
}

void User::setPassword(const string &password_) { 
    password = password_; 
}

string User::getPhone() const { 
    return phone; 
}

void User::setPhone(const string &phone_) { 
    phone = phone_; 
}

string User::getCity() const { 
    return city; 
}

void User::setCity(const string &city_) { 
    city = city_; 
}

string User::getState() const { 
    return state; 
}

void User::setState(const string &state_) { 
    state = state_; 
}

List<int> User::getFriends() const {
    return friends;
}

void User::setFriends(const List<int> &friends_) {
    friends = friends_;
}

void User::addFriend(int friendId) {
    friends.add(friendId);
}

void User::removeFriend(int friendId) {
    for (int i = 0; i < friends.getSize(); i++) {
        if (friends.get(i) == friendId) {
            friends.remove(i);
            break;
        }
    }
}

List<int> User::getEvents() const {
    return events;
}

void User::setEvents(const List<int> &events_) {
    events = events_;
}

void User::addEvent(int eventId) {
    events.add(eventId);
}

void User::removeEvent(int eventId) {
    for (int i = 0; i < events.getSize(); i++) {
        if (events.get(i) == eventId) {
            events.remove(i);
            break;
        }
    }
}

bool User::operator<(const User &rhs) const {
    return this->name < rhs.name;
}

bool User::operator>(const User &rhs) const {
    return this->name > rhs.name;   
}

bool User::operator==(const User &rhs) const {
    return this->name == rhs.name && this->email == rhs.email && this->password == rhs.password && this->phone == rhs.phone && this->city == rhs.city && this->state == rhs.state;
}

bool User::operator!=(const User &rhs) const {
    return !(*this == rhs);
}
