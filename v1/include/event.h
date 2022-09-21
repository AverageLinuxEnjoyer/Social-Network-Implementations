#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "list.h"
#include "user.h"

class Event {
public:
    Event() = default;
    Event(std::string name, std::string location, std::string description, std::string date);

    std::string getName() const;
    void setName(const std::string &name_);

    std::string getLocation() const;
    void setLocation(const std::string &location_);

    std::string getDescription() const;
    void setDescription(const std::string &description_);

    std::string getDate() const;
    void setDate(const std::string &date_);

    const List<User*>& getInterested() const;
    void addInterested(User* user);

private:
    std::string name;
    std::string location;
    std::string description;
    std::string date;
    List<User*> interested;
};

#endif // EVENT_H
