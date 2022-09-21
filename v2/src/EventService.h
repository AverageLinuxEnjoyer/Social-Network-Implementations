#ifndef SERVICEEVENT_H
#define SERVICEEVENT_H

#include "Event.h"
#include "List.h"
using namespace std;

class EventService {
public:
    EventService(string fileName);
    ~EventService();

    List<Event> getEvents();
    Event getEvent(int id);
    void addEvent(const Event &event);
    void modifyEvent(int id, const Event &event);
    void removeEvent(const Event &event);

private:
    List<Event> events;
    string fileName;
};

#endif // SERVICEEVENT_H
