#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    Message();
    Message(int id , int senderId, int receiverId, const std::string &test);
    Message(const Message &message);
    ~Message();

    std::string getMessage() const;
    void setMessage(const std::string &message);

    int getId() const;
    void setId(const int &id);

    int getUser1Id() const;
    void setUser1Id(const int &userId);

    int getUser2Id() const;
    void setUser2Id(const int &eventId);

    bool operator==(const Message &message) const;
    bool operator!=(const Message &message) const;
    bool operator<(const Message &message) const;
    bool operator>(const Message &message) const;
    
private:
    int id;
    int user1_id;
    int user2_id;  
    std::string text;
};

#endif // MESSAGE_H
