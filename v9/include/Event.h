#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "User.h"
using namespace std;

class Event {
public:
    Event();
    Event(const Event &event);
    Event(int id, string name, string description, string date, string location);
    ~Event();

    int getId() const;
    void setId(int id_);

    string getName() const;
    void setName(const string &name_);

    string getDescription() const;
    void setDescription(const string &description_);

    string getDate() const;
    void setDate(const string &date_);

    string getLocation() const;
    void setLocation(const string &location_);

    List<int> getAttendees() const;
    void setAttendees(const List<int> &attendees_);
    void addAttendee(int attendeeId);
    void removeAttendee(int attendeeId);

    bool operator<(const Event &rhs) const;
    bool operator>(const Event &rhs) const;
    bool operator==(const Event &rhs) const;
    bool operator!=(const Event &rhs) const;

private:
    int id;
    string name;
    string description;
    string date;
    string location;
    List<int> attendees;
};

#endif // EVENT_H
