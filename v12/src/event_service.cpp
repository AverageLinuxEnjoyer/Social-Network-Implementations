#include "../include/event_service.h"
#include <random>
#include <vector>
using namespace std;

EventService::EventService()
{
    vector<string> names={"Untold", "Electric Castle", "Concert", "Football game"};

    vector<string> type = {"party", "concert", "sport", "other"};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <int> dis(0, 100);

    int nrE=15;
    int code=1;

    for(int i=0; i<nrE; i++)
    {
        Event event;
        event.setCode(code);
        event.setName(names[dis(rd)%names.size()]);
        event.setOrganizerId(dis(rd)%15);
        event.setType(type[dis(rd)%type.size()]);
        code++;
        this->add(event);
    }
}

void EventService::addParticipant(int event_code, int participant_code) {
    Event event = this->get(event_code);
    event.addParticipant(participant_code);
    this->update(event.getCode(), event);    
}

void EventService::removeParticipant(int event_code, int participant_code) {
    Event event = this->get(event_code);
    event.removeParticipant(participant_code);
    this->update(event.getCode(), event);
}

List<int> EventService::getParticipants(int event_code) 
{
    Event event = this->get(event_code);
    
    return event.getParticipants();
}
