cmake_minimum_required(VERSION 2.8.4)
project(Networks_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

    Constants/ProtocolConstants.h
    Constants/ProtocolConstants.cpp

    Models/Recipient.h
    Models/User.h
    Models/User.cpp
    Models/Group.h
    Models/Group.cpp)
add_executable(Networks_Client ${SOURCE_FILES})