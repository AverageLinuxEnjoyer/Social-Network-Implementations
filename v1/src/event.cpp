#include "../include/event.h"

Event::Event(std::string name, std::string location, std::string description, std::string date)
    : name(name),
      location(location),
      description(description),
      date(date)
{}

std::string Event::getName() const { return name; }

void Event::setName(const std::string &name_) { name = name_; }

std::string Event::getLocation() const { return location; }

void Event::setLocation(const std::string &location_) { location = location_; }

std::string Event::getDescription() const { return description; }

void Event::setDescription(const std::string &description_) { description = description_; }

std::string Event::getDate() const { return date; }

void Event::setDate(const std::string &date_) { date = date_; }

const List<User*>& Event::getInterested() const { return interested; }

void Event::addInterested(User* user) {
    // if user is not already interested in this event
    for (int i = 0; i < interested.size(); i++)
        if (*interested[i] == *user)
            return;

    interested.push_back(user);

    std::cout << "User " << interested[interested.size()-1]->getUsername() << " is now interested in event " << name << std::endl;
}
