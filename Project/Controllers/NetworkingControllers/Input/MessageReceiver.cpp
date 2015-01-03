#include "MessageReceiver.h"

MessageReceiver::MessageReceiver(std::string serverAddress, unsigned short port, MessageReceiverCallback callback)
        : _listener(serverAddress, port)
{
}