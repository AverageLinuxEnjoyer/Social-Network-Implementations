#include "../include/Event.h"

Event::Event()
{

}

Event::Event(const Event &event)
{
    id = event.id;
    name = event.name;
    description = event.description;
    date = event.date;
    location = event.location;
    attendees = event.attendees;
}

Event::Event(int id, string name, string description, string date, string location)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->date = date;
    this->location = location;
}

Event::~Event()
{
    
}

int Event::getId() const { 
    return id; 
}

void Event::setId(int id_) { 
    id = id_; 
}

string Event::getName() const { 
    return name; 
}

void Event::setName(const string &name_) { 
    name = name_; 
}

string Event::getDescription() const { 
    return description; 
}

void Event::setDescription(const string &description_) { 
    description = description_; 
}

string Event::getDate() const { 
    return date; 
}

void Event::setDate(const string &date_) { 
    date = date_; 
}

string Event::getLocation() const { 
    return location; 
}

void Event::setLocation(const string &location_) { 
    location = location_; 
}

List<int> Event::getAttendees() const { 
    return attendees; 
}

void Event::setAttendees(const List<int> &attendees_) { 
    attendees = attendees_; 
}

void Event::addAttendee(int attendeeId) {
    for (int i = 0; i < attendees.getSize(); i++) {
        if (attendees.get(i) == attendeeId) {
            throw "Utilizator participa deja la eveniment.";
        }
    }

    attendees.add(attendeeId);
}

void Event::removeAttendee(int attendeeId) {
    for (int i = 0; i < attendees.getSize(); i++) {
        if (attendees.get(i) == attendeeId) {
            attendees.remove(i);
            break;
        }
    }

    throw "Participantul nu a fost gasit.";
}

bool Event::operator<(const Event &rhs) const {
    return name < rhs.name;
}

bool Event::operator>(const Event &rhs) const {
    return name > rhs.name;
}

bool Event::operator==(const Event &rhs) const {
    return name == rhs.name && description == rhs.description && date == rhs.date && location == rhs.location;
}

bool Event::operator!=(const Event &rhs) const {
    return !(*this == rhs);
}
