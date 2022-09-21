cmake_minimum_required(VERSION 3.10)

project(anastasia_1_6)

add_executable(anastasia_1_6
    main.cpp
    Event.cpp
    EventService.cpp
    Message.cpp
    Network.cpp
    User.cpp
    UserService.cpp
    Friendship.cpp
    Interface.cpp
    EventSubscription.cpp
)
