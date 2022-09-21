#include <iostream>
#include <cassert>

#include "../include/tests.h"
#include "../include/list.h"
#include "../include/dictionary.h"
#include "../include/service.h"

void test_list();
void test_dictionary();

void test_user();
void test_service();

void tests() {
    test_list();
    test_dictionary();

    test_user();
    test_service();
    std::cout << "Toate testele au fost trecute cu succes!" << std::endl;
}

void test_list() {
    List<int>* list1 = new List<int>();
    assert(list1->count == 0);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    list1->capacity = 20;

    List<int>* list2 = new List<int>(*list1);
    assert(list2->count == 0);
    assert(list2->capacity == 20);
    assert(list2->data != nullptr);

    List<int>* list3 = new List<int>(std::move(*list2));
    assert(list3->isEmpty());
    assert(list3->count == 0);
    assert(list3->capacity == 20);
    assert(list3->data != nullptr);

    delete list2;
    delete list3;
    list1->capacity = 10;

    list1->insert(0, 6);
    assert(list1->count == 1);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 6);

    list1->push_back(4);
    assert(list1->count == 2);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 6);
    assert(list1->data[1] == 4);

    list1->push_front(5);
    assert(list1->count == 3);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 5);
    assert(list1->data[1] == 6);
    assert(list1->data[2] == 4);

    list1->insert(1, 3);
    assert(list1->count == 4);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 5);
    assert(list1->data[1] == 3);
    assert(list1->data[2] == 6);
    assert(list1->data[3] == 4);

    list1->pop_front();
    assert(list1->count == 3);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 3);
    assert(list1->data[1] == 6);
    assert(list1->data[2] == 4);

    list1->remove(1);
    assert(list1->count == 2);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 3);
    assert(list1->data[1] == 4);

    assert(!list1->isEmpty());

    list1->pop_back();
    assert(list1->count == 1);
    assert(list1->capacity == 10);
    assert(list1->data != nullptr);
    assert(list1->data[0] == 3);

    list1->clear();
    assert(list1->count == 0);
    assert(list1->capacity == 10);
    assert(list1->data == nullptr);
    assert(list1->isEmpty());

    std::cout << "Test list: OK" << std::endl;
}

void test_dictionary() {
    Dictionary<char, int> dict;
    
    dict['a'] = 1;
    assert(dict['a'] == 1);
    assert(dict.contains('a'));;

    dict.add('b', 2);
    assert(dict['b'] == 2);
    assert(dict.contains('b'));

    dict.remove('b');
    assert(!dict.contains('b'));

    dict.remove('x');
    assert(!dict.contains('x'));

    dict.add('x', 3);
    assert(dict['x'] == 3);
    assert(dict.contains('x'));
    assert(*dict.begin() == 3);

    dict.add('y', 4);
    assert(dict['y'] == 4);
    assert(dict.contains('y'));
    auto it = dict.begin();
    assert(*it == 4);
    ++it;
    assert(*it == 3);


    std::cout << "Test dictionar: OK\n";
}

void test_user() {
    User user1("Ion", 19, "creangaion@gmail.com");

    assert(user1.getUsername() == "Ion");    
    assert(user1.getAge() == 19);
    assert(user1.getEmail() == "creangaion@gmail.com");
    assert(user1.getFriends().empty());

    User user2("Maria", 20, "maria@yahoo.com");

    assert(user2.getUsername() == "Maria");
    assert(user2.getAge() == 20);
    assert(user2.getEmail() == "maria@yahoo.com");
    assert(user2.getFriends().empty());

    user1.addFriend(user2);
    user2.addFriend(user1);
    
    auto user1friends = user1.getFriends();
    assert(user1friends.size() == 1);

    auto user2friends = user2.getFriends();
    assert(user2friends.size() == 1);

    user1.sendMessage(user2, "hello");
    assert(user1.getMessages().size() == 1);
    assert(user2.getMessages().size() == 1);

    auto message1 = user1.getMessages()[0];
    assert(message1.sender == &user1);
    assert(message1.receiver == &user2);
    assert(message1.content == "hello");

    auto message2 = user2.getMessages()[0];
    assert(message2.sender == &user1);
    assert(message2.receiver == &user2);
    assert(message2.content == "hello");

    User user3("Mihai", 25, "mihai@gmail.com");
    User user4("Vasile", 17, "vasile@gmail.com");

    user3.sendMessage(user4, "vi la un lol?");
    assert(user3.getMessages().size() == 1);
    assert(user4.getMessages().size() == 1);

    std::cout << "Test utilizator: OK" << std::endl;
}

inline void test_service() {
    Service service;

    service.addUser("Ion", 19, "creangaion@gmail.com");
    assert(service.getUsers().size() == 1);
    
    service.addUser("Maria", 20, "maria@yahoo.com");
    assert(service.getUsers().size() == 2);

    List<User*> users = service.getUsers();

    assert(users[1]->getUsername() == "Ion");
    assert(users[1]->getAge() == 19);
    assert(users[1]->getEmail() == "creangaion@gmail.com");
    assert(users[1]->getFriends().empty());

    assert(users[0]->getUsername() == "Maria");
    assert(users[0]->getAge() == 20);
    assert(users[0]->getEmail() == "maria@yahoo.com");
    assert(users[0]->getFriends().empty());

    service.updateUser("Ion", "Creanga", 25, "business@amintiricopilarie.com");
    users = service.getUsers();

    assert(service.getUsers().size() == 2);
    assert(users[1]->getUsername() == "Creanga");
    assert(users[1]->getAge() == 25);
    assert(users[1]->getEmail() == "business@amintiricopilarie.com");
    assert(users[1]->getFriends().empty());

    // service.addFriendship("Creanga", "Maria");
    // users = service.getUsers();
    // assert(users[0]->getFriends().size() == 1);
    // assert(users[1]->getFriends().size() == 1);

    // service.sendMessage("Creanga", "Maria", "buna ce faci");
    // users  = service.getUsers();
    // assert(users[0]->getMessages().size() == 1);
    // assert(users[1]->getMessages().size() == 1);
    
    // Message message = users[0]->getMessages()[0];
    // users  = service.getUsers();
    // assert(message.sender == users[0]);
    // assert(message.receiver == users[1]);
    // assert(message.content == "buna ce faci");

    std::cout << "Test service: OK" << std::endl;
}
