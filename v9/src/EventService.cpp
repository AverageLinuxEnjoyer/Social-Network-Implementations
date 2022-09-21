#include "../include/EventService.h"
#include <fstream>


EventSerice::EventSerice()
{
    readEventsFromFile();
}

EventSerice::~EventSerice()
{   
    writeEventsToFile();
}

void EventSerice::addEvent(Event event) {
    vector<Event> events_ = getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == event.getId()) {
            throw "Evenimentul exista deja.";
        }
    }

    events.insert(event);
}

void EventSerice::updateEvent(int id, Event event) {
    this->removeEvent(id);
    this->addEvent(event);
}

void EventSerice::removeEvent(int id) {
    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == id) {
            events.remove(events_[i]);
            return;
        }
    }

    throw "Evenimentul nu a fost gasit.";
}

Event EventSerice::getEvent(int id) {
    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == id) {
            return events_[i];
        }
    }

    throw "Evenimentul nu a fost gasit.";
}

vector<Event> EventSerice::getEvents() {
    return events.to_vector();
}

void EventSerice::addAttendee(int eventId, int attendeeId) {
    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == eventId) {
            Event event = events_[i];
            event.addAttendee(attendeeId);
            this->updateEvent(eventId, event);
            return;
        }
    }

    throw "Evenimentul nu a fost gasit.";
}

void EventSerice::removeAttendee(int eventId, int attendeeId) {
    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == eventId) {
            Event event = events_[i];
            event.removeAttendee(attendeeId);
            this->updateEvent(eventId, event);
            return;
        }
    }

    throw "Evenimentul nu a fost gasit.";
}

List<int> EventSerice::getAttendees(int eventId) {
    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        if (events_[i].getId() == eventId) {
            return events_[i].getAttendees();
        }
    }

    throw "Evenimentul nu a fost gasit.";
}

void EventSerice::readEventsFromFile() {
    ifstream file("events.txt");

    if (!file.is_open()) {
        return;
    }

    int id;
    string name, description, date, location;
    while(file >> id >> name >> description >> date >> location) {
        Event event(id, name, description, date, location);
        events.insert(event);
    }

    file.close();
}

void EventSerice::writeEventsToFile() {
    ofstream file("events.txt");

    if (!file.is_open()) {
        return;
    }

    vector<Event> events_ = this->getEvents();

    for (int i = 0; i < events_.size(); i++) {
        file << events_[i].getId() << " " << events_[i].getName() << " " << events_[i].getDescription() << " " << events_[i].getDate() << " " << events_[i].getLocation() << endl;
    }

    file.close();
}
