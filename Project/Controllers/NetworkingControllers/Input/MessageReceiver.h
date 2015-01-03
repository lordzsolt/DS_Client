#include "SocketListener.h"

#include "../../../Models/MessageModels/Message.h"

#include <functional>

class MessageReceiver;
using MessageReceiverCallback = std::function<void(MessageReceiver receiver, Message& message)>;

class MessageReceiver {
public:
    MessageReceiver(std::string serverAddress, unsigned short port, MessageReceiverCallback callback);

private:
    SocketListener _listener;
};