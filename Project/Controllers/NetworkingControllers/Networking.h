#pragma once

#include "Messenger.h"

#include <string>
#include <unordered_set>
#include <functional>

using NetworkCallback = std::function<void(bool success)>;

class Networking {
public:

    Networking();

    void login(std::string username, std::string password, NetworkCallback callback) const;
    void signup(std::string username, std::string password, NetworkCallback callback) const;
    void privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const;
    void groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const;

private:
    Messenger _messenger;
};