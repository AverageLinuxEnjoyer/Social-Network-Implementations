#include "../include/Interface.h"

Interface::Interface()
{
    
}

Interface::~Interface()
{
    
}

void Interface::start() {
    int option;
    do {
        cout << "1. Get user" << endl;
        cout << "2. Get event" << endl;
        cout << "3. Add user" << endl;
        cout << "4. Add event" << endl;
        cout << "5. Add message" << endl;
        cout << "6. Add friendship" << endl;
        cout << "7. Remove user" << endl;
        cout << "8. Remove event" << endl;
        cout << "9. Remove message" << endl;
        cout << "10. Remove friendship" << endl;
        cout << "11. Modify user" << endl;
        cout << "12. Modify event" << endl;
        cout << "13. Get all users" << endl;
        cout << "14. Get all events" << endl;
        cout << "15. Get all messages" << endl;
        cout << "16. Get messages of user" << endl;
        cout << "17. Get messages between users" << endl;
        cout << "18. Get all friendships" << endl;
        cout << "19. Get friends of user" << endl;
        cout << "20. Subscribe to event" << endl;
        cout << "21. Unsubscribe from event" << endl;
        cout << "22. Show subscribed users to event" << endl;
        cout << "23. Show user subscriptions" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case 1:
                getUser();
                break;
            case 2:
                getEvent();
                break;
            case 3:
                addUser();
                break;
            case 4:
                addEvent();
                break;
            case 5:
                addMessage();
                break;
            case 6:
                addFriendship();
                break;
            case 7:
                removeUser();
                break;
            case 8:
                removeEvent();
                break;
            case 9:
                removeMessage();
                break;
            case 10:
                removeFriendship();
                break;
            case 11:
                modifyUser();
                break;
            case 12:
                modifyEvent();
                break;
            case 13:
                getAllUsers();
                break;
            case 14:
                getAllEvents();
                break;
            case 15:
                getAllMessages();
                break;
            case 16:
                getMessagesOfUser();
                break;
            case 17:
                getMessagesBetweenUsers();
                break;
            case 18:
                getAllFriendships();
                break;
            case 19:
                getFriendsOfUser();
                break;
            case 20:
                subscribe();
                break;
            case 21:
                unsubscribe();
                break;
            case 22:
                showEventSubscriptions();
                break;
            case 23:
                showUserSubscriptions();
                break;
            case 0:
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    } while (option != 0);
}

void Interface::getUser() {
    int id;
    cout << "Enter user id: ";
    cin >> id;
    cout << endl;
    User user = network.getUser(id);
    if (user.getId() == -1) {
        cout << "User not found" << endl;
    } else {
        cout << "Name: " << user.getName() << endl;
        cout << "Surname: " << user.getSurname() << endl;
        cout << "Email: " << user.getEmail() << endl;
        cout << "Password: " << user.getPassword() << endl;
        cout << "Id: " << user.getId() << endl;
    }

    cout << endl;
}


void Interface::getEvent() {
    int id;
    cout << "Enter event id: ";
    cin >> id;
    cout << endl;
    Event event = network.getEvent(id);
    if (event.getId() == -1) {
        cout << "Event not found" << endl;
    } else {
        cout << "Name: " << event.getName() << endl;
        cout << "Date: " << event.getDate() << endl;
        cout << "Description: " << event.getDescription() << endl;
        cout << "Id: " << event.getId() << endl;
    }

    cout << endl;
}

void Interface::addUser() {
    int id;
    string name, surname, email, password;
    cout << "Enter user id: ";
    cin >> id;
    cout << "Enter user name: ";
    cin >> name;
    cout << "Enter user surname: ";
    cin >> surname;
    cout << "Enter user email: ";
    cin >> email;
    cout << "Enter user password: ";
    cin >> password;
    cout << endl;

    try {
        network.addUser(User(id ,name, surname, email, password));
        cout << "User added" << endl;
    } catch (std::string error) {
        cout << error << endl;
    }

    cout << endl;
}

void Interface::addEvent() {
    int id;
    string name, description, location, date, time;
    cout << "Enter event id: ";
    cin >> id;
    cout << "Enter event name: ";
    cin >> name;
    cout << "Enter event description: ";
    cin >> description;
    cout << "Enter event location: ";
    cin >> location;
    cout << "Enter event date: ";
    cin >> date;
    cout << "Enter event time: ";
    cin >> time;
    cout << endl;

    try {
        network.addEvent(Event(id, name, description, location, date, time));
        cout << "Event added" << endl;
    } catch (std::string error) {
        cout << error << endl;
    }
    
    cout << endl;
}


