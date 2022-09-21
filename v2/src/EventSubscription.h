#ifndef EVENTSUBSCRIPTION_H
#define EVENTSUBSCRIPTION_H

class EventSubscription {
public:
    EventSubscription();
    EventSubscription(int userId, int eventId);
    EventSubscription(const EventSubscription &EventSubscription);
    ~EventSubscription();

    int getUserId() const;
    void setUserId(const int &userId);

    int getEventId() const;
    void setEventId(const int &eventId);

    bool operator==(const EventSubscription &EventSubscription) const;
    bool operator!=(const EventSubscription &EventSubscription) const;

private:
    int user_id;
    int event_id;
};

#endif // EVENTSUBSCRIPTION_H
