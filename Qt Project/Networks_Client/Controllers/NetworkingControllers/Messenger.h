#pragma once

#include "Output/MessageSender.h"
#include "Input/MessageReceiver.h"

#include "../../Models/MessageModels/Message.h"

#include "../../Constants/ProtocolConstants.h"

#include <unordered_set>
#include <functional>
#include <unordered_map>
#include <thread>
#include <memory>

using MessengerCallback = std::function<void(bool success)>;

class Messenger {
public:
    Messenger(std::string serverAddress, unsigned short port);

    virtual ~Messenger();

    void sendLogin(std::string username, std::string password, MessengerCallback callback) const;
    void sendSignup(std::string username, std::string password, MessengerCallback callback) const;
    void sendPrivateMessage(std::string message, int recipientId, MessengerCallback callback) const;
    void sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const;

    void registerCallbackForMessageType(MessageType type, MessengerCallback callback);
    void unregisterCallbackForMessageType(MessageType type, MessengerCallback callback);

private:
    MessageSender _sender;
    MessageReceiver _receiver;
    std::thread _receivingThread;
    mutable unsigned int _messageIndex = 0;

    mutable std::unordered_map<unsigned int, MessengerCallback> _callbacksByIndex;
    mutable std::unordered_map<MessageType, std::vector<MessengerCallback>> _callbacksByType;

    Messenger(std::string serverAddress, unsigned short port, SOCKET socket);
    void sendMessage(Message* message, MessengerCallback callback) const;
    void messageReceived(std::shared_ptr<Message> message);
};
