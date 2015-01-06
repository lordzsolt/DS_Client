#include "MessageReceiver.h"

#include "../../../Models/MessageModels/Deserializer/MessageDeserializer.h"

using namespace std;
using namespace std::placeholders;

MessageReceiver::MessageReceiver(SOCKET socket, MessageReceiverCallback callback)
        : _listener(socket, bind(&MessageReceiver::messageReceived, this, _1, _2), Message::headerLength()),
          _callback(callback)
{
}

void MessageReceiver::startReceiving() {
    _listener.startListening();
}

void MessageReceiver::stopReceiving() {
    _listener.stopListening();
}


void MessageReceiver::messageReceived(string header, string body) {
    shared_ptr<Message> message = MessageDeserializer::deserializeMessage(header, body);
    cerr << "Received message with body: " << body << endl;
    _callback(message);
}
