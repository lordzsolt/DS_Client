#include "MessageReceiver.h"

MessageReceiver::MessageReceiver(std::string serverAddress, unsigned short port) {
    _listener = SocketListener(serverAddress, port);
}