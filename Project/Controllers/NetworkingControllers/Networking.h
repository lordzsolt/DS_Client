#pragma once

#include "MessageSender.h"
#include "SocketListener.h"

#include <string>
#include <unordered_set>

typedef void (*NetworkCallback)(bool success);

class Networking {
public:

    Networking();

    void login(std::string username, std::string password, NetworkCallback callback) const;
    void signup(std::string username, std::string password, NetworkCallback callback) const;
    void sendPrivateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const;
    void sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const;

private:
    MessageSender _sender;
    SocketListener _listener;
};