#pragma once

#include "Output/MessageSender.h"
#include "Input/MessageReceiver.h"

#include "../../Models/MessageModels/Message.h"

#include <unordered_set>
#include <functional>
#include <unordered_map>

using MessengerCallback = std::function<void(bool success)>;

class Messenger {
public:
    Messenger() {}
    Messenger(std::string serverAddress, unsigned short port);

    void sendLogin(std::string username, std::string password, MessengerCallback callback);
    void sendSignup(std::string username, std::string password, MessengerCallback callback);
    void sendPrivateMessage(std::string message, int recipientId, MessengerCallback callback);
    void sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback);

private:
    MessageSender _sender;
    MessageReceiver _receiver;
    unsigned int _messageIndex = 0;
    std::unordered_map<unsigned int, MessengerCallback> _callbacks;

    void sendMessage(Message message, MessengerCallback callback);
};