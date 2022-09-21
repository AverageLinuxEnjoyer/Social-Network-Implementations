#include "../include/Event.h"

Event::Event()
{
    id = -1;
}

Event::Event(int id, const std::string &name, const std::string &description, const std::string &location, const std::string &date, const std::string &time)
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


std::string Event::getName() const {
    return name;
}

std::string Event::getDescription() const {
    return description;
}

std::string Event::getLocation() const {
    return location;
}

std::string Event::getDate() const {
    return date;
}

std::string Event::getTime() const {
    return time;
}

int Event::getId() const {
    return id;
}

void Event::setName(const std::string &name) {
    this->name = name;
}

void Event::setDescription(const std::string &description) {
    this->description = description;
}

void Event::setLocation(const std::string &location) {
    this->location = location;
}

void Event::setDate(const std::string &date) {
    this->date = date;
}

void Event::setTime(const std::string &time) {
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
