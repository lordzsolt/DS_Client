cmake_minimum_required(VERSION 2.8.4)
project(Networks_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

    Constants/ProtocolConstants.h
    Constants/ProtocolConstants.cpp

    Controllers/Session.cpp
    Controllers/Session.h
    Controllers/NetworkingControllers/Networking.h
    Controllers/NetworkingControllers/Networking.cpp
    Controllers/NetworkingControllers/Output/MessageSender.h
    Controllers/NetworkingControllers/Output/MessageSender.cpp
    Controllers/NetworkingControllers/Messenger.h
    Controllers/NetworkingControllers/Messenger.cpp
    Controllers/NetworkingControllers/Input/MessageReceiver.h
    Controllers/NetworkingControllers/Input/MessageReceiver.cpp
    Controllers/NetworkingControllers/Input/SocketListener.h
    Controllers/NetworkingControllers/Input/SocketListener.cpp
    Controllers/ThreadControllers/SynchronizedQueue.h
    Controllers/ThreadControllers/SynchronizedQueue.cpp

    Models/RecipientModels/Recipient.h
    Models/RecipientModels/User.h
    Models/RecipientModels/User.cpp
    Models/RecipientModels/Group.h
    Models/RecipientModels/Group.cpp

    Models/MessageModels/Message.h
    Models/MessageModels/Message.cpp
    Models/MessageModels/Messages/GroupMessage.h
    Models/MessageModels/Messages/GroupMessage.cpp
    Models/MessageModels/Messages/LoginMessage.h
    Models/MessageModels/Messages/LoginMessage.cpp
    Models/MessageModels/Messages/PrivateMessage.h
    Models/MessageModels/Messages/PrivateMessage.cpp
    Models/MessageModels/Messages/RegisterMessage.h
    Models/MessageModels/Messages/RegisterMessage.cpp

    Models/ErrorMessage.h
    Models/ErrorMessage.cpp
    )
add_executable(Networks_Client ${SOURCE_FILES})

if(WIN32)
  target_link_libraries(Networks_Client wsock32 ws2_32)
endif()