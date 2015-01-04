#include "SocketListener.h"

#include "../../../Models/MessageModels/Message.h"

#include <functional>

class MessageReceiver;
using MessageReceiverCallback = std::function<void(MessageReceiver receiver, Message& message)>;

class MessageReceiver {
public:
    MessageReceiver(SOCKET socket, MessageReceiverCallback callback);

    void startReceiving();
    void stopReceiving();
private:
    SocketListener _listener;
    MessageReceiverCallback _callback;

    void messageReceived(std::string header, std::string message);
};