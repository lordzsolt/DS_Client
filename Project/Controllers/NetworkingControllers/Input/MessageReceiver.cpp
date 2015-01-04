#include "MessageReceiver.h"

using namespace std;
using namespace std::placeholders;

MessageReceiver::MessageReceiver(SOCKET socket, MessageReceiverCallback callback)
        : _listener(socket, bind(&MessageReceiver::messageReceived, this, _1), Message::headerLength()),
          _callback(callback)
{
}

void MessageReceiver::startReceiving() {
    _listener.startListening();
}

void MessageReceiver::stopReceiving() {
    _listener.stopListening();
}


void MessageReceiver::messageReceived(string header, string message) {

}
