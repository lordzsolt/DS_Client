#pragma once

#include "SocketListener.h"
#include "../../Models/ErrorMessage.h"

#include <string>
#include <unordered_set>
#include <vector>

typedef void (*NetworkCallback)(bool success, ErrorMessage &error);

class Networking {
public:
    void login(std::string username, std::string password, NetworkCallback callback) const;
    void signup(std::string username, std::string password, NetworkCallback callback) const;
    void sendMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const;

private:
    std::vector<SocketListener> _listeners;
};