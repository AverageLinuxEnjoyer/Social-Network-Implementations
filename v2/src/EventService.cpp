#include "EventService.h"
#include <fstream>


EventService::EventService(string fileName)
{
    this->fileName = fileName;

    ifstream file(fileName);

    int id;
    string name;
    string description;
    string location;
    string date;
    string time;

    while (file >> id >> name >> description >> location >> date >> time) {
        Event event(id, name, description, location, date, time);
        events.push_back(event);
    }
}

EventService::~EventService()
{
    ofstream file(fileName);

    for (int i = 0; i < events.size(); i++) {
        file << events[i].getId() << " " << events[i].getName() << " " << events[i].getDescription() << " " << events[i].getLocation() << " " << events[i].getDate() << " " << events[i].getTime() << endl;
    }
}

List<Event> EventService::getEvents() {
    return events;
}

Event EventService::getEvent(int id) {
    for (int i = 0; i < events.size(); i++) {
        if (events[i].getId() == id) {
            return events[i];
        }
    }
    
    return Event();
}

void EventService::addEvent(const Event &event) {
    events.push_back(event);
}

void EventService::modifyEvent(int id, const Event &event) {
    for (int i = 0; i < events.size(); i++) {
        if (events[i].getId() == id) {
            events[i] = event;
        }
    }
}

void EventService::removeEvent(const Event &event) {
    for (int i = 0; i < events.size(); i++) {
        if (events[i].getId() == event.getId()) {
            events.erase(i);
        }
    }
}
