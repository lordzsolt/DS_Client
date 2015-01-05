#pragma once

#include "Messenger.h"

#include <string>
#include <unordered_set>
#include <functional>

using NetworkingCallback = std::function<void(bool success)>;

class Networking {
public:

    Networking();

    void login(std::string username, std::string password, NetworkingCallback callback);
    void signup(std::string username, std::string password, NetworkingCallback callback);
    void privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback);
    void groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback);

private:
    Networking(nullptr_t);
    nullptr_t initializeWSA();
    Messenger _messenger;
};