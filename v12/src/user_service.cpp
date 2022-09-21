#include "../include/user_service.h"
#include <vector>
#include <random>

using namespace std;

UserService::UserService() {
    vector<string> names={"Clau", "Prigoana", "Andrei", "Alex", "Sebastian", "Andreea", "Maria"};
    vector<string> gender={"m", "f"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <int> dis(0, 100);
    int nrU=15;
    int code=1;
    for(int i=0; i<nrU; i++)
    {
        User util;
        util.setCode(code);
        util.setName(names[dis(rd)%names.size()]);
        util.setAge(dis(rd));
        util.setGender(gender[dis(rd)%gender.size()]);
        code++;
        this->add(util);
    }
    
    List<User> vec = this->getAll();

    int chance = 50;
    for (int i = 0; i < vec.getSize(); i++)
    {
        for (int j = 0; j < vec.getSize(); j++)
        {
            if (i != j)
            {
                while (dis(gen) % 100 < chance)
                {
                    string message = "Hello " + vec[j].getName();
                    this->add_message(vec[i].getCode(), vec[j].getCode(), message);
                }
            }
        }
    }

    this->add(User(100, "Danuta", 20, "f"));
    this->add(User(101, "Ion", 20, "m"));
    this->add(User(102, "Mihai", 20, "m"));
    this->add(User(103, "Alex", 20, "m"));
    this->add(User(104, "Stefanut", 20, "m"));
    this->addFriend(100, 101);
    this->addFriend(100, 102);
    this->addFriend(100, 103);
    this->addFriend(100, 104);
    this->addFriend(101, 102);
}

void UserService::addFriend(int user_code, int friend_code) {
    User user = this->get(user_code);
    user.addFriend(friend_code);
    this->update(user.getCode(), user);

    User friend_user = this->get(friend_code);
    friend_user.addFriend(user_code);
    this->update(friend_user.getCode(), friend_user);
}

void UserService::removeFriend(int user_code, int friend_code) {
    User user = this->get(user_code);
    user.removeFriend(friend_code);
    this->update(user.getCode(), user);

    User friend_user = this->get(friend_code);
    friend_user.removeFriend(user_code);
    this->update(friend_user.getCode(), friend_user);
}

List<User> UserService::getFriends(int user_code) {
    User user = this->get(user_code);
    List<User> user_friends;

    for (int i = 0; i < user.getFriends().getSize(); i++) {
        user_friends.push_back(this->get(user.getFriends()[i]));
    }

    return user_friends;
}

void UserService::removeAllFriends(int user_code) {
    User user = this->get(user_code);
    List<int> user_friends = user.getFriends();

    for (int i = 0; i < user_friends.getSize(); i++) {
        User friend_user = this->get(user_friends[i]);
        friend_user.removeFriend(user_code);
        this->update(friend_user.getCode(), friend_user);
    }
}

void UserService::add_message(int user1_code, int user2_code, std::string message) {
    messages.push_back(std::make_tuple(user1_code, user2_code, message));
}

List<std::tuple<int, int, std::string>> UserService::get_messages(int user1_code, int user2_code) {
    List<std::tuple<int, int, std::string>> user_messages;

    for (int i = 0; i < messages.getSize(); i++) {
        if (std::get<0>(messages[i]) == user1_code && std::get<1>(messages[i]) == user2_code || std::get<0>(messages[i]) == user2_code && std::get<1>(messages[i]) == user1_code) {
            user_messages.push_back(messages[i]);
        }
    }

    return user_messages;
}

void UserService::delete_chat(int user1_code, int user2_code) {
    for (int i = 0; i < messages.getSize(); i++) {
        if (std::get<0>(messages[i]) == user1_code && std::get<1>(messages[i]) == user2_code || std::get<0>(messages[i]) == user2_code && std::get<1>(messages[i]) == user1_code) {
            messages.erase(i);
            break;
        }
    }
}

