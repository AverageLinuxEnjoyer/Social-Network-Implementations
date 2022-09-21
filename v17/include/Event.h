#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <iostream>
#include "User.h"

class Event {
private:
    std::string name;
    std::string description;
    std::string location;
    std::string startDate;
    std::string endDate;
    
public:
    Event();
    Event(const Event& other);
    Event(const std::string& name,
          const std::string& description,
          const std::string& location,
          const std::string& startDate,
          const std::string& endDate);

    std::string getName() const;
    std::string getDescription() const;
    std::string getLocation() const;
    std::string getStartDate() const;
    std::string getEndDate() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setLocation(const std::string& location);
    void setStartDate(const std::string& startDate);
    void setEndDate(const std::string& endDate);

    bool operator==(const Event& other) const;
    bool operator!=(const Event& other) const;

    Event& operator=(const Event& other);

    friend std::ostream& operator<<(std::ostream& os, const Event& event);
    friend std::istream& operator>>(std::istream& is, Event& event);
};

#endif // EVENT_H