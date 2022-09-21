#ifndef EVENTSERVICE_H
#define EVENTSERVICE_H

#include "Ordered Set.h"
#include "Event.h"

class EventSerice {
public:
    EventSerice();
    ~EventSerice();

    void addEvent(Event event);
    void updateEvent(int id, Event event);
    void removeEvent(int id);
    Event getEvent(int id);
    vector<Event> getEvents();
    void addAttendee(int eventId, int attendeeId);
    void removeAttendee(int eventId, int attendeeId);
    List<int> getAttendees(int eventId);

private:
    void readEventsFromFile();
    void writeEventsToFile();

    OrderedSet<Event> events;
};

#endif // EVENTSERVICE_H
