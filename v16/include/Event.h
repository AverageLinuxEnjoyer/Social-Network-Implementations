#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
public:
    Event();
    Event(int id, const std::string &name, const std::string &description, const std::string &location, const std::string &date, const std::string &time);
    Event(const Event &event);

    Event& operator=(const Event &event);

    std::string getName() const;
    std::string getDescription() const;
    std::string getLocation() const;
    std::string getDate() const;
    std::string getTime() const;
    int getId() const;

    void setName(const std::string &name);
    void setDescription(const std::string &description);
    void setLocation(const std::string &location);
    void setDate(const std::string &date);
    void setTime(const std::string &time);
    void setId(const int &id);

    bool operator==(const Event &event) const;
    bool operator!=(const Event &event) const;
    bool operator<(const Event &event) const;
    bool operator>(const Event &event) const;
private:

    std::string name;
    std::string description;
    std::string location;
    std::string date;
    std::string time;
    int id = -1;
};

#endif // EVENT_H
