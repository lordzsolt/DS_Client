#include "Messenger.h"
#include "../../Factories/SocketFactory.h"

#include "../../Constants/ProtocolConstants.h"
#include "../../Models/MessageModels/Message.h"
#include "../../Models/MessageModels/Messages/LoginMessage.h"
#include "../../Models/MessageModels/Messages/RegisterMessage.h"
#include "../../Models/MessageModels/Messages/PrivateMessage.h"

using namespace std;
using namespace std::placeholders;

Messenger::Messenger(std::string serverAddress, unsigned short port)
        : Messenger(serverAddress, port, SocketFactory::createSocket(serverAddress, port))
{
}

Messenger::Messenger(std::string serverAddress, unsigned short port, SOCKET socket)
        : _sender(socket),
        _receiver(socket, bind(&Messenger::messageReceived, this, _1)),
        _receivingThread(bind(&MessageReceiver::startReceiving, &_receiver))
{
}


Messenger::~Messenger() {
    _receiver.stopReceiving();
    _receivingThread.join();
}



void Messenger::sendLogin(std::string username, std::string password, MessengerCallback callback) const {
    LoginMessage loginMessage(_messageIndex, MessageTag::New, username, password);
    sendMessage(&loginMessage, callback);
}


void Messenger::sendSignup(std::string username, std::string password, MessengerCallback callback) const {
    RegisterMessage registerMessage(_messageIndex, MessageTag::New, username, password);
    sendMessage(&registerMessage, callback);
}



void Messenger::sendPrivateMessage(std::string message, int recipientId, MessengerCallback callback) const {
    PrivateMessage privateMessage(_messageIndex, MessageTag::New, recipientId, message);
    sendMessage(&privateMessage, callback);
}


void Messenger::sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const {
    //TODO: Update GroupMessage and implement group message sending
}


void Messenger::sendMessage(Message* message, MessengerCallback callback) const {
    _callbacks.emplace(_messageIndex, callback);
    if (_messageIndex < kMaximumMessageIndex - 1) {
        _messageIndex++;
    }
    else {
        _messageIndex = 0;
    }
    //TODO: Add error handling
    _sender.sendMessage(message->serialize());
}


void Messenger::messageReceived(shared_ptr<Message> message) {

}
