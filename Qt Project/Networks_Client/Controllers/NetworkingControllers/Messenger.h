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

using MessengerCallback = std::function<void(std::shared_ptr<Message>)>;

class Messenger {
public:
    Messenger(std::string serverAddress, unsigned short port, MessengerCallback callback);

    virtual ~Messenger();

    void sendLogin(std::string username, std::string password, MessengerCallback callback) const;
    void sendSignup(std::string username, std::string password, MessengerCallback callback) const;
    void sendPrivateMessage(std::string message, int recipientId, MessengerCallback callback) const;
    void sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const;

private:
    MessageSender _sender;
    MessageReceiver _receiver;
    std::thread _receivingThread;
    mutable unsigned int _messageIndex = 1;

    /**
     * @brief _callbacksByIndex
     * Contains the callbacks provided, the callback provided in the constructor will always be at index 0
     */
    mutable std::unordered_map<unsigned int, MessengerCallback> _callbacksByIndex;

    Messenger(std::string serverAddress, unsigned short port, MessengerCallback callback, SOCKET socket);
    void sendMessage(Message* message, MessengerCallback callback) const;
    void messageReceived(std::shared_ptr<Message> message);
};