void Interface::addMessage() {
    int senderId, receiverId;
    string message;

    cout << "Enter sender id: ";
    cin >> senderId;

    cout << "Enter receiver id: ";
    cin >> receiverId;

    cout << "Enter message: ";
    cin >> message;

    if (network.getUser(senderId).getId() == -1) {
        cout << "Sender not found" << endl;
    } else if (network.getUser(receiverId).getId() == -1) {
        cout << "Receiver not found" << endl;
    } else {
        network.addMessage(Message( network.getMessages().size() + 1,
            senderId, receiverId, message));
        cout << "Message added" << endl;
    }

    cout << endl;
}


void Interface::addFriendship() {
    int userId1, userId2;

    cout << "Enter first user id: ";
    cin >> userId1;

    cout << "Enter second user id: ";
    cin >> userId2;

    if (network.getUser(userId1).getId() == -1) {
        cout << "First user not found" << endl;
    } else if (network.getUser(userId2).getId() == -1) {
        cout << "Second user not found" << endl;
    } else {
        network.addFriendship(Friendship( userId1, userId2));
        cout << "Friendship added" << endl;
    }

    cout << endl;
}

void Interface::removeUser() {
    int id;
    cout << "Enter user id: ";
    cin >> id;
    cout << endl;

    if (network.getUser(id).getId() == -1) {
        cout << "User not found" << endl;
    } else {
        network.removeUser(id);
        cout << "User removed" << endl;
    }

    cout << endl;
}

void Interface::removeEvent() {
    int id;
    cout << "Enter event id: ";
    cin >> id;
    cout << endl;

    if (network.getEvent(id).getId() == -1) {
        cout << "Event not found" << endl;
    } else {
        network.removeEvent(id);
        cout << "Event removed" << endl;
    }

    cout << endl;
}

void Interface::removeMessage() {
    int id;
    cout << "Enter message id: ";
    cin >> id;
    cout << endl;

    List<Message> messages = network.getMessages();

    for (int i = 0; i < messages.size(); i++) {
        if (messages[i].getId() == id) {
            network.removeMessage(id);
            cout << "Message removed" << endl;
            break;
        }
    }

    cout << endl;
}


void Interface::removeFriendship() {
    int userId1, userId2;

    cout << "Enter first user id: ";
    cin >> userId1;

    cout << "Enter second user id: ";
    cin >> userId2;

    if (network.getUser(userId1).getId() == -1) {
        cout << "First user not found" << endl;
    } else if (network.getUser(userId2).getId() == -1) {
        cout << "Second user not found" << endl;
    } else {
        network.removeFriendship(userId1, userId2);
        cout << "Friendship removed" << endl;
    }

    cout << endl;
}

void Interface::modifyUser() {
    int id;
    string name, surname, email, password;
    cout << "Enter user id: ";
    cin >> id;
    cout << "Enter new user name: ";
    cin >> name;
    cout << "Enter new user surname: ";
    cin >> surname;
    cout << "Enter new user email: ";
    cin >> email;
    cout << "Enter new user password: ";
    cin >> password;
    cout << endl;

    if (network.getUser(id).getId() == -1) {
        cout << "User not found" << endl;
    } else {
        network.modifyUser(id, User(id, name, surname, email, password));
        cout << "User modified" << endl;
    }

    cout << endl;
}

void Interface::modifyEvent() {
    int id;
    string name, description, location, date, time;
    cout << "Enter event id: ";
    cin >> id;
    cout << "Enter new event name: ";
    cin >> name;
    cout << "Enter new event description: ";
    cin >> description;
    cout << "Enter new event location: ";
    cin >> location;
    cout << "Enter new event date: ";
    cin >> date;
    cout << "Enter new event time: ";
    cin >> time;
    cout << endl;

    if (network.getEvent(id).getId() == -1) {
        cout << "Event not found" << endl;
    } else {
        network.modifyEvent(id, Event(id, name, description, location, date, time));
        cout << "Event modified" << endl;
    }

    cout << endl;
}

void Interface::getAllUsers() {
    List<User> users = network.getUsers();
    if (users.size() == 0) {
        cout << "No users found" << endl;
    } else {
        for (int i = 0; i < users.size(); i++) {
            cout << "Name: " << users[i].getName() << endl;
            cout << "Surname: " << users[i].getSurname() << endl;
            cout << "Email: " << users[i].getEmail() << endl;
            cout << "Password: " << users[i].getPassword() << endl;
            cout << "Id: " << users[i].getId() << endl << endl;
        }
    }

    cout << endl;
}


void Interface::getAllEvents() {
    List<Event> events = network.getEvents();
    if (events.size() == 0) {
        cout << "No events found" << endl;
    } else {
        for (int i = 0; i < events.size(); i++) {
            cout << "Name: " << events[i].getName() << endl;
            cout << "Description: " << events[i].getDescription() << endl;
            cout << "Location: " << events[i].getLocation() << endl;
            cout << "Date: " << events[i].getDate() << endl;
            cout << "Time: " << events[i].getTime() << endl;
            cout << "Id: " << events[i].getId() << endl << endl;
        }
    }

    cout << endl;
}


