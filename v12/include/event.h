#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "list.h"

class Event{
public:
    Event() = default;
    Event(int code, std::string name, int organizer_code, std::string type);
    Event(const Event& other) = default;
    ~Event() = default;

    int getCode() const;
    void setCode(int code_);

    std::string getName() const;
    void setName(const std::string &name_);

    int organizerId() const;
    void setOrganizerId(int organizerId);

    std::string getType() const;
    void setType(const std::string &type_);

    bool operator==(const Event& other) const;
    bool operator<(const Event& other) const;
    bool operator>(const Event& other) const;

    const List<int>& getParticipants() const;
    void setParticipants(const List<int> &participants_);
    void addParticipant(int participant);
    void removeParticipant(int participant);

    bool operator!=(const Event& other) const;

private:
    int code;
    std::string name;
    int organizer_id;
    std::string type;
    List<int> participants;
};

#endif // EVENT_H
