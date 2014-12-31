#include "Messenger.h"

Messenger::Messenger(std::string serverAddress, unsigned short port) {
    _sender = MessageSender(serverAddress, port);
    _listener = SocketListener(serverAddress, port);
}


void Messenger::sendLogin(std::string username, std::string password, MessengerCallback callback) const {

}


void Messenger::sendSignup(std::string username, std::string password, MessengerCallback callback) const {

}


void Messenger::sendPrivateMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const {

}


void Messenger::sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const {

}
