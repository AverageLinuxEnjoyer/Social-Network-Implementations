#include "../include/Event.h"


Event::Event()
    : name(""),
      description(""),
      location(""),
      startDate(""),
      endDate("")
{}

Event::Event(const Event& other)
    : name(other.name),
      description(other.description),
      location(other.location),
      startDate(other.startDate),
      endDate(other.endDate)
{}

Event::Event(const std::string& name, const std::string& description, const std::string& location, const std::string& startDate, const std::string& endDate)
    : name(name),
      description(description),
      location(location),
      startDate(startDate),
      endDate(endDate)
{}

std::string Event::getName() const
{
    return name;
}

std::string Event::getDescription() const
{
    return description;
}

std::string Event::getLocation() const
{
    return location;
}

std::string Event::getStartDate() const
{
    return startDate;
}

std::string Event::getEndDate() const
{
    return endDate;
}

void Event::setName(const std::string& name)
{
    this->name = name;
}

void Event::setDescription(const std::string& description)
{
    this->description = description;
}

void Event::setLocation(const std::string& location)
{
    this->location = location;
}

void Event::setStartDate(const std::string& startDate)
{
    this->startDate = startDate;
}

void Event::setEndDate(const std::string& endDate)
{
    this->endDate = endDate;
}

bool Event::operator==(const Event& other) const
{
    return name == other.name &&
           description == other.description &&
           location == other.location &&
           startDate == other.startDate &&
           endDate == other.endDate;
}

bool Event::operator!=(const Event& other) const
{
    return !(*this == other);
}

Event& Event::operator=(const Event& other)
{
    name = other.name;
    description = other.description;
    location = other.location;
    startDate = other.startDate;
    endDate = other.endDate;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Event: " << event.name << std::endl;
    os << "Description: " << event.description << std::endl;
    os << "Location: " << event.location << std::endl;
    os << "Start date: " << event.startDate << std::endl;
    os << "End date: " << event.endDate << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Event& event) {
    std::string name;
    std::string description;
    std::string location;
    std::string startDate;
    std::string endDate;

    std::cout << "Nume: ";
    std::cin.ignore();
    std::getline(is, name);

    std::cout << "Descriere: ";
    std::cin.ignore();
    std::getline(is, description);

    std::cout << "Locatie: ";
    std::cin.ignore();
    std::getline(is, location);

    std::cout << "Data inceput: ";
    std::cin.ignore();
    std::getline(is, startDate);

    std::cout << "Data sfarsit: ";
    std::cin.ignore();
    std::getline(is, endDate);

    event.name = name;
    event.description = description;
    event.location = location;
    event.startDate = startDate;
    event.endDate = endDate;

    return is;
}