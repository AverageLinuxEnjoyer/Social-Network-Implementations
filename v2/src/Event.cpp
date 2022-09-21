#include "Event.h"

Event::Event()
{
    id = -1;
}

Event::Event(int id, const string &name, const string &description, const string &location, const string &date, const string &time)
    : name(name),
      description(description),
      location(location),
      date(date),
      time(time),
      id(id)
{
    
}

Event::Event(const Event &event)
    : name(event.name),
      description(event.description),
      location(event.location),
      date(event.date),
      time(event.time),
      id(event.id)
{
    
}

Event& Event::operator=(const Event &event) {
    name = event.name;
    description = event.description;
    location = event.location;
    date = event.date;
    time = event.time;
    id = event.id;
    
    return *this;
}


string Event::getName() const {
    return name;
}

string Event::getDescription() const {
    return description;
}

string Event::getLocation() const {
    return location;
}

string Event::getDate() const {
    return date;
}

string Event::getTime() const {
    return time;
}

int Event::getId() const {
    return id;
}

void Event::setName(const string &name) {
    this->name = name;
}

void Event::setDescription(const string &description) {
    this->description = description;
}

void Event::setLocation(const string &location) {
    this->location = location;
}

void Event::setDate(const string &date) {
    this->date = date;
}

void Event::setTime(const string &time) {
    this->time = time;
}

void Event::setId(const int &id) {
    this->id = id;
}

bool Event::operator==(const Event &event) const {
    return name == event.name &&
           description == event.description &&
           location == event.location &&
           date == event.date &&
           time == event.time &&
           id == event.id;
}

bool Event::operator!=(const Event &event) const {
    return !(*this == event);
}

bool Event::operator<(const Event &event) const {
    return name < event.name;
}

bool Event::operator>(const Event &event) const {
    return name > event.name;
}
