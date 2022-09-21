#include "../include/event.h"

Event::Event(int code, std::string name, int organizer_code, std::string type)
{
    this->code = code;
    this->name = name;
    this->organizer_id = organizer_code;
    this->type = type;
}

int Event::getCode() const { return code; }

void Event::setCode(int code_) { code = code_; }

std::string Event::getName() const { return name; }

void Event::setName(const std::string &name_) { name = name_; }

int Event::organizerId() const { return organizer_id; }

void Event::setOrganizerId(int organizerId) { organizer_id = organizerId; }

std::string Event::getType() const { return type; }

void Event::setType(const std::string &type_) { type = type_; }

bool Event::operator==(const Event& other) const { return code == other.code; }

bool Event::operator<(const Event& other) const { return name < other.name; }

bool Event::operator>(const Event& other) const { return name > other.name; }

const List<int>& Event::getParticipants() const { return participants; }

void Event::setParticipants(const List<int> &participants_) { participants = participants_; }

void Event::addParticipant(int participant) { participants.push_back(participant);}

void Event::removeParticipant(int participant) {
    for (int i = 0; i < participants.getSize(); i++) {
        if (participants[i] == participant) {
            participants.erase(i);
            break;
        }
    }
}

bool Event::operator!=(const Event& other) const { return !(*this == other); }
