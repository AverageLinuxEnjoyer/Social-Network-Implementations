#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "service.h"
#include "user.h"
#include <tuple>

class UserService : public Service<User> {
public:
    UserService();
    void addFriend(int user_code, int friend_code);
    void removeFriend(int user_code, int friend_code);
    List<User> getFriends(int user_code);
    void removeAllFriends(int user_code);

    void add_message(int user1_code, int user2_code, std::string message);
    List<std::tuple<int, int, std::string>> get_messages(int user1_code, int user2_code);
    void delete_chat(int user1_code, int user2_code);

private:
    List<std::tuple<int, int, std::string>> messages;
};

#endif // USER_SERVICE_H
