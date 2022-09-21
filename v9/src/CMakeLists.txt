cmake_minimum_required(VERSION 3.10)

project(paul)

add_executable(paul
    main.cpp
    Event.cpp
    User.cpp
    UserService.cpp
    EventService.cpp
    UI.cpp
)
