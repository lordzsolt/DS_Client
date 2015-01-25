#pragma once

#include "Messenger.h"
#include "../../Models/MessageModels/Message.h"

#include <string>
#include <unordered_set>
#include <functional>

using NotificationCallback = std::function<void(std::shared_ptr<Message> message)>;
using NetworkingCallback = std::function<void(bool success)>;

class Networking {
public:

    Networking(NotificationCallback callback);

    void login(std::string username, std::string password, NetworkingCallback callback) const;
    void signup(std::string username, std::string password, NetworkingCallback callback) const;
    void privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const;
    void groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const;

private:
    Networking(NotificationCallback callback, nullptr_t t);
    nullptr_t initializeWSA();
    Messenger _messenger;
};
