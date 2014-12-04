cmake_minimum_required(VERSION 2.8.4)
project(Networks_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

    Constants/ProtocolConstants.cpp
    Constants/ProtocolConstants.h

    Controllers/Session.cpp
    Controllers/Session.h

    Models/RecipientModels/Recipient.h
    Models/RecipientModels/User.cpp
    Models/RecipientModels/User.h
    Models/RecipientModels/Group.cpp
    Models/RecipientModels/Group.h

    Models/MessageModels/Message.cpp
    Models/MessageModels/Message.h
    Models/MessageModels/Messages/GroupMessage.cpp
    Models/MessageModels/Messages/GroupMessage.h
    Models/MessageModels/Messages/LoginMessage.cpp
    Models/MessageModels/Messages/LoginMessage.h
    Models/MessageModels/Messages/PrivateMessage.cpp
    Models/MessageModels/Messages/PrivateMessage.h
    Models/MessageModels/Messages/RegisterMessage.cpp
    Models/MessageModels/Messages/RegisterMessage.h

    Models/ErrorMessage.h
    Models/ErrorMessage.cpp
    )
add_executable(Networks_Client ${SOURCE_FILES})