void Interface::getAllMessages() {
    List<Message> messages = network.getMessages();
    if (messages.size() == 0) {
        cout << "No messages found" << endl;
    } else {
        for (int i = 0; i < messages.size(); i++) {
            User sender = network.getUser(messages[i].getUser1Id());
            User receiver = network.getUser(messages[i].getUser2Id());
            std::string message = messages[i].getMessage();
            cout << "[id:" << messages[i].getId() << "][" << sender.getName() << "-" << receiver.getName() << "]: " << message << endl;
        }
    }

    cout << endl;
}

void Interface::getMessagesOfUser() {
    int userId;
    cout << "Enter user id: ";
    cin >> userId;
    cout << endl;

    List<Message> messages = network.getMessages(userId);

    if (messages.size() == 0) {
        cout << "No messages found" << endl;
    } else {
        for (int i = 0; i < messages.size(); i++) {
            User sender = network.getUser(messages[i].getUser1Id());
            User receiver = network.getUser(messages[i].getUser2Id());
            std::string message = messages[i].getMessage();
            cout << "[id:" << messages[i].getId() << "][" << sender.getName() << "-" << receiver.getName() << "]: " << message << endl;
        }
    }

    cout << endl;
}

void Interface::getMessagesBetweenUsers() {
    int userId1, userId2;
    cout << "Enter first user id: ";
    cin >> userId1;

    cout << "Enter second user id: ";
    cin >> userId2;
    cout << endl;

    List<Message> messages = network.getMessages(userId1, userId2);

    if (messages.size() == 0) {
        cout << "No messages found" << endl;
    } else {
        for (int i = 0; i < messages.size(); i++) {
            User sender = network.getUser(messages[i].getUser1Id());
            User receiver = network.getUser(messages[i].getUser2Id());
            std::string message = messages[i].getMessage();
            cout << "[id:" << messages[i].getId() << "][" << sender.getName() << "-" << receiver.getName() << "]: " << message << endl;
        }
    }

    cout << endl;
}


void Interface::getAllFriendships() {
    List<Friendship> friendships = network.getFriendships();
    if (friendships.size() == 0) {
        cout << "No friendships found" << endl;
    } else {
        for (int i = 0; i < friendships.size(); i++) {
            User user1 = network.getUser(friendships[i].getUser1Id());
            User user2 = network.getUser(friendships[i].getUser2Id());
            cout << "[" << user1.getName() << "-" << user2.getName() << "]" << endl;
        }
    }

    cout << endl;
}

void Interface::getFriendsOfUser() {
    int userId;
    cout << "Enter user id: ";
    cin >> userId;
    cout << endl;

    List<Friendship> friends = network.getFriends(userId);

    if (friends.size() == 0) {
        cout << "No friendships found" << endl;
    } else {
        for (int i = 0; i < friends.size(); i++) {
            User user1 = network.getUser(friends[i].getUser1Id());
            User user2 = network.getUser(friends[i].getUser2Id());
            cout << "[" << user1.getName() << "-" << user2.getName() << "]" << endl;
        }
    }

    cout << endl;
}

void Interface::subscribe() {
    int user_id, event_id;
    cout << "Enter user id: ";
    cin >> user_id;

    cout << "Enter event id: ";
    cin >> event_id;
    cout << endl;

    try {
        network.subscribe(user_id, event_id);
        cout << "Subscribed" << endl;
    } catch (std::string msg) {
        cout << msg << endl;
    }

    cout << endl;
}

void Interface::unsubscribe() {
    int user_id, event_id;
    cout << "Enter user id: ";
    cin >> user_id;

    cout << "Enter event id: ";
    cin >> event_id;
    cout << endl;

    try {
        network.unsubscribe(user_id, event_id);
        cout << "Unsubscribed" << endl;
    } catch (std::string msg) {
        cout << msg << endl;
    }

    cout << endl;
}

void Interface::showEventSubscriptions() {
    int event_id;
    cout << "Enter event id: ";
    cin >> event_id;
    cout << endl;

    Event event = network.getEvent(event_id);

    if (event.getId() == -1) {
        cout << "Event not found" << endl;
    } else {
        List<User> subscriptions = network.getSubscribers(event_id);
        if (subscriptions.size() == 0) {
            cout << "No subscriptions found" << endl;
        } else {
            for (int i = 0; i < subscriptions.size(); i++) {
                cout << subscriptions[i].getName() << endl;
            }
        }
    }
}

void Interface::showUserSubscriptions() {
    int user_id;
    cout << "Enter user id: ";
    cin >> user_id;
    cout << endl;

    User user = network.getUser(user_id);

    if (user.getId() == -1) {
        cout << "User not found" << endl;
    } else {
        List<Event> subscriptions = network.getSubscriptions(user_id);
        if (subscriptions.size() == 0) {
            cout << "No subscriptions found" << endl;
        } else {
            for (int i = 0; i < subscriptions.size(); i++) {
                cout << subscriptions[i].getName() << endl;
            }
        }
    }
}

