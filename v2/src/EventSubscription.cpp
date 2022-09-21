#include "EventSubscription.h"

EventSubscription::EventSubscription()
{
    
}

EventSubscription::EventSubscription(int userId, int eventId)
{
    this->user_id = userId;
    this->event_id = eventId;
}

EventSubscription::EventSubscription(const EventSubscription &EventSubscription)
{
    this->user_id = EventSubscription.user_id;
    this->event_id = EventSubscription.event_id;
}

EventSubscription::~EventSubscription()
{

}

int EventSubscription::getUserId() const {
    return user_id;
}

void EventSubscription::setUserId(const int &userId) {
    this->user_id = userId;
}

int EventSubscription::getEventId() const {
    return event_id;
}

void EventSubscription::setEventId(const int &eventId) {
    this->event_id = eventId;
}

bool EventSubscription::operator==(const EventSubscription &EventSubscription) const {
    return (user_id == EventSubscription.user_id && event_id == EventSubscription.event_id);
}

bool EventSubscription::operator!=(const EventSubscription &EventSubscription) const {
    return !(*this == EventSubscription);
}
