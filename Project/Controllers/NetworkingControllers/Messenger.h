#pragma once

#include "MessageSender.h"
#include "SocketListener.h"

#include <unordered_set>

typedef void (*MessengerCallback)(bool success);

class Messenger {
public:
    Messenger() {}
    Messenger(std::string serverAddress, unsigned short port);

    void sendLogin(std::string username, std::string password, MessengerCallback callback) const;
    void sendSignup(std::string username, std::string password, MessengerCallback callback) const;
    void sendPrivateMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const;
    void sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const;

private:
    MessageSender _sender;
    SocketListener _listener;
};