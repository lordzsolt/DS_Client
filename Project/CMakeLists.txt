cmake_minimum_required(VERSION 2.8.4)
project(Networks_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

    Constants/ProtocolConstants.h
    Constants/ProtocolConstants.cpp

    Controllers/Session.h
    Controllers/Session.cpp

    Models/RecipientModels/Recipient.h
    Models/RecipientModels/User.h
    Models/RecipientModels/User.cpp
    Models/RecipientModels/Group.h
    Models/RecipientModels/Group.cpp

    Models/ErrorMessage.h
    Models/ErrorMessage.cpp
    )
add_executable(Networks_Client ${SOURCE_FILES})