#ifndef EVENT_SERVICE_H
#define EVENT_SERVICE_H

#include "service.h"
#include "event.h"

class EventService : public Service<Event> {
public:
    EventService();

    void addParticipant(int event_code, int participant_code);
    void removeParticipant(int event_code, int participant_code);
    List<int> getParticipants(int event_code);
};

#endif // EVENT_SERVICE_H
