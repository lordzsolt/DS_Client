#pragma once

#include <winsock2.h>
#include <string>

typedef void (*MessageSenderCallback)(std::string errorMessage);

class MessageSender {

public:

    MessageSender(std::string serverAddress, unsigned short port);

    void sendMessage(std::string message) throw();

private:
    SOCKET _socket;
};