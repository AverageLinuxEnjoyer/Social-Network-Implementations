#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {
public:
    Event();
    Event(int id, const string &name, const string &description, const string &location, const string &date, const string &time);
    Event(const Event &event);

    Event& operator=(const Event &event);

    string getName() const;
    string getDescription() const;
    string getLocation() const;
    string getDate() const;
    string getTime() const;
    int getId() const;

    void setName(const string &name);
    void setDescription(const string &description);
    void setLocation(const string &location);
    void setDate(const string &date);
    void setTime(const string &time);
    void setId(const int &id);

    bool operator==(const Event &event) const;
    bool operator!=(const Event &event) const;
    bool operator<(const Event &event) const;
    bool operator>(const Event &event) const;
private:

    string name;
    string description;
    string location;
    string date;
    string time;
    int id = -1;
};

#endif // EVENT_H